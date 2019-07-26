#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ioteqDB.h"
#include "ioteqDBFunctions.h"

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

uint8_t getTagSize(const Tag_t* tag, uint8_t size){

    if (tag->numOfChildren !=0){
        for (int i = 0; i < tag->numOfChildren; i++){
            const Tag_t* currentChild = tree + ((tag->childPtr/sizeof(Tag_t)) + i);
            size += getTagSize(currentChild, size);
        }
    }
    else {
        size = tag->valueSize;
    }
    return size;
}

uint8_t* getValue(const Tag_t* tag){
    if (tag->numOfChildren != 0){

        for (int i = 0; i < tag->numOfChildren; i++){
        	const Tag_t* child = tree + ((tag->childPtr/sizeof(Tag_t)) + i);
        	if (child->persistent && *(persistentData-1) == 0x00A5005A){
//        		memcpy((data + child->valuePtr), persistentData + (sizeof(uint32_t)/child->valuePtr), (sizeof(uint32_t)/child->valueSize));
        	}
        }
        const Tag_t* child = tree + (tag->childPtr/sizeof(Tag_t));
        return data + child->valuePtr;
    }
    else{
        if (tag->persistent)
        	if (*(persistentData-1) != 0x00A5005A)
        		return data + tag->valuePtr;
        	else
        		return (uint8_t*)(persistentData + (sizeof(uint32_t)/tag->valuePtr));
        else
            return data + tag->valuePtr;
    }
}

void setValue(const Tag_t* tag, uint8_t* value){

    if (tag->numOfChildren != 0){
        const Tag_t* child = tree + (tag->childPtr/sizeof(Tag_t));
        memcpy(data + child->valuePtr, value, getTagSize(tag, 0));
    }
    else{
    	if (tag->persistent)
    		*(persistentData + tag->valuePtr) = *(uint32_t*)value;

    	memcpy((data + tag->valuePtr), value, tag->valueSize);
    }
}

void initPersistentMemory(uint32_t volatile *address){
	if (address[0] != 0x00A5005A)
		address[0] = 0x00A5005A;
	persistentData = address+1;
}
