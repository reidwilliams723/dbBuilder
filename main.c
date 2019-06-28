#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "advertise-data.h"

const Tag_t* parseTag(char* strTest, char delim[], const Tag_t* currentTag){

    for (int i = 0; i <= currentTag->numOfChildren; i++){

        const Tag_t* tempTag = tree + i + ((currentTag->childPtr/sizeof(Tag_t)));
        uint8_t test =  i + ((currentTag->childPtr));
        const char* tempName = tempTag->namePtr + str;
         
        if(memcmp(strTest, tempName, tempTag->nameSize) == 0){
            strTest = strtok(NULL, delim);
            if(strTest != NULL){
                return parseTag(strTest, delim, tempTag);
            }
            else {
                return tempTag;
            }
        }
    }

    return NULL;
}

const Tag_t* getTag(char * tagName){

    /* When the requested tag name has a "." in the string (requesting a child tag) */
    if (strstr(tagName, ".") != NULL){
        char delim[] = ".";
        char *tagNamePtr = strtok(strdup(tagName), delim);
        return parseTag(tagNamePtr, delim, tree);     
    }
    else {
        return parseTag(tagName, "", tree);
    }
}

uint8_t* getValue(const Tag_t* tag){
    return data + tag->valuePtr;
}

void setValue(const Tag_t* tag, uint8_t* value){
    memcpy((data + tag->valuePtr), value, tag->valueSize);
}

void addAdvertiseData(Advertise_Message_t* message, uint8_t type, uint8_t* data, uint8_t length){

	message->currentIndex = message->nextIndex;

	uint8_t* adData;
    uint8_t msgLength = sizeof(type) + length + sizeof(uint8_t);
	adData = (uint8_t *) calloc(msgLength, sizeof(uint8_t));

	adData[0] = sizeof(type) + length;
	adData[1] = type;
	memcpy(adData + 2, data, length);

	memcpy(message->nextIndex, adData, sizeof(uint8_t) * msgLength);
	message->nextIndex += sizeof(uint8_t) * msgLength;
}

void initAdvertiseMessage(Advertise_Message_t* message){
    uint8_t flags = 0x06;
    message->currentIndex = message->advertiseData;
    message->nextIndex = message->advertiseData;
    
    addAdvertiseData(message,
                Flags,
                &flags,
                sizeof(uint8_t));
	/* Device Name */
    addAdvertiseData(message,
					Complete_Local_Name,
					getValue(getTag("DeviceName")),
                    getTag("DeviceName")->valueSize);

	/* Manufacturer Data */
    addAdvertiseData(message,
					Manufacturer_Specific_Data,
					getValue(getTag("ManufacturerData")),
                    getTag("ManufacturerData")->valueSize);

	/* Service Data */
//	uint8_t serviceDataMsg[6];
//	serviceDataMsg[0] = ADVERTISED_SERVICE & 0xFF;
//	serviceDataMsg[1] = ADVERTISED_SERVICE >> 8;
//	memcpy(serviceDataMsg + 2,
//			getValue(getTag("Temperature")),
//			getTag("Temperature")->valueSize);
//
//	addAdvertiseData(message,
//					Service_Data,
//					(uint8_t*)serviceDataMsg,
//					sizeof(serviceDataMsg));

}

Advertise_Message_t message;

int main(void){
     initAdvertiseMessage(&message);
    Tag_t* test = getTag("Flags");
    float* test2 = (float*)getValue(test);
    
}