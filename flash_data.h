/*
 * flash_data.h
 *
 *  Created on: Jul 10, 2019
 *      Author: inakizi
 */

#ifndef FLASH_DATA_H_
#define FLASH_DATA_H_

#include "em_msc.h"


#define USERDATA ((uint32_t*)USERDATA_BASE)



// Saves a device Name
void saveBLEDeviceId(char *name,int len);
char *getBLEDeviceDataPtr();
void clearBLEDeviceId();


#endif /* FLASH_DATA_H_ */
