#include "database.h"

Tag_t* getTag(char * tagName){
    for(int i = 0; i < TOTAL_NUMBER_OF_TAGS; i++){
        if(memcmp(tagName, (tree + i)->namePtr, (tree +i)->nameSize) == 0){
            return tree + i;
        }
    }

    return NULL;
}