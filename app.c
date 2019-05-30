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
#include "em_usart.h"

#include "app.h"

#include "serialProtocol.h"

/* Print boot message */
static void bootMessage(struct gecko_msg_system_boot_evt_t *bootevt);

/* Flag for indicating DFU Reset must be performed */
static uint8_t boot_to_dfu = 0;

/* Current number of connections */
uint8_t active_connections_num;

uint32_t bins[20];
uint32_t strokes = 0x0;

uint32_t runTime = 0;
uint32_t bins1;
uint32_t bins2;
uint32_t bins3;
uint32_t bins4;
uint32_t rawValue;
uint32_t scaledValue;

uint32_t yes = 0;
uint8 currentConnection;

SerialProto_t serialPort;

uint8_t accelerationx;
uint8_t accelerationy;
uint8_t accelerationz;

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
}


/* Main application */
void appMain(gecko_configuration_t *pconfig)
{
#if DISABLE_SLEEP > 0
  pconfig->sleep.flags = 0;
#endif

  /* Initialize debug prints. Note: debug prints are off by default. See DEBUG_LEVEL in app.h */
 //initLog();

 serialPort.txState = 0;
 serialPort.rxState = 0;
 serialPort.usart = USART0;
 serialPort.txCount = 0;
 serialPort.sentCount = 0;

  /* Initialize stack */
  gecko_init(pconfig);
  while (1) {

		  processSerial(&serialPort);
		  	  if (serialPort.rxDone) {
		  		  serialPort.rxDone = 0;
		  		  unPackData(serialPort.rxData);
		  		  serialPort.rxData[0] = serialPort.rxData[0];
		  	  }

    /* Event pointer for handling events */
    struct gecko_cmd_packet* evt;

    /* if there are no events pending then the next call to gecko_wait_event() may cause
     * device go to deep sleep. Make sure that debug prints are flushed before going to sleep */
    if (!gecko_event_pending()) {
      //flushLog();
    }


    evt = gecko_peek_event();

    if (evt == NULL) {
        if (yes > 100000){
        	yes = 0;
    //    	bins1 = bins[0] +  bins[1] +  bins[2] +  bins[3] +  bins[4];
    //    	bins2 =  bins[5] +  bins[6] +  bins[7] +  bins[8] +  bins[9];
    //    	bins3 =  bins[10] +  bins[11] +  bins[12] +  bins[13] +  bins[14];
    //    	bins4 =  bins[15] +  bins[16] +  bins[17] +  bins[18] +  bins[19];

        	if (active_connections_num>0) {
        		gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_stroke_count, sizeof(strokes), (uint8 *)&strokes);
        		gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_hours_pumped, sizeof(runTime), (uint8 *)&runTime);
        		gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_raw_value, sizeof(rawValue), (uint8 *)&rawValue);
        		gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_scaled_value, sizeof(scaledValue), (uint8 *)&scaledValue);
        	}

    //    	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_bin_1, sizeof(bins1), (uint8 *)&bins[0]);
    //    	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_bin_2, sizeof(bins2), (uint8 *)&bins[1]);
    //    	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_bin_3, sizeof(bins3), (uint8 *)&bins[2]);
    //    	gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_bin_4, sizeof(bins4), (uint8 *)&bins[3]);

    //    	for (int i = 0; i < 20; i++)
    //        	bins[i] = 0;
    //    		gecko_cmd_gatt_server_send_characteristic_notification(0xFF, gattdb_stroke_count, sizeof(bins[i]), (uint8 *)&bins[i]);
        }
        else{
        	yes++;

        }

    } else {



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

        break;

      case gecko_evt_le_connection_opened_id:

    	/* Increment connection counter */
    	active_connections_num++;

        //printLog("connection opened\r\n");
    	currentConnection = evt->data.evt_gatt_server_user_read_request.connection;

    	// IZI - This is what makes the device disapear, this should be fixed
        //if(active_connections_num < pconfig->bluetooth.max_connections)
            /* If maximum connections hasn't been reached we can restart advertising. */
        	 gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);
//        else
        	//printLog("Max connections reached. Advertising not enabled.\r\n");
        break;

      case gecko_evt_le_connection_closed_id:
    	active_connections_num--;
        //printLog("connection closed, reason: 0x%2.2x\r\n", evt->data.evt_le_connection_closed.reason);

        /* Check if need to boot to OTA DFU mode */
        if (boot_to_dfu) {
          /* Enter to OTA DFU mode */
          gecko_cmd_system_reset(2);
        } else {

        }
        // IZI - This also affects the visibility of the board
        	//if(active_connections_num == pconfig->bluetooth.max_connections - 1) {
        		//printLog("Connection is now available. Restarting advertising\r\n");
        		/* If we had the maximum connections we can go back to scanning and advertising as connectable */
        		gecko_cmd_le_gap_start_advertising(0, le_gap_general_discoverable, le_gap_connectable_scannable);
        //}
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
        break;

        /* Add additional event handlers as your application requires */
             case gecko_evt_gatt_server_user_read_request_id:
           	  if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_stroke_count) {
       			gecko_cmd_gatt_server_send_user_read_response(
       			  evt->data.evt_gatt_server_user_read_request.connection,
				  gattdb_stroke_count,
       			  bg_err_success,
				  sizeof(strokes),
				  (uint8 *)&strokes);
           	  }

           	  else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_hours_pumped) {
         			gecko_cmd_gatt_server_send_user_read_response(
         			  evt->data.evt_gatt_server_user_read_request.connection,
					  gattdb_hours_pumped,
         			  bg_err_success,
         			  sizeof(runTime),
					  (uint8 *)&runTime);
             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_raw_value) {
           	         			gecko_cmd_gatt_server_send_user_read_response(
           	         			  evt->data.evt_gatt_server_user_read_request.connection,
								  gattdb_raw_value,
           	         			  bg_err_success,
           	         			  sizeof(rawValue),
           						  (uint8 *)&rawValue);
           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_scaled_value) {
           	         			gecko_cmd_gatt_server_send_user_read_response(
           	         			  evt->data.evt_gatt_server_user_read_request.connection,
								  gattdb_scaled_value,
           	         			  bg_err_success,
           	         			  sizeof(scaledValue),
           						  (uint8 *)&scaledValue);
           	             	  }

           	  else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_1) {
         			gecko_cmd_gatt_server_send_user_read_response(
         			  evt->data.evt_gatt_server_user_read_request.connection,
					  evt->data.evt_gatt_server_user_read_request.characteristic,
         			  bg_err_success,
         			  sizeof(bins[0]),
					  (uint8 *)&bins[0]);
             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_2) {
           	         			gecko_cmd_gatt_server_send_user_read_response(
           	         			  evt->data.evt_gatt_server_user_read_request.connection,
								  evt->data.evt_gatt_server_user_read_request.characteristic,
           	         			  bg_err_success,
           	         			  sizeof(bins[1]),
								  (uint8 *)&bins[1]);
           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_3) {
           	         			gecko_cmd_gatt_server_send_user_read_response(
           	         			  evt->data.evt_gatt_server_user_read_request.connection,
								  evt->data.evt_gatt_server_user_read_request.characteristic,
           	         			  bg_err_success,
           	         			  sizeof(bins[2]),
								  (uint8 *)&bins[2]);
           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_4) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[3]),
											  (uint8 *)&bins[3]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_5) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[4]),
											  (uint8 *)&bins[4]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_6) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[5]),
											  (uint8 *)&bins[5]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_7) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[6]),
											  (uint8 *)&bins[6]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_8) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[7]),
											  (uint8 *)&bins[7]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_9) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[8]),
											  (uint8 *)&bins[8]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_10) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[9]),
											  (uint8 *)&bins[9]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_11) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[10]),
											  (uint8 *)&bins[10]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_12) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_write_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[11]),
											  (uint8 *)&bins[11]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_13) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_write_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[12]),
											  (uint8 *)&bins[12]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_14) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_write_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[13]),
											  (uint8 *)&bins[13]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_15) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_write_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[14]),
											  (uint8 *)&bins[14]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_16) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_write_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[15]),
											  (uint8 *)&bins[15]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_17) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[16]),
											  (uint8 *)&bins[16]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_18) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[17]),
											  (uint8 *)&bins[17]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_19) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[18]),
											  (uint8 *)&bins[18]);
           	           	             	  }
           	else if (evt->data.evt_gatt_server_user_read_request.characteristic == gattdb_bin_20) {
           	           	         			gecko_cmd_gatt_server_send_user_read_response(
           	           	         			  evt->data.evt_gatt_server_user_read_request.connection,
           									  evt->data.evt_gatt_server_user_read_request.characteristic,
           	           	         			  bg_err_success,
           	           	         			  sizeof(bins[19]),
											  (uint8 *)&bins[19]);
           	           	             	  }





           	 break;
      default:
        break;
    }
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
