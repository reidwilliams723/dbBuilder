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

#ifndef SRC_SERIALPROTOCOL_H_
#define SRC_SERIALPROTOCOL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

#include "em_device.h"
#include "em_cmu.h"
#include "em_chip.h"
#include "em_emu.h"
#include "em_rtcc.h"
#include "em_gpio.h"
#include "em_rmu.h"

#include "mcu_characteristics.h"



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

	uint8_t portMask;

	MCU_Characteristics_t *mcu;

} SerialProto_t;


void initSerialProtocol(SerialProto_t *serialObj,USART_TypeDef *usart);
void processSerial(SerialProto_t *serialObj);



#endif /* SRC_SERIALPROTOCOL_H_ */
