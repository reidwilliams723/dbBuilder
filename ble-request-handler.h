/*
 * ble-request-handler.h
 *
 *  Created on: Jul 18, 2019
 *      Author: reidwilliams
 */

#ifndef BLE_REQUEST_HANDLER_H_
#define BLE_REQUEST_HANDLER_H_

#include "native_gecko.h"
#include "gatt_db.h"
#include "ioteqDBFunctions.h"
#include "ioteqDB.h"

void handleUserWriteRequest(struct gecko_cmd_packet* evt);
void handleUserReadRequest(struct gecko_cmd_packet* evt);
void sendUserReadResponse(const Tag_t* tag, struct gecko_cmd_packet* evt);
#endif /* BLE_REQUEST_HANDLER_H_ */
