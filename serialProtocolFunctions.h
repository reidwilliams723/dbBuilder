
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
#define SERIAL_PROTO_MSG_REPORT_STROKES         6
#define SERIAL_PROTO_MSG_ZERO_RAW_VALUE         7
#define SERIAL_PROTO_MSG_RESET_DATA             8
#define SERIAL_PROTO_MSG_REPORT_RUNTIME         9
#define SERIAL_PROTO_MSG_REPORT_BINS            10
#define SERIAL_PROTO_MSG_REPORT_PSI             11
#define SERIAL_PROTO_MSG_REPORT_ACCELEROMETER   12
#define SERIAL_PROTO_MSG_REPORT_GPS             13


void serialProtocolProcessMessages(SerialProto_t *pSerialObj);





/* TX Functions */
int txMsgSendEraseFirmware(SerialProto_t *pSerialObj);
int txMsgSendFirmwareData(SerialProto_t *pSerialObj);
int txMsgSendFlashFirmware(SerialProto_t *pSerialObj);
int txMsgSendPSIScaling(SerialProto_t *pSerialObj);
int txMsgSendResetData(SerialProto_t *pSerialObj);
int txMsgSendZeroRawValue(SerialProto_t *pSerialObj);
int txMsgSendMessage(SerialProto_t *pSerialObj,uint8_t msgType,uint8_t dataLength, uint8_t *pBuffer);





/* RX Functions */
void rxMsgProcessStrokesData(SerialProto_t *pSerialObj);
void rxMsgProcessRunTimeData(SerialProto_t *pSerialObj);
void rxMsgProcessBinsData(SerialProto_t *pSerialObj);
void rxMsgProcessPSIData(SerialProto_t *pSerialObj);
void rxMsgProcessAccelerometerData(SerialProto_t *pSerialObj);
void rxMsgProcessGPSData(SerialProto_t *pSerialObj);





#endif /* SRC_SERIALPROTOCOLFUNCTIONS_H_ */
