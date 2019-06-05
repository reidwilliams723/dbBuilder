
/**************************************************************************
 *
 * Serial Functions Implementation of Interprocessor Serial Protocol
 *
 **************************************************************************
 *
 * This Library implements the function parsing of the serial protocol
 * All functions executed by serial ports must be impleneted here
 *
 * (c) 2019, IOT-eq LLC, All Rights Reserved
 * Programmed By: 	Reid Williams
 * 					Casey McKinley
 * 					Inaki Zuloaga
 *
 * Date: Jun 3, 2019
 * Contact: izi@iot-eq.com
 *
 * MODIFIED:
 * 		Jun 3, 2019 - First Version of this file
 *
 *
 *
 *
 **************************************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#include "serialProtocol.h"
#include "serialProtocolFunctions.h"

uint8_t messageFlags[SERIAL_PROTO_MSG_MAX];


//// Function that process a received Firmware Data Packet
//void rxMsgEraseFirmwareData() {
//	//int32_t result = bootloader_eraseStorageSlot(FIRMWARE_SLOT);
//	bootloader_eraseStorageSlot(FIRMWARE_SLOT);
//}
//
//// Function that process a received Firmware Data Packet
//// Blocks are fixed size and first element corresponds to the respective block to write
//void rxMsgProcessFirmwareData(uint8_t *data) {
//	uint16_t blockId = *(uint16_t *)data;
//	uint8_t  *pRxFirmwareData = data + sizeof(uint16_t);
///*	int32_t result = bootloader_writeStorage(FIRMWARE_SLOT,
//	                                blockId * FIRMWARE_BLOCK_SIZE, // offset in Buffer
//									pRxFirmwareData,               // Data
//									FIRMWARE_BLOCK_SIZE);          // Bytes to write
//*/
//	bootloader_writeStorage(FIRMWARE_SLOT,
//	                                blockId * FIRMWARE_BLOCK_SIZE, // offset in Buffer
//									pRxFirmwareData,               // Data
//									FIRMWARE_BLOCK_SIZE);          // Bytes to write
//
//}

void rxMsgProcessStrokesData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->strokes, data,sizeof(pSerialObj->mcu->strokes));
}




uint8_t txMsgStrokesData[100];
uint8_t txMsgStrokesDataCount = 0;





int txMsgSendStrokes(SerialProto_t *pSerialObj, uint32_t strokesCount) {
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_REPORT_STROKES,sizeof(strokesCount),(uint8_t *)&strokesCount);
}




// Function to send a message trough the serial port
// Returns false (0) if message couldn't be send so the user must retry
// Returns true (1) if message has been scheduled to be sent
int txMsgSendMessage(SerialProto_t *pSerialObj,uint8_t msgType,uint8_t dataLength, uint8_t *pBuffer)
{
    // Check if message can be sent
	if (pSerialObj->txCount != 0) {
		return 0;
	} else if (dataLength >= sizeof(pSerialObj->dataToTX)) {
		return 0;
	} else {
		pSerialObj->dataToTX[0] = msgType;
		memcpy(pSerialObj->dataToTX+1,pBuffer,dataLength+1);
		pSerialObj->txCount = dataLength+1;
	}
	return 1;
}


void serialProtocolProcessMessages(SerialProto_t *pSerialObj) {
	static int txMsgIndex = 0;
	// Process Serial Port
	processSerial(pSerialObj);

	// Receive Messages
	if (pSerialObj->rxDone) {
		// First Byte of message is Function
		switch (pSerialObj->rxData[0]) {
		case SERIAL_PROTO_MSG_PING:
			break;
		case SERIAL_PROTO_MSG_PONG:
			break;
		case SERIAL_PROTO_MSG_REPORT_STROKES:
			rxMsgProcessStrokesData(pSerialObj);
			break;

		}
		pSerialObj->rxDone = 0; // Signal Msg Processed
		//*********************** TESTING ONLY *************************
		//Send a Done command as response

		if (pSerialObj->txCount == 0) {
			pSerialObj->dataToTX[0] = SERIAL_PROTO_MSG_DONE;
			pSerialObj->txCount = 1;
		 }
		//*********************** END TESTING BLOCK *************************

	}
/*
 *  This piece of code was meant to just turn flags to send messages, but data handling got to complex.
 *
 *


	// Send Messages
	if (pSerialObj->txCount == 0) {
		// When Output buffer is empty check for all MSG requests
		while (txMsgIndex<SERIAL_PROTO_MSG_MAX) {
			if (messageFlags[txMsgIndex] & pSerialObj->portMask) {
				switch (txMsgIndex) {

				case SERIAL_PROTO_MSG_REPORT_STROKES:

					uint8_t txMsgStrokesData[100];
					uint8_t txMsgDtrokesDataCount = 0;

					//int dataCount =
					break;

				default:
					// In case is not an implemented MSG
					messageFlags[txMsgIndex] &= ~pSerialObj->portMask;
					txMsgIndex++;
					break;
				}

			}

		}


		pSerialObj->dataToTX[0] = SERIAL_PROTO_MSG_DONE;
		pSerialObj->txCount = 1;

	 }*/



}
