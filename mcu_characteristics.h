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
<<<<<<< HEAD

	float strokes;
	float runTime;
	float bins[20];
	float binsData[5]; // Aggregates and divides bins[20] into 5 values
	float psiData[5];  // Holds the RawZero, RawScale, UnitsScale, PSI Raw Value, and Scaled PSI Value
	float accelerometerData[3]; // Holds the X,Y, and Z values
	float gpsData[5];
	float newPsiScaling[5];

=======
>>>>>>> database
	uint8_t eraseFirmwarePacket;
	uint8_t flashFirmwarePacket;
	uint8_t firmwareDataBuffer[18];
	uint32_t packetCounter;

	uint8_t control;

<<<<<<< HEAD
	float firmwareVersions[2];


=======
>>>>>>> database
} MCU_Characteristics_t;

#endif /* MCU_CHARACTERISTICS_H_ */
