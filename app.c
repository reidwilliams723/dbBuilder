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
#include "serialProtocol.h"
#include <stdbool.h>

/* Interval for sending notifications */
#define APP_TASK_INTERVAL 500 //ms

/* Print boot message */
static void bootMessage(struct gecko_msg_system_boot_evt_t *bootevt);


/* Flag for indicating DFU Reset must be performed */
static uint8_t boot_to_dfu = 0;


/* Current number of connections */
uint8_t active_connections_num;


/* Values from MCU */
uint32_t bins[20]; // Bins buffer from MCU
uint32_t strokes = 0x0; // Stroke value from MCU
uint32_t runTime = 0; // Run time value from MCU
uint32_t rawValue; // Raw PSI value from MCU
uint32_t scaledValue; // Scaled PSI value from MCU
uint8_t accelerationx; // Accelerometer X value from MCU
uint8_t accelerationy; // Accelerometer Y value from MCU
uint8_t accelerationz; // Accelerometer Z value from MCU


/* Buffers/Values for BLE Characteristic 'User' Types */
uint32_t psiMessage[5]; // Holds the RawZero, RawScale, UnitsScale, PSI Raw Value, and Scaled PSI Value
uint32_t Bins[5]; // Aggregates and divides bins[20] into 5 values
uint32_t AccelerometerData[3]; // Holds the X,Y, and Z values
char controlInput; // Byte for control input. 0x01 = Reset, 0x02 = Zero Out
char mcuControlOTA;
uint32_t packetIncrement = 0;
uint32_t mcuControlData[5];



/* Simulating Variables */
bool simulate = false; // Boolean for either simulating data or reading data from MCU
uint32_t timer = 0;
uint32_t increment = 0;


/* Initialize Serial Port struct */
SerialProto_t serialPort;


void unPackData(uint8_t *buffer) {
	uint32_t index = 0;
	memcpy(&strokes, buffer+index,sizeof(strokes));
	index += sizeof(strokes);

	memcpy(&runTime, buffer+index,sizeof(runTime));
	index += sizeof(runTime);

	memcpy(bins, buffer+index,sizeof(bins));
	index += sizeof(bins);

	memcpy(&rawValue, buffer+index,sizeof(rawValue));
	index += sizeof(rawValue);

	memcpy(&scaledValue, buffer+index,sizeof(scaledValue));
	index += sizeof(scaledValue);

	memcpy(accelerationx, buffer+index,sizeof(accelerationx));
	index += sizeof(bins);

	memcpy(&accelerationy, buffer+index,sizeof(accelerationy));
	index += sizeof(rawValue);

	memcpy(&accelerationz, buffer+index,sizeof(accelerationz));
	index += sizeof(scaledValue);

	psiMessage[4] = scaledValue;
	psiMessage[3] = rawValue;

	AccelerometerData[0] = accelerationx;
	AccelerometerData[1] = accelerationy;
	AccelerometerData[2] = accelerationz;

	Bins[0] = bins[0] +  bins[1] +  bins[2] +  bins[3];
	Bins[1] = bins[4] + bins[5] +  bins[6] +  bins[7];
	Bins[2] = bins[8] + bins[9] +  bins[10] +  bins[11];
	Bins[3] = bins[12] + bins[13] + bins[14] + bins[15];
	Bins[4] = bins[16] +  bins[17] +  bins[18] +  bins[19];

}

void simulation(){
	increment++;
	if (increment > 100000)
		increment = 0;

	Bins[0] = increment;
	Bins[1] = increment+100;
	Bins[2] = increment+500;
	Bins[3] = increment+600;
	Bins[4] = 0;

	strokes = increment;
	runTime = increment - 1;

	rawValue = 4;
	scaledValue = 18234;

	psiMessage[3] = rawValue;
	psiMessage[4] = scaledValue;
}
void sendNotifications(){
	if (simulate)
		simulation();

	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Strokes, sizeof(strokes), (uint8 *)&strokes);
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Run_hours, sizeof(runTime), (uint8 *)&runTime);
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_PSI, sizeof(psiMessage), (uint8 *)&psiMessage);
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Bins, sizeof(Bins), (uint8 *)&Bins);
	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_Accelerometer, sizeof(AccelerometerData), (uint8 *)&AccelerometerData);
}
/* Main application */
void appMain(gecko_configuration_t *pconfig)
{

#if DISABLE_SLEEP > 0
  pconfig->sleep.flags = 0;
#endif

/* Initialize Serial Port */
 serialPort.txState = 0;
 serialPort.rxState = 0;
 serialPort.usart = USART0;
 serialPort.txCount = 0;
 serialPort.sentCount = 0;

 /* Initialize PSI Scaling if simulating */
 if(simulate)
 {
	 psiMessage[0] = 4;
	 psiMessage[1] = 20;
	 psiMessage[2] = 20000;
	 psiMessage[3] = rawValue;
	 psiMessage[4] = scaledValue;
 }

  /* Initialize stack */
  gecko_init(pconfig);

  while (1) {

    /* Event pointer for handling events */
    struct gecko_cmd_packet* evt;

    /* Read serial port when simulation is not taking place */
    if(!simulate)
    {
      processSerial(&serialPort);

	  if (serialPort.rxDone)
	  {
		serialPort.rxDone = 0;
		unPackData(serialPort.rxData);
		serialPort.rxData[0] = serialPort.rxData[0];
	  }
    }

    evt = gecko_peek_event();

    /* Handle events */
    switch (BGLIB_MSG_ID(evt->header)) {
      /* This boot event is generated when the system boots up after reset.
       * Do not call any stack commands before receiving the boot event.
       * Here the system is set to start advertising immediately after boot procedure. */
      case gecko_evt_system_boot_id:

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

        if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_control) {

          /* Set flag to enter to OTA mode */
          boot_to_dfu = 1;
          /* Send response to Write Request */
          gecko_cmd_gatt_server_send_user_write_response(
            evt->data.evt_gatt_server_user_write_request.connection,
            gattdb_ota_control,
            bg_err_success);

          /* Close connection to enter to DFU OTA mode */
          gecko_cmd_le_connection_close(evt->data.evt_gatt_server_user_write_request.connection);
        }
        if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_mcu_control) {
                    memcpy(&mcuControlOTA + evt->data.evt_gatt_server_user_write_request.offset,
                    		evt->data.evt_gatt_server_user_write_request.value.data,
							evt->data.evt_gatt_server_user_write_request.value.len);

                    gecko_cmd_gatt_server_send_user_write_response(
                    		evt->data.evt_gatt_server_user_write_request.connection,
                    		evt->data.evt_gatt_server_user_write_request.characteristic,
							bg_err_success);
                    packetIncrement = 0;
                }
        if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_ota_mcu_data) {
        	memcpy(mcuControlData + evt->data.evt_gatt_server_user_write_request.offset,
					evt->data.evt_gatt_server_user_write_request.value.data,
					evt->data.evt_gatt_server_user_write_request.value.len);

//        	packetBuffer[packetIncrement] = mcuControlData[0];

        	if (packetIncrement+1 != mcuControlData[0]){
        		uint8 tmp = 2;
        		gecko_cmd_gatt_server_send_characteristic_notification(evt->data.evt_gatt_server_user_write_request.connection,
        				gattdb_ota_mcu_control, sizeof(mcuControlOTA), (uint8 *)&tmp);

        	}
        	else
        	{
				packetIncrement++;

				if (packetIncrement == 130000){
					uint8 tmp = 1;
					gecko_cmd_gatt_server_send_characteristic_notification(evt->data.evt_gatt_server_user_write_request.connection,
							gattdb_ota_mcu_control, sizeof(mcuControlOTA), (uint8 *)&tmp);
					packetIncrement = 0;
				}
        	}

        }

        if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_PSI) {
			memcpy(psiMessage + evt->data.evt_gatt_server_user_write_request.offset,
					&evt->data.evt_gatt_server_user_write_request.value.data,
					evt->data.evt_gatt_server_user_write_request.value.len);

			gecko_cmd_gatt_server_send_user_write_response(
					evt->data.evt_gatt_server_user_write_request.connection,
					evt->data.evt_gatt_server_user_write_request.characteristic,
					bg_err_success);

         }

        if (evt->data.evt_gatt_server_user_write_request.characteristic == gattdb_Control_Input) {
        			memcpy(&controlInput + evt->data.evt_gatt_server_user_write_request.offset,
        					evt->data.evt_gatt_server_user_write_request.value.data,
        					evt->data.evt_gatt_server_user_write_request.value.len);

        			gecko_cmd_gatt_server_send_user_write_response(
        					evt->data.evt_gatt_server_user_write_request.connection,
        					evt->data.evt_gatt_server_user_write_request.characteristic,
        					bg_err_success);

        			// If controlInput = 01 (Data Reset)
        			if (controlInput == 1){
        				increment = 0;
        				controlInput = 0;
        				}
        			// If controlInput = 10 (Zero Raw value)
        			else if (controlInput == 2){
        				psiMessage[0] = psiMessage[3];
        				controlInput = 0;
        			}
        			else if (controlInput == 3){
        				if(simulate)
        					simulate = false;
        				else
        					simulate = true;
        			}
        }

        break;

        /* Add additional event handlers as your application requires */
             case gecko_evt_gatt_server_user_read_request_id:
           	  if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_Strokes) {
       			gecko_cmd_gatt_server_send_user_read_response(
       			  evt->data.evt_gatt_server_user_read_request.connection,
				  gattdb_Strokes,
       			  bg_err_success,
				  sizeof(strokes),
				  (uint8 *)&strokes);
           	  }

           	  else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_Run_hours) {
         			gecko_cmd_gatt_server_send_user_read_response(
         			  evt->data.evt_gatt_server_user_read_request.connection,
					  gattdb_Run_hours,
         			  bg_err_success,
         			  sizeof(runTime),
					  (uint8 *)&runTime);
             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_Bins) {
					gecko_cmd_gatt_server_send_user_read_response(
					  evt->data.evt_gatt_server_user_read_request.connection,
					  gattdb_Bins,
					  bg_err_success,
					  sizeof(Bins),
					  (uint8 *)&Bins);
				  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_PSI) {
				gecko_cmd_gatt_server_send_user_read_response(
				  evt->data.evt_gatt_server_user_read_request.connection,
				  gattdb_PSI,
				  bg_err_success,
				  sizeof(psiMessage),
				  (uint8 *)&psiMessage);
			  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_Accelerometer) {
				gecko_cmd_gatt_server_send_user_read_response(
				  evt->data.evt_gatt_server_user_read_request.connection,
				  gattdb_PSI,
				  bg_err_success,
				  sizeof(AccelerometerData),
				  (uint8 *)&AccelerometerData);
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
