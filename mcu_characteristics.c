/*
 * mcu_characteristics.c
 *
 *  Created on: Jun 5, 2019
 *      Author: reidwilliams
 */

#include "mcu_characteristics.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>

void initMCUChars(MCU_Characteristics_t *mcuChars){

}
void calculateBins(MCU_Characteristics_t *mcuChars){
	mcuChars->binsData[0] = mcuChars->bins[0] + mcuChars->bins[1] + mcuChars->bins[2] +
			mcuChars->bins[3];
	mcuChars->binsData[1] = mcuChars->bins[4] + mcuChars->bins[5] + mcuChars->bins[6] +
			mcuChars->bins[7];
	mcuChars->binsData[2] = mcuChars->bins[8] + mcuChars->bins[9] + mcuChars->bins[10] +
			mcuChars->bins[11];
	mcuChars->binsData[3] = mcuChars->bins[12] + mcuChars->bins[13] + mcuChars->bins[14] +
			mcuChars->bins[15];
	mcuChars->binsData[4] = mcuChars->bins[16] + mcuChars->bins[17] + mcuChars->bins[18] +
			mcuChars->bins[19];
}
