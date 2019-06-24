#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"


Tag_t* parseTag(char* strTest, char delim[], Tag_t* currentTag){

    for (int i = 0; i <= currentTag->numOfChildren; i++){

        Tag_t* tempTag = tree + i + ((currentTag->childPtr/sizeof(Tag_t)));
        uint8_t test =  i + ((currentTag->childPtr));
        char* tempName = tempTag->namePtr + str;
         
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

Tag_t* getTag(char * tagName, Tag_t* currentTag){

    /* When the requested tag name has a "." in the string (requesting a child tag) */
    if (strstr(tagName, ".") != NULL){
        char delim[] = ".";
        char *tagNamePtr = strtok(strdup(tagName), delim);
        return parseTag(tagNamePtr, delim, currentTag);     
    }
    else {
        return parseTag(tagName, "", currentTag);
    }
}

float* getValue(Tag_t* tag){
    return data + tag->valuePtr;
}

void setValue(Tag_t* tag, float* value){
    memcpy((data + tag->valuePtr), value, tag->valueSize);
}

int main(void){
    Tag_t* test = getTag("Bins[5]", tree);
    float* test2 = getValue(test);
}