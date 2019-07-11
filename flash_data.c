/*
 * flash_data.c
 *
 *  Created on: Jul 10, 2019
 *      Author: inakizi
 */

#include "flash_data.h"
#include "em_msc.h"





/*
void flashTest()
{

 // Declare the value to be stored in flash
  uint32_t value = 32;

  // Clear the Userdata page of any previous data stored
  MSC_ErasePage((uint32_t*)USERDATA_BASE);

  // Read the initial value in the cleared page
  Cleared_value = USERDATA[4];

  // Write the value into the first location of the Userdata portion of the flash
  MSC_Init();
  MSC_WriteWord(((uint32_t*)USERDATA_BASE + 4),&value,8);
  MSC_Deinit();

  // Read the written data from the flash location it was stored in
  Set_value = USERDATA[4];

}
*/

// Saves a device Name
void saveBLEDeviceId(char *name,int len)
{
	int wordLength = len;
	if (len % 4 != 0){
		wordLength = len + (4-(len % 4));
	}

	// Write the value into the first location of the Userdata portion of the flash
	MSC_Init();
	MSC_WriteWord(((uint32_t*)USERDATA_BASE),name,wordLength);
	MSC_Deinit();

}

char *getBLEDeviceDataPtr()
{
	return USERDATA;
}

void clearBLEDeviceId(){
	MSC_Init();
	MSC_ErasePage((uint32_t*)USERDATA_BASE);
	MSC_Deinit();
}



