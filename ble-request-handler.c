/*
 * ble-request-handler.c
 *
 *  Created on: Jul 18, 2019
 *      Author: reidwilliams
 */
#include "ble-request-handler.h"
#include "serialProtocolFunctions.h"

void sendUserReadResponse(const Tag_t* tag, struct gecko_cmd_packet* evt){
		gecko_cmd_gatt_server_send_user_read_response(
		  evt->data.evt_gatt_server_user_read_request.connection,
		  evt->data.evt_gatt_server_user_read_request.characteristic,
		  bg_err_success,
		  getTagSize(tag, 0),
		  (uint8 *)getValue(tag));
}

void handleUserWriteRequest(struct gecko_cmd_packet* evt){}

void handleUserReadRequest(struct gecko_cmd_packet* evt){

	switch (evt->data.evt_gatt_server_user_read_request.characteristic){
		case gattdb_Strokes:
			sendUserReadResponse(Strokes, evt);
			  break;
		case gattdb_Run_hours:
			  sendUserReadResponse(RunTime, evt);
			  break;
		case gattdb_PSI:
			  sendUserReadResponse(PSIData, evt);
			  break;
		case gattdb_Accelerometer:
			  sendUserReadResponse(AccelerometerData, evt);
			  break;
		case gattdb_location_and_speed:
			  sendUserReadResponse(GPSData, evt);
			  break;
		case gattdb_firmware_version:
			  sendUserReadResponse(SystemInformation, evt);
			  break;
	}
}
