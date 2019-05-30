/*
 * serialProtocol.c
 *
 *  Created on: Apr 25, 2019
 *      Author: inakizi
 */


#include <stdio.h>
#include "em_device.h"
#include "em_cmu.h"
#include "em_chip.h"
#include "em_emu.h"
#include "bsp.h"

#include "em_rtcc.h"


#include "em_gpio.h"
#include "em_rmu.h"



#include "serialProtocol.h"


#define SERIAL_STATE_IDLE           0
#define SERIAL_STATE_WAIT_TX        1
#define SERIAL_STATE_SEND_HEADER1   2
#define SERIAL_STATE_SEND_HEADER2   3
#define SERIAL_STATE_SEND_LENGTH    4
#define SERIAL_STATE_SEND_DATA      5

#define SERIAL_STATE_WAIT_RX      10
#define SERIAL_STATE_RX_HEADER1   11
#define SERIAL_STATE_RX_HEADER2   12
#define SERIAL_STATE_RX_LENGTH    13
#define SERIAL_STATE_RX_DATA      14


//volatile extern uint32_t msTicks; /* counts 1ms timeTicks */





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
			serialObj->txState = SERIAL_STATE_SEND_DATA;
			serialObj->sentCount = 0;
		}
		break;

	case SERIAL_STATE_SEND_DATA:
		if (txAvailable(serialObj->usart)) {
			USART_Tx(serialObj->usart, serialObj->dataToTX[serialObj->sentCount++]);
			if (serialObj->sentCount>=serialObj->txCount) {
				serialObj->txState = SERIAL_STATE_WAIT_TX;
				serialObj->txCount = 0;
			}
		}
		break;

	}




	switch (serialObj->rxState) {

	case SERIAL_STATE_IDLE:
		serialObj->rxState = SERIAL_STATE_WAIT_RX;
		break;

	case SERIAL_STATE_WAIT_RX:
		if (rxAvailable(serialObj->usart)) {
			serialObj->rxState = SERIAL_STATE_RX_HEADER1;
			//serialObj->lastRXTime = msTicks;
		}

		break;

	case SERIAL_STATE_RX_HEADER1:
		rxData = USART_Rx(serialObj->usart);
		if (rxData == 0xA5) {
			serialObj->rxState = SERIAL_STATE_RX_HEADER2;
			//serialObj->lastRXTime = msTicks;
		} else {
			serialObj->rxState = SERIAL_STATE_WAIT_RX;
		}
		break;

	case SERIAL_STATE_RX_HEADER2:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			if (rxData == 0x5A) {
				serialObj->rxState = SERIAL_STATE_RX_LENGTH;
				//serialObj->lastRXTime = msTicks;
			} else {
				serialObj->rxState = SERIAL_STATE_WAIT_RX;
			}
		}
		break;

	case SERIAL_STATE_RX_LENGTH:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);

			//serialObj->lastRXTime = msTicks;
			serialObj->rxLen = rxData;
			serialObj->rxCount = 0;
			serialObj->rxDone = 0;
			serialObj->rxState = SERIAL_STATE_RX_DATA;
			// Extra safeward
			if (rxData != 96) {
				serialObj->rxState = SERIAL_STATE_WAIT_RX;
			}
		}
		break;


	case SERIAL_STATE_RX_DATA:
		if (rxAvailable(serialObj->usart)) {
			rxData = USART_Rx(serialObj->usart);
			//serialObj->lastRXTime = msTicks;
			serialObj->rxData[serialObj->rxCount++] = rxData;
			if (serialObj->rxCount >= serialObj->rxLen) {
				serialObj->rxDone = 1;
				serialObj->rxState = SERIAL_STATE_WAIT_RX;
			}
		}
		break;


	}



/*



	   USART_Tx(USART0, welcome_string[i]);
	  }

	  while (1)
	  {
	    // Read a line from the UART
	    for (i = 0; i < BUFFER_SIZE - 1 ; i++ )
	    {
	      buffer[i] = USART_Rx(USART0);
	      if (buffer[i] == '\r')
	      {
	        break; // Breaking on CR prevents it from being counted in the number of bytes
	      }
	    }

	    // Echo the line back, adding CRLF
	    for (j = 0; j < i ; j ++ )
	    {
	      USART_Tx(USART0, buffer[j]);
	    }
	    USART_Tx(USART0, '\r');
	    USART_Tx(USART0, '\f');
	  }


*/

}

