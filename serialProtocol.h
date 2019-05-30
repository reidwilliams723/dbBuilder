/*
 * serialProtocol.h
 *
 *  Created on: Apr 25, 2019
 *      Author: inakizi
 */

#ifndef SRC_SERIALPROTOCOL_H_
#define SRC_SERIALPROTOCOL_H_




typedef struct SerialProto {
	uint32_t txState;
	uint32_t rxState;
	USART_TypeDef *usart;

	uint32_t txCount;
	uint8_t dataToTX[200];
	uint32_t sentCount;

	uint32_t lastRXTime;
	uint32_t rxLen;
	uint32_t rxCount;
	uint8_t  rxData[200];
	uint32_t rxDone;


} SerialProto_t;



void processSerial(SerialProto_t *serialObj);



#endif /* SRC_SERIALPROTOCOL_H_ */
