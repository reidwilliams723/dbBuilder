
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
#include "mcu_characteristics.h"

uint8_t messageFlags[SERIAL_PROTO_MSG_MAX];




/* RX Functions */
void rxMsgProcessStrokesData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->strokes, data,sizeof(pSerialObj->mcu->strokes));
}

void rxMsgProcessRunTimeData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->runTime, data,sizeof(pSerialObj->mcu->runTime));
}

void rxMsgProcessBinsData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->bins, data,sizeof(pSerialObj->mcu->bins));
	calculateBins(pSerialObj->mcu);
}

void rxMsgProcessPSIData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->psiData, data, sizeof(pSerialObj->mcu->psiData));
}

void rxMsgProcessAccelerometerData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->accelerometerData, data,sizeof(pSerialObj->mcu->accelerometerData));
}

void rxMsgProcessGPSData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->gpsData, data,sizeof(pSerialObj->mcu->gpsData));
}

void rxMsgProcessFirmwareControl(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->packetCounter, data,sizeof(pSerialObj->mcu->packetCounter));
}


/* TX Functions */
int txMsgSendEraseFirmware(SerialProto_t *pSerialObj) {
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_ERASE_FIRMWARE_SLOT,sizeof(uint8_t),(uint8_t *)&pSerialObj->mcu->eraseFirmwarePacket);
}

int txMsgSendFirmwareData(SerialProto_t *pSerialObj) {
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_FIRMWARE_DATA,sizeof(pSerialObj->mcu->firmwareDataBuffer),(uint8_t *)&pSerialObj->mcu->firmwareDataBuffer);
}

int txMsgSendFlashFirmware(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_FIRMWARE_FLASH,sizeof(uint8_t),(uint8_t *)&pSerialObj->mcu->flashFirmwarePacket);
}

int txMsgSendPSIScaling(SerialProto_t *pSerialObj){

	float psiScaling[3];
	memcpy(&psiScaling[0], &pSerialObj->mcu->newPsiScaling[0], sizeof(float));
	memcpy(&psiScaling[1], &pSerialObj->mcu->newPsiScaling[1], sizeof(float));
	memcpy(&psiScaling[2], &pSerialObj->mcu->newPsiScaling[2], sizeof(float));

	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_PSI_SCALING,sizeof(psiScaling),(uint8_t *)psiScaling);
}

int txMsgSendResetData(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_RESET_DATA,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
}

int txMsgSendZeroRawValue(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_ZERO_RAW_VALUE,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
}

int txMsgSendToggleLED(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_TOGGLE_LED,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
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
		memcpy(pSerialObj->dataToTX+1,pBuffer,dataLength);
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
		case SERIAL_PROTO_MSG_REPORT_RUNTIME:
			rxMsgProcessRunTimeData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_BINS:
			rxMsgProcessBinsData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_PSI:
			rxMsgProcessPSIData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_ACCELEROMETER:
			rxMsgProcessAccelerometerData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_GPS:
			rxMsgProcessGPSData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_FIRMWARE_CONTROL:
			rxMsgProcessFirmwareControl(pSerialObj);
			break;

		}
		pSerialObj->rxDone = 0; // Signal Msg Processed
		//*********************** TESTING ONLY *************************
		//Send a Done command as response

//		if (pSerialObj->txCount == 0) {
//			pSerialObj->dataToTX[0] = SERIAL_PROTO_MSG_DONE;
//			pSerialObj->txCount = 1;
//		 }
		//*********************** END TESTING BLOCK *************************

	}
}
