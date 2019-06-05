/**************************************************************************
 *
 * Interprocessor Serial Protocol
 *
 **************************************************************************
 *
 * This Library implements bidirectional communication between the main
 * MCU and the BLE MCU in the Weir FluidEnd Monitor
 *
 * (c) 2019, IOT-eq LLC, All Rights Reserved
 * Programmed By: 	Reid Williams
 * 					Casey McKinley
 * 					Inaki Zuloaga
 *
 * Date: May 30, 2019
 * Contact: izi@iot-eq.com
 *
 * MODIFIED:
 * 		May 30, 2019 Added this header and general cleanup
 *
 *
 *
 *
 **************************************************************************
 */
#include <stdio.h>
#include "em_device.h"
#include "em_cmu.h"
#include "em_chip.h"
#include "em_emu.h"

#include "em_rtcc.h"


#include "em_gpio.h"
#include "em_rmu.h"

#include "em_usart.h"


#include "serialProtocol.h"


#define SERIAL_STATE_IDLE           0
#define SERIAL_STATE_WAIT_TX        1
#define SERIAL_STATE_SEND_HEADER1   2
#define SERIAL_STATE_SEND_HEADER2   3
#define SERIAL_STATE_SEND_LENGTH    4
#define SERIAL_STATE_SEND_DATA      5
#define SERIAL_STATE_SEND_NULL      6

//#define SERIAL_STATE_WAIT_RX      10
#define SERIAL_STATE_RX_HEADER1   11
#define SERIAL_STATE_RX_HEADER2   12
#define SERIAL_STATE_RX_NULL      13
#define SERIAL_STATE_RX_LENGTH    14
#define SERIAL_STATE_RX_DATA      15



int rxAvailable(USART_TypeDef *usart) {
	if (!(usart->STATUS & USART_STATUS_RXDATAV)) {
		return 0;
	}
	return 1;
}

int txAvailable(USART_TypeDef *usart) {
	if (!(usart->STATUS & USART_STATUS_TXBL)) {
		return 0;
	}
	return 1;
}

//uint8_t USART_Rx(USART_TypeDef *usart)
//  void USART_Tx(USART_TypeDef *usart, uint8_t data)


// Port Mask allows handling up to 8 ports.
// The mask signal what bit is used of the MSG send array
// in the serialProtocolFunctions
uint8_t portMask = 1;



void initSerialProtocol(SerialProto_t *serialObj,USART_TypeDef *usart) {
	serialObj->txState = 0;
	serialObj->rxState = 0;
	serialObj->usart = usart;
	serialObj->txCount = 0;
	serialObj->sentCount = 0;

	serialObj->rxLen = 0;
	serialObj->rxCount = 0;
	serialObj->rxDone = 0;



}



void processSerial(SerialProto_t *serialObj) {
	uint8_t rxData;

	switch (serialObj->txState) {

	case SERIAL_STATE_IDLE:
		serialObj->txState = SERIAL_STATE_WAIT_TX;
		break;

	case SERIAL_STATE_WAIT_TX:
		if (serialObj->txCount >0) {
			serialObj->txState = SERIAL_STATE_SEND_HEADER1;
		}
		break;

	case SERIAL_STATE_SEND_HEADER1:
		if (txAvailable(serialObj->usart)) {
			USART_Tx(serialObj->usart, 0xA5);
			serialObj->txState = SERIAL_STATE_SEND_HEADER2;
		}
		break;

	case SERIAL_STATE_SEND_HEADER2:
		if (txAvailable(serialObj->usart)) {
			USART_Tx(serialObj->usart, 0x5A);
			serialObj->txState = SERIAL_STATE_SEND_LENGTH;
			serialObj->sentCount = 0;
		}
		break;

	case SERIAL_STATE_SEND_LENGTH:
		if (txAvailable(serialObj->usart)) {
			USART_Tx(serialObj->usart, serialObj->txCount);
			if (serialObj->txCount == 0xA5) {
				serialObj->txState = SERIAL_STATE_SEND_NULL;
				serialObj->sentCount = 0;
			} else {
				serialObj->txState = SERIAL_STATE_SEND_DATA;
				serialObj->sentCount = 0;
			}
		}
		break;

	case SERIAL_STATE_SEND_DATA:
		if (txAvailable(serialObj->usart)) {
			// If a 0xA5 is sent then next will send a dummy 0x00 to avoid a misdetection of a header
			// The receiving side will get rid of the extra 0x00
			if ((serialObj->sentCount>1) && (serialObj->dataToTX[serialObj->sentCount] == 0xA5)) {
				USART_Tx(serialObj->usart, serialObj->dataToTX[serialObj->sentCount++]);
				serialObj->txState = SERIAL_STATE_SEND_NULL;
			}
			USART_Tx(serialObj->usart, serialObj->dataToTX[serialObj->sentCount++]);
			if (serialObj->sentCount>=serialObj->txCount) {
				serialObj->txState = SERIAL_STATE_WAIT_TX;
				serialObj->txCount = 0;
			}
		}
		break;

	case SERIAL_STATE_SEND_NULL:
		if (txAvailable(serialObj->usart)) {
			USART_Tx(serialObj->usart, 0x00);
			if (serialObj->sentCount>=serialObj->txCount) {
				serialObj->txState = SERIAL_STATE_WAIT_TX;
				serialObj->txCount = 0;
			} else {
				serialObj->txState = SERIAL_STATE_SEND_DATA;
			}
		}
		break;
	}




	switch (serialObj->rxState) {

	case SERIAL_STATE_IDLE:
		serialObj->rxState = SERIAL_STATE_RX_HEADER1;
		break;

	case SERIAL_STATE_RX_HEADER1:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			if (rxData == 0xA5) {
				serialObj->rxState = SERIAL_STATE_RX_HEADER2;
			} else {
				serialObj->rxState = SERIAL_STATE_RX_HEADER1;
			}
		}
		break;

	case SERIAL_STATE_RX_HEADER2:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			if (rxData == 0x5A) {
				serialObj->rxState = SERIAL_STATE_RX_LENGTH;
			} else if (rxData != 0xA5) { // If another 0xA5 is received remain in this state to check for next header byte
				serialObj->rxState = SERIAL_STATE_RX_HEADER1;
			}
		}
		break;


	case SERIAL_STATE_RX_LENGTH:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);

			serialObj->rxLen = rxData;
			serialObj->rxCount = 0;
			serialObj->rxDone = 0;

			if (rxData == 0xA5) {
				serialObj->rxState = SERIAL_STATE_RX_NULL;
			} else {
				serialObj->rxState = SERIAL_STATE_RX_DATA;
			}
		}
		break;

	case SERIAL_STATE_RX_NULL:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			if (rxData == 0x5A) {
				// This means that the previous 0xA5 was a message start
				serialObj->rxState = SERIAL_STATE_RX_LENGTH;
			} else if (rxData != 0x00) {
				// This means that we got garbage, because unless in the header a
				// NULL should come after 0xA5. In this case reset state machine
				serialObj->rxState = SERIAL_STATE_RX_HEADER1;
			} else {
				if (serialObj->rxCount >= serialObj->rxLen) {
					serialObj->rxDone = 1;
					serialObj->rxState = SERIAL_STATE_RX_HEADER1;
				} else {
					serialObj->rxState = SERIAL_STATE_RX_DATA;
				}
			}
		}
		break;

	case SERIAL_STATE_RX_DATA:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			serialObj->rxData[serialObj->rxCount++] = rxData;
			if (rxData == 0xA5) {
				serialObj->rxState = SERIAL_STATE_RX_NULL;
			} else if (serialObj->rxCount >= serialObj->rxLen) {
				serialObj->rxDone = 1;
				serialObj->rxState = SERIAL_STATE_RX_HEADER1;
			}
		}
		break;


	}
}

