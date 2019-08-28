/*
 * mcu_characteristics.h
 *
 *  Created on: Jun 4, 2019
 *      Author: reidwilliams
 */

#ifndef MCU_CHARACTERISTICS_H_
#define MCU_CHARACTERISTICS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

typedef struct MCU_Characteristics {
	uint8_t eraseFirmwarePacket;
	uint8_t flashFirmwarePacket;
	uint8_t firmwareDataBuffer[18];
	uint32_t packetCounter;

	uint8_t control;

} MCU_Characteristics_t;

#endif /* MCU_CHARACTERISTICS_H_ */
