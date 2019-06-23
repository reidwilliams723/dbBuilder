#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

Tag_t* getTag(char * tagName){
    for(int i = 0; i < TOTAL_NUMBER_OF_TAGS; i++){
        Tag_t* currentTag = tree + i;
        char * name = currentTag->namePtr + str;
        if(memcmp(tagName, name, currentTag->nameSize) == 0){
            return currentTag;
        }
    }

    return NULL;
}

float* getValue(Tag_t* tag){
    return data + tag->valuePtr;
}

void setValue(Tag_t* tag, float* value){
    memcpy((data + tag->valuePtr), value, tag->valueSize);
}

int main(void){
    Tag_t* strokes = getTag("Strokes");
    // Tag_t* strokes = tree +1;
    float* x = getValue(strokes);
    float newValue = 4321.21;
    setValue(strokes, &newValue);

    float y = *getValue(strokes);
}