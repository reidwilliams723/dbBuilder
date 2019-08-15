
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

#ifndef SRC_SERIALPROTOCOLFUNCTIONS_H_
#define SRC_SERIALPROTOCOLFUNCTIONS_H_

#include "ioteqDB.h"

// This is the Slot of internal memory where firmware is copied
#define FIRMWARE_SLOT 0

// Size of firmware blocks sent via serial Protocol
#define FIRMWARE_BLOCK_SIZE 16


// This is the maximum number of message defined
// This is to create an array of flags of messages that
// need to be sent
#define SERIAL_PROTO_MSG_MAX					50

#define SERIAL_PROTO_MSG_PING          			0
#define SERIAL_PROTO_MSG_PONG          			1
#define SERIAL_PROTO_MSG_DONE          			2
#define SERIAL_PROTO_MSG_ERASE_FIRMWARE_SLOT 	3
#define SERIAL_PROTO_MSG_FIRMWARE_DATA       	4
#define SERIAL_PROTO_MSG_FIRMWARE_FLASH       	5
#define SERIAL_PROTO_MSG_RESET_DATA             6
#define SERIAL_PROTO_MSG_ZERO_RAW_VALUE         7
#define SERIAL_PROTO_MSG_PSI_SCALING            8
#define SERIAL_PROTO_MSG_REPORT_STROKES         9
#define SERIAL_PROTO_MSG_REPORT_RUNTIME         10
#define SERIAL_PROTO_MSG_REPORT_BINS            11
#define SERIAL_PROTO_MSG_REPORT_PSI             12
#define SERIAL_PROTO_MSG_REPORT_ACCELEROMETER   13
#define SERIAL_PROTO_MSG_REPORT_GPS             14
#define SERIAL_PROTO_MSG_FIRMWARE_CONTROL       15
#define SERIAL_PROTO_MSG_TOGGLE_LED             16
#define SERIAL_PROTO_MSG_FIRMWARE_INFO			17


void serialProtocolProcessMessages(SerialProto_t *pSerialObj);





/* TX Functions */
int txMsgSendEraseFirmware(SerialProto_t *pSerialObj);
int txMsgSendFirmwareData(SerialProto_t *pSerialObj);
int txMsgSendFlashFirmware(SerialProto_t *pSerialObj);
int txMsgSendPSIScaling(SerialProto_t *pSerialObj);
int txMsgSendResetData(SerialProto_t *pSerialObj);
int txMsgSendZeroRawValue(SerialProto_t *pSerialObj);
int txMsgSendToggleLED(SerialProto_t *pSerialObj);
int txMsgSendMessage(SerialProto_t *pSerialObj,uint8_t msgType,uint8_t dataLength, uint8_t *pBuffer);





/* RX Functions */
void rxMsgProcessStrokesData(SerialProto_t *pSerialObj);
void rxMsgProcessRunTimeData(SerialProto_t *pSerialObj);
void rxMsgProcessBinsData(SerialProto_t *pSerialObj);
void rxMsgProcessPSIData(SerialProto_t *pSerialObj);
void rxMsgProcessAccelerometerData(SerialProto_t *pSerialObj);
void rxMsgProcessGPSData(SerialProto_t *pSerialObj);
void rxMsgProcessFirmwareControl(SerialProto_t *pSerialObj);
void rxMsgProcessFirmwareInfo(SerialProto_t *pSerialObj);


void initDatabase();

/* Tags */
const Tag_t* Strokes;
const Tag_t* RunTime;
const Tag_t* PSIData;
const Tag_t* GPSData;
const Tag_t* SystemInformation;
const Tag_t* PSIRawValue;
const Tag_t* RawZero;
const Tag_t* ScaledPSIValue;
const Tag_t CalculatedBins[5];
const Tag_t Bins[20];
const Tag_t* AccelerometerData;

#endif /* SRC_SERIALPROTOCOLFUNCTIONS_H_ */