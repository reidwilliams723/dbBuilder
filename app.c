/***************************************************************************//**
 * @file app.c
 * @brief Silicon Labs Empty Example Project
 *
 * This example demonstrates the bare minimum needed for a Blue Gecko C application
 * that allows Over-the-Air Device Firmware Upgrading (OTA DFU). The application
 * starts advertising after boot and restarts advertising after a connection is closed.
 *******************************************************************************
 * # License
 * <b>Copyright 2018 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/* Bluetooth stack headers */
#include "bg_types.h"
#include "native_gecko.h"
#include "gatt_db.h"

/* EM Lib headers */
#include "em_usart.h"

/* Other headers */
#include "app.h"
#include <stdbool.h>
#include "mcu_characteristics.h"
#include "serialProtocol.h"
#include "serialProtocolFunctions.h"
#include "flash_data.h"

#include "ioteqDB.h"
#include "ioteqDBFunctions.h"

/* Interval for sending notifications */
#define APP_TASK_INTERVAL 500 //ms

/* Print boot message */
static void bootMessage(struct gecko_msg_system_boot_evt_t *bootevt);

/* Flag for indicating DFU Reset must be performed */
static uint8_t boot_to_dfu = 0;

/* Current number of connections */
uint8_t active_connections_num;

/* Simulating Variables */
bool simulate = false; // Boolean for either simulating data or reading data from MCU
uint32_t increment = 0;
float test123[5] = {1.0,2.0,3.0,4.0, 5.0};
/* Initialize Serial Port struct */
SerialProto_t serialPort;
MCU_Characteristics_t mcuChars;

/* Simulation function */
void simulation(){
	increment++;
	if (increment > 100000)
		increment = 0;
	setValue(&CalculatedBins[0], (uint8_t*)&increment);
	increment+=100;
	setValue(&CalculatedBins[1], (uint8_t*)&increment);
	increment-=100;
	increment+=500;
	setValue(&CalculatedBins[2], (uint8_t*)&increment);
	increment-=500;
	increment+=600;
	setValue(&CalculatedBins[3], (uint8_t*)&increment);
	increment-=600;
	increment+=700;
	setValue(&CalculatedBins[4], (uint8_t*)&increment);
	increment-=700;

	setValue(Strokes, (uint8_t*)&increment);
	increment--;
	setValue(RunTime, (uint8_t*)&(increment));
	increment++;

	float psiValue = 15;
	float scaledValue = 18234;

	setValue(PSIRawValue, (uint8_t*)&psiValue);
	setValue(ScaledPSIValue, (uint8_t*)&scaledValue);

}
void sendNotifications(){
	if (simulate)
		simulation();

	uint32_t binsData[5];
	for (int i = 0; i < 5; i++){
		binsData[i] = *(uint32_t*)getValue(&CalculatedBins[i]);
	}
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Strokes, getTagSize(Strokes,0), (uint8 *)getValue(Strokes));
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Run_hours, getTagSize(RunTime,0), (uint8 *)getValue(RunTime));
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Suction_PSI, getTagSize(SuctionPressure,0), (uint8 *)getValue(SuctionPressure));
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Discharge_PSI, getTagSize(DischargePressure,0), (uint8 *)getValue(DischargePressure));
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Bins, sizeof(binsData), (uint8 *)binsData);
//	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Bins, getTagSize(Bins,0), (uint8 *)getValue(DischargePressure));
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Accelerometer, getTagSize(AccelerometerData,0), (uint8 *)getValue(AccelerometerData));
}
/* Main application */
void appMain(gecko_configuration_t *pconfig)
{

#if DISABLE_SLEEP > 0
  pconfig->sleep.flags = 0;
#endif

/* Initialize Serial Port */
 serialPort.mcu = &mcuChars;
 initSerialProtocol(&serialPort, USART0);

 /* Initialize database */
 initDB(0);


  /* Initialize stack */
  gecko_init(pconfig);

  while (1) {

    /* Event pointer for handling events */
    struct gecko_cmd_packet* evt;

    /* Read serial port when simulation is not taking place */
    if(!simulate)
    {
    	serialProtocolProcessMessages(&serialPort);
    }

    evt = gecko_peek_event();

    /* Handle events */
    switch (BGLIB_MSG_ID(evt->header)) {
      /* This boot event is generated when the system boots up after reset.
       * Do not call any stack commands before receiving the boot event.
       * Here the system is set to start advertising immediately after boot procedure. */
      case gecko_evt_system_boot_id:{

    	/* Get device name from flash */
    	char *savedVal = getBLEDeviceDataPtr();

    	/* By default, all flash has value 255, so if it doesn't equal...set the device name */
    	if (*savedVal != 255)
    		gecko_cmd_gatt_server_write_attribute_value(gattdb_device_name,0,strlen(savedVal),(uint8_t *)savedVal);


        bootMessage(&(evt->data.evt_system_boot));
        //printLog("boot event - starting advertising\r\n");

        /* Set advertising parameters. 100ms advertisement interval.
         * The first parameter is advertising set handle
         * The next two parameters are minimum and maximum advertising interval, both in
         * units of (milliseconds * 1.6).
         * The last two parameters are duration and maxevents left as default. */
        gecko_cmd_le_gap_set_advertise_timing(0, 160, 160, 0, 0);

        /* Start general advertising and enable connections. */
        gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);

        /* Start soft timer */
        gecko_cmd_hardware_set_soft_timer(32768*APP_TASK_INTERVAL/1000,0,0);

        break;
      }
      case gecko_evt_hardware_soft_timer_id:
    	  sendNotifications();
    	break;

      case gecko_evt_le_connection_opened_id:

    	/* Increment connection counter */
    	active_connections_num++;

        gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);

        break;

      case gecko_evt_le_connection_closed_id:

    	active_connections_num--;

        /* Check if need to boot to OTA DFU mode */
        if (boot_to_dfu)
          gecko_cmd_system_reset(2);
         else
        	gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);

        break;

      /* Events related to OTA upgrading
         ----------------------------------------------------------------------------- */

      /* Check if the user-type OTA Control Characteristic was written.
       * If ota_control was written, boot the device into Device Firmware Upgrade (DFU) mode. */
      case gecko_evt_gatt_server_user_write_request_id:
    	  switch (evt->data.evt_gatt_server_user_write_request.characteristic) {
    	  	  case gattdb_ota_control:
    	          /* Set flag to enter to OTA mode */
    	          boot_to_dfu = 1;
    	          /* Send response to Write Request */
    	          gecko_cmd_gatt_server_send_user_write_response(
    	            evt->data.evt_gatt_server_user_write_request.connection,
    	            gattdb_ota_control,
    	            bg_err_success);

    	          /* Close connection to enter to DFU OTA mode */
    	          gecko_cmd_le_connection_close(evt->data.evt_gatt_server_user_write_request.connection);
    	          break;

//    	  	  case gattdb_PSI:
//    	        	setValue(PSIData, (uint8_t*)&evt->data.evt_gatt_server_user_write_request.value.data);
//    				gecko_cmd_gatt_server_send_user_write_response(
//    						evt->data.evt_gatt_server_user_write_request.connection,
//    						evt->data.evt_gatt_server_user_write_request.characteristic,
//    						bg_err_success);
//    				txMsgSendPSIScaling(&serialPort);
//    				break;

    	  	  case gattdb_Erase_Firmware:
      			memcpy(&mcuChars.eraseFirmwarePacket + evt->data.evt_gatt_server_user_write_request.offset,
      					&evt->data.evt_gatt_server_user_write_request.value.data,
      					evt->data.evt_gatt_server_user_write_request.value.len);

      			gecko_cmd_gatt_server_send_user_write_response(
      					evt->data.evt_gatt_server_user_write_request.connection,
      					evt->data.evt_gatt_server_user_write_request.characteristic,
      					bg_err_success);

      			if (mcuChars.eraseFirmwarePacket == 3){
      				txMsgSendEraseFirmware(&serialPort);
      				mcuChars.eraseFirmwarePacket = 0;
      				mcuChars.packetCounter = 0;
      			}
      			break;

    	  	  case gattdb_device_name_mask: {
          		/* Clear the flash memory */
          		clearBLEDeviceId();

          		char tmp[evt->data.evt_gatt_server_attribute_value.value.len+1];
  				memcpy(tmp, evt->data.evt_gatt_server_attribute_value.value.data, evt->data.evt_gatt_server_attribute_value.value.len);
  				tmp[evt->data.evt_gatt_server_attribute_value.value.len] = 0; // add null terminator

          		/* Write incoming value to flash */
          		saveBLEDeviceId(tmp,
          				evt->data.evt_gatt_server_user_write_request.value.len+1);


          		/* Write new name to device name characteristic */
          		gecko_cmd_gatt_server_write_attribute_value(
          				gattdb_device_name,
          				0,
          				evt->data.evt_gatt_server_user_write_request.value.len,
          				(uint8_t *)evt->data.evt_gatt_server_user_write_request.value.data);

  				gecko_cmd_gatt_server_send_user_write_response(
  						evt->data.evt_gatt_server_user_write_request.connection,
  						evt->data.evt_gatt_server_user_write_request.characteristic,
  						bg_err_success);
  				break;
    	  	  }

    	  	  case gattdb_Firmware_Data:
					memcpy(&mcuChars.firmwareDataBuffer + evt->data.evt_gatt_server_user_write_request.offset,
							&evt->data.evt_gatt_server_user_write_request.value.data,
							evt->data.evt_gatt_server_user_write_request.value.len);


					if (((mcuChars.firmwareDataBuffer[1] << 8) | (mcuChars.firmwareDataBuffer[0] & 0xff)) == 33){
						mcuChars.packetCounter++;
					}
					txMsgSendFirmwareData(&serialPort);
					break;

    	  	  case gattdb_Control_Input:
					memcpy(&mcuChars.control + evt->data.evt_gatt_server_user_write_request.offset,
							evt->data.evt_gatt_server_user_write_request.value.data,
							evt->data.evt_gatt_server_user_write_request.value.len);

					gecko_cmd_gatt_server_send_user_write_response(
							evt->data.evt_gatt_server_user_write_request.connection,
							evt->data.evt_gatt_server_user_write_request.characteristic,
							bg_err_success);

					// If controlInput = 01 (Data Reset)
					if (mcuChars.control == 1){
						increment = 0;
						txMsgSendResetData(&serialPort);
						mcuChars.control = 0;
						}
					// If controlInput = 10 (Zero Raw value)
					else if (mcuChars.control == 2){
						if(simulate)
							setValue(RawZero, getValue(PSIRawValue));
						txMsgSendZeroRawValue(&serialPort);

						mcuChars.control = 0;
					}
					// If controlInput = 3, (Toggle LED)
					else if (mcuChars.control == 3){
						txMsgSendToggleLED(&serialPort);
						mcuChars.control = 0;

					}

						else if (mcuChars.control == 4){
							clearBLEDeviceId();
							gecko_cmd_system_reset(0);
						}
      			break;
    	  }

    	  break;

	/* Add additional event handlers as your application requires */
		 case gecko_evt_gatt_server_user_read_request_id:
			 switch (evt->data.evt_gatt_server_user_read_request.characteristic) {
				 case gattdb_Strokes:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Strokes,
						  bg_err_success,
						  getTagSize(Strokes, 0),
						  (uint8 *)getValue(Strokes));
						break;

				 case gattdb_Run_hours:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Run_hours,
						  bg_err_success,
						  getTagSize(RunTime, 0),
						  (uint8 *)getValue(RunTime));
						break;

				 case gattdb_Bins:{
						uint32_t binsData[5];
						for (int i = 0; i < 5; i++){
							binsData[i] = *(uint32_t*)getValue(&CalculatedBins[i]);
						}

						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Bins,
						  bg_err_success,
						  sizeof(binsData),
						  (uint8 *)binsData);
						break;
				 }
				 case gattdb_Suction_PSI:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Suction_PSI,
						  bg_err_success,
						  getTagSize(SuctionPressure, 0),
						  (uint8 *)getValue(SuctionPressure));
						break;
				 case gattdb_Discharge_PSI:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Discharge_PSI,
						  bg_err_success,
						  getTagSize(DischargePressure, 0),
						  (uint8 *)getValue(DischargePressure));
						break;

				 case gattdb_Accelerometer:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Accelerometer,
						  bg_err_success,
						  getTagSize(AccelerometerData, 0),
						  (uint8 *)getValue(AccelerometerData));
						break;
				 case gattdb_Temperature:{
						uint32_t temperaturedata[5];
						for (int i = 0; i < 5; i++){
							temperaturedata[i] = *(uint32_t*)getValue(&Temperature[i]);
						}
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Temperature,
						  bg_err_success,
						  sizeof(temperaturedata),
						  (uint8 *)temperaturedata);
						break;
				 }

				 case gattdb_location_and_speed:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_location_and_speed,
						  bg_err_success,
						  getTagSize(GPSData, 0),
						  (uint8 *)getValue(GPSData));
						break;

				 case gattdb_Firmware_Control:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Firmware_Control,
						  bg_err_success,
						  sizeof(mcuChars.packetCounter),
						  (uint8 *)&mcuChars.packetCounter);

						mcuChars.packetCounter = 0;
						break;

				 case gattdb_firmware_version:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_firmware_version,
						  bg_err_success,
						  getTagSize(SystemInformation, 0),
						  (uint8 *)getValue(SystemInformation));
						break;

				 case gattdb_device_name_mask: {
						/* Get device name from flash */
						char* deviceName = getBLEDeviceDataPtr();
						gecko_cmd_gatt_server_send_user_read_response(
							evt->data.evt_gatt_server_user_read_request.connection,
							gattdb_device_name_mask,
							bg_err_success,
							strlen(deviceName),
							(uint8 *)deviceName);
						break;
				 case gattdb_SSID:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_SSID,
						  bg_err_success,
						  getTagSize(SSID, 0),
						  (uint8 *)getValue(SSID));
						break;
				 case gattdb_Password:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_Password,
						  bg_err_success,
						  getTagSize(Password, 0),
						  (uint8 *)getValue(Password));
						break;
				 case gattdb_IP_Address:
						gecko_cmd_gatt_server_send_user_read_response(
						  evt->data.evt_gatt_server_user_read_request.connection,
						  gattdb_IP_Address,
						  bg_err_success,
						  getTagSize(IPAddress, 0),
						  (uint8 *)getValue(IPAddress));
						break;
				 }
			 }
		 break;

      default:
        break;
    }
  }
}

/* Print stack version and local Bluetooth address as boot message */
static void bootMessage(struct gecko_msg_system_boot_evt_t *bootevt)
{
#if DEBUG_LEVEL
  bd_addr local_addr;
  int i;

  //printLog("stack version: %u.%u.%u\r\n", bootevt->major, bootevt->minor, bootevt->patch);
  local_addr = gecko_cmd_system_get_bt_address()->address;

  //printLog("local BT device address: ");
  for (i = 0; i < 5; i++) {
    //printLog("%2.2x:", local_addr.addr[5 - i]);
  }
  //printLog("%2.2x\r\n", local_addr.addr[0]);
#endif
}
