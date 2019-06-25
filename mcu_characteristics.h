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

	uint32_t strokes;
	uint32_t runTime;
	uint32_t bins[20];
	uint32_t binsData[5]; // Aggregates and divides bins[20] into 5 values
	float psiData[5];  // Holds the RawZero, RawScale, UnitsScale, PSI Raw Value, and Scaled PSI Value
	uint32_t accelerometerData[3]; // Holds the X,Y, and Z values
	float gpsData[5];
	float newPsiScaling[5];

	uint8_t eraseFirmwarePacket;
	uint8_t flashFirmwarePacket;
	uint8_t firmwareDataBuffer[18];
	uint32_t packetCounter;

	uint8_t control;

	uint32_t firmwareVersions[2];


} MCU_Characteristics_t;

void initMCUChars(MCU_Characteristics_t *mcuChars);
void calculateBins(MCU_Characteristics_t *mcuChars);
#endif /* MCU_CHARACTERISTICS_H_ */
