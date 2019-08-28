
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

#include "ioteqDBFunctions.h"

uint8_t messageFlags[SERIAL_PROTO_MSG_MAX];


/* RX Functions */
void rxMsgProcessStrokesData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(Strokes, data);
}

void rxMsgProcessRunTimeData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(RunTime, data);
}

void rxMsgProcessBinsData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	for(int i = 0; i < 20; i++)
		setValue(&Bins[i], (uint8_t*)(((uint32_t*)data)+i));

	uint32_t calc1 = *(uint32_t*)getValue(&Bins[0]) + *(uint32_t*)getValue(&Bins[1]) + *(uint32_t*)getValue(&Bins[2]) + *(uint32_t*)getValue(&Bins[3]);
	uint32_t calc2 = *(uint32_t*)getValue(&Bins[4]) + *(uint32_t*)getValue(&Bins[5]) + *(uint32_t*)getValue(&Bins[6]) + *(uint32_t*)getValue(&Bins[7]);
	uint32_t calc3 = *(uint32_t*)getValue(&Bins[8]) + *(uint32_t*)getValue(&Bins[9]) + *(uint32_t*)getValue(&Bins[10]) + *(uint32_t*)getValue(&Bins[11]);
	uint32_t calc4 = *(uint32_t*)getValue(&Bins[12]) + *(uint32_t*)getValue(&Bins[13]) + *(uint32_t*)getValue(&Bins[14]) + *(uint32_t*)getValue(&Bins[15]);
	uint32_t calc5 = *(uint32_t*)getValue(&Bins[16]) + *(uint32_t*)getValue(&Bins[17]) + *(uint32_t*)getValue(&Bins[18]) + *(uint32_t*)getValue(&Bins[19]);
	setValue(&CalculatedBins[0], (uint8_t*)&calc1);
	setValue(&CalculatedBins[1], (uint8_t*)&calc2);
	setValue(&CalculatedBins[2], (uint8_t*)&calc3);
	setValue(&CalculatedBins[3], (uint8_t*)&calc4);
	setValue(&CalculatedBins[4], (uint8_t*)&calc5);
}

void rxMsgProcessDischargePSIData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(DischargePressure, data);
}

void rxMsgProcessSuctionPSIData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(SuctionPressure, data);
}

void rxMsgProcessAccelerometerData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(AccelerometerData, data);
}

void rxMsgProcessGPSData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(GPSData, data);
}

void rxMsgProcessFirmwareControl(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	memcpy(&pSerialObj->mcu->packetCounter, data,sizeof(pSerialObj->mcu->packetCounter));
}

void rxMsgProcessFirmwareInfo(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
	setValue(SystemInformation, data);
}

void rxMsgProcessTemperatureData(SerialProto_t *pSerialObj){
	uint8_t *data = pSerialObj->rxData + 1;
		for(int i = 0; i < 4; i++)
			setValue(&Temperature[i], (uint8_t*)(((float*)data)+i));
}

//void rxMsgProcessWiFiResponse(SerialProto_t *pSerialObj){
//	uint8_t *data = pSerialObj->rxData + 1;
//	setValue(WiFiResponse, data);
//}




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

int txMsgSendSuctionPSIScaling(SerialProto_t *pSerialObj){
	float data[6];
	data[0] = *(float*)getValue(SuctionRawZero);
	data[1] = *(float*)getValue(SuctionRawScale);
	data[2] = *(float*)getValue(SuctionUnitsScale);
	data[3] = *(float*)getValue(SuctionRawValue);
	data[4] = *(float*)getValue(SuctionPSIValue);
	data[5] = *(float*)getValue(SuctionRMS);
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_PSI_SUCTION_SCALING,sizeof(data)*3,(uint8_t *)data);
}

int txMsgSendDischargePSIScaling(SerialProto_t *pSerialObj){
	float data[6];
	data[0] = *(float*)getValue(DischargeRawZero);
	data[1] = *(float*)getValue(DischargeRawScale);
	data[2] = *(float*)getValue(DischargeUnitsScale);
	data[3] = *(float*)getValue(DischargeRawValue);
	data[4] = *(float*)getValue(DischargePSIValue);
	data[5] = *(float*)getValue(DischargeRMS);
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_PSI_DISCHARGE_SCALING,sizeof(data),(uint8_t *)data);
}

int txMsgSendResetData(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_RESET_DATA,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
}

int txMsgSendDischargeZeroRawValue(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_ZERO_RAW_DISCHARGE_VALUE,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
}

int txMsgSendSuctionZeroRawValue(SerialProto_t *pSerialObj){
	return txMsgSendMessage(pSerialObj,SERIAL_PROTO_MSG_ZERO_RAW_SUCTION_VALUE,sizeof(pSerialObj->mcu->control),(uint8_t *)&pSerialObj->mcu->control);
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
		case SERIAL_PROTO_MSG_REPORT_DISCHARGE_PSI:
			rxMsgProcessDischargePSIData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_SUCTION_PSI:
			rxMsgProcessSuctionPSIData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_ACCELEROMETER:
			rxMsgProcessAccelerometerData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_TEMPERATURE:
			rxMsgProcessTemperatureData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_REPORT_GPS:
			rxMsgProcessGPSData(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_FIRMWARE_CONTROL:
			rxMsgProcessFirmwareControl(pSerialObj);
			break;
		case SERIAL_PROTO_MSG_FIRMWARE_INFO:
			rxMsgProcessFirmwareInfo(pSerialObj);
			break;
//		case SERIAL_PROTO_MSG_WIFI_RESPONSE:
//			rxMsgProcessWiFiResponse(pSerialObj);
//			break;
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
