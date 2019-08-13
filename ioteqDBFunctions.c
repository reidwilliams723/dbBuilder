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

uint8_t iterateChildren(const Tag_t* tag, uint8_t size){
    size+= tag->valueSize;
    const char* tempName = tag->namePtr + str;
    if (tag->nextSibling != 0){
         const Tag_t* nextSibling = tree + (tag->nextSibling/sizeof(Tag_t));
         return iterateChildren(nextSibling, size);
    }

    else {
        return size;
    }
}
uint8_t getTagSize(const Tag_t* tag, uint8_t size){

    if (tag->numOfChildren !=0){
        const Tag_t* currentChild = tree + (tag->childPtr/sizeof(Tag_t));
        const char* tempName = currentChild->namePtr + str;
        size = iterateChildren(currentChild, 0);
    }
    else {
        size = tag->valueSize;
    }
    return size;
}

uint8_t* iterateChildrenValues(const Tag_t* tag, uint8_t* dataArray, uint8_t index){
    memcpy(dataArray + index, getValue(tag), tag->valueSize);
     float* test = (float*)(dataArray + index);
     float* test2 = (float*)getValue(tag);
    index+=4;
    if (tag->nextSibling != 0){
        const Tag_t* nextSibling = tree + (tag->nextSibling/sizeof(Tag_t));
        dataArray = iterateChildrenValues(nextSibling, dataArray, index);
        return dataArray;
    }

    else {
        
        return dataArray;
    }
}

uint8_t* getValue(const Tag_t* tag){
    if (tag->numOfChildren != 0){
        uint8_t index = 0;
        uint8_t dataArray[getTagSize(tag,0)];

        const Tag_t* currentChild = tree + ((tag->childPtr/sizeof(Tag_t)));
        memcpy(dataArray, getValue(currentChild), currentChild->valueSize);
        index+=4;
        if (currentChild->nextSibling != 0){
            const Tag_t* nextSibling = tree + (currentChild->nextSibling/sizeof(Tag_t));
            return iterateChildrenValues(nextSibling, dataArray, index);
        }

        return data + currentChild->valuePtr;
    }
    else{
        if (tag->isPersistent && *persistentData == 0x00A5005A){

            return (uint8_t*)(persistentData + 1 + (tag->persistentPtr/sizeof(uint32_t)));
        }
        else {
            return data + tag->valuePtr;
        }
    }
}

void setValue(const Tag_t* tag, char* value){

    if (tag->numOfChildren != 0){
        const Tag_t* child = tree + (tag->childPtr/sizeof(Tag_t));
        memcpy(data + child->valuePtr, value, getTagSize(tag, 0));
    }
    else{
        if (tag->isPersistent && *persistentData == 0x00A5005A){

        	*(persistentData + 1 + (tag->persistentPtr/sizeof(uint32_t))) = *(uint32_t*)value;
        }
        else {
        memcpy((data + tag->valuePtr), value, tag->valueSize);
        }
    }
}