
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
        
const char str[] = {0x74, 0x61, 0x67, 0x73, 0x0, 0x53, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x73, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x39, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x39, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x30, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x31, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x32, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x33, 0x5d, 0x0, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x44, 0x61, 0x74, 0x61, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x4d, 0x53, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x4d, 0x53, 0x0, 0x46, 0x61, 0x75, 0x6c, 0x74, 0x46, 0x6c, 0x61, 0x67, 0x0, 0x47, 0x50, 0x53, 0x44, 0x61, 0x74, 0x61, 0x0, 0x4c, 0x6f, 0x6e, 0x67, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x4c, 0x61, 0x74, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x53, 0x61, 0x74, 0x65, 0x6c, 0x6c, 0x69, 0x74, 0x65, 0x73, 0x0, 0x4d, 0x69, 0x6e, 0x53, 0x4e, 0x52, 0x0, 0x4d, 0x61, 0x78, 0x53, 0x4e, 0x52, 0x0, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x49, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x42, 0x6f, 0x6f, 0x74, 0x6c, 0x6f, 0x61, 0x64, 0x65, 0x72, 0x0, 0x46, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65, 0x0};

const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = {0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x2c, 0x0, 0x0, 0x25, 0x0, 0x0, 0x4, 0x0, 0x5, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x4, 0x4, 0x4, 0xd, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x8, 0x4, 0x0, 0x15, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0x4, 0x0, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x4, 0x0, 0x25, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0x4, 0x0, 0x2d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x4, 0x0, 0x35, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x4, 0x0, 0x3d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x4, 0x0, 0x45, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x4, 0x0, 0x4d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x28, 0x4, 0x0, 0x55, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c, 0x4, 0x0, 0x5d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x4, 0x0, 0x65, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x4, 0x0, 0x6e, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x4, 0x0, 0x77, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0x4, 0x0, 0x80, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x4, 0x0, 0x89, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0x4, 0x0, 0x92, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x48, 0x4, 0x0, 0x9b, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x4, 0x0, 0xa4, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x4, 0x0, 0xad, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x54, 0x4, 0x0, 0xb6, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x58, 0x4, 0x0, 0xbf, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5c, 0x4, 0x0, 0xd1, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x4, 0x0, 0xe3, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x4, 0x0, 0xf5, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x4, 0x0, 0x107, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x4, 0x0, 0x119, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x4, 0x0, 0x128, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x4, 0x0, 0x137, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x4, 0x0, 0x146, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c, 0x4, 0x0, 0x155, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x167, 0x12, 0x0, 0x688, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x1e1, 0x10, 0x0, 0x790, 0x0, 0x0, 0x6, 0x0, 0xb0, 0x4, 0x0, 0x24d, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x257, 0x8, 0x0, 0x898, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x28b, 0x12, 0x0, 0x974, 0x0, 0x0, 0x2, 0x0, 0x80, 0x4, 0x8, 0x179, 0x11, 0x5ac, 0x0, 0x0, 0x6b4, 0x0, 0x1, 0x84, 0x4, 0xc, 0x18a, 0x12, 0x5ac, 0x0, 0x688, 0x6e0, 0x0, 0x1, 0x88, 0x4, 0x10, 0x19c, 0x14, 0x5ac, 0x0, 0x6b4, 0x70c, 0x0, 0x1, 0x8c, 0x4, 0x0, 0x1b0, 0x12, 0x5ac, 0x0, 0x6e0, 0x738, 0x0, 0x0, 0x90, 0x4, 0x0, 0x1c2, 0x12, 0x5ac, 0x0, 0x70c, 0x764, 0x0, 0x0, 0x94, 0x4, 0x0, 0x1d4, 0xd, 0x5ac, 0x0, 0x738, 0x0, 0x0, 0x0, 0x98, 0x4, 0x14, 0x1f1, 0xf, 0x5d8, 0x0, 0x0, 0x7bc, 0x0, 0x1, 0x9c, 0x4, 0x18, 0x200, 0x10, 0x5d8, 0x0, 0x790, 0x7e8, 0x0, 0x1, 0xa0, 0x4, 0x1c, 0x210, 0x12, 0x5d8, 0x0, 0x7bc, 0x814, 0x0, 0x1, 0xa4, 0x4, 0x0, 0x222, 0x10, 0x5d8, 0x0, 0x7e8, 0x840, 0x0, 0x0, 0xa8, 0x4, 0x0, 0x232, 0x10, 0x5d8, 0x0, 0x814, 0x86c, 0x0, 0x0, 0xac, 0x4, 0x0, 0x242, 0xb, 0x5d8, 0x0, 0x840, 0x0, 0x0, 0x0, 0xb4, 0x4, 0x0, 0x25f, 0xa, 0x630, 0x0, 0x0, 0x8c4, 0x0, 0x0, 0xb8, 0x4, 0x0, 0x269, 0x9, 0x630, 0x0, 0x898, 0x8f0, 0x0, 0x0, 0xbc, 0x4, 0x0, 0x272, 0xb, 0x630, 0x0, 0x8c4, 0x91c, 0x0, 0x0, 0xc0, 0x4, 0x0, 0x27d, 0x7, 0x630, 0x0, 0x8f0, 0x948, 0x0, 0x0, 0xc4, 0x4, 0x0, 0x284, 0x7, 0x630, 0x0, 0x91c, 0x0, 0x0, 0x0, 0xc8, 0x4, 0x0, 0x29d, 0xb, 0x65c, 0x0, 0x0, 0x9a0, 0x0, 0x0, 0xcc, 0x4, 0x0, 0x2a8, 0x9, 0x65c, 0x0, 0x974, 0x0, 0x0, 0x0};

uint8_t data[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x63, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

uint8_t* getValue(const Tag_t* tag);

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

void setValue(const Tag_t* tag, uint8_t* value){

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


int main(void){
    // uint32_t* memory;
    // uint32_t test = 0;
    // memory = &test;
    // float testValue = 1234;
    // persistentData = memory;
    // DischargePressure = getTag("DischargePressure");
    // DischargeRawScale = getTag("DischargePressure.DischargeRawScale");
    // float* test123 = (float*)getValue(DischargePressure);

    // float* test3 = test123+2;
    // float* floatPtr = (float*)getValue(DischargeRawScale);
    float testValue = 1234;
    const Tag_t* SuctionRawZero = getTag("SuctionRawZero");
    const Tag_t* SuctionPressure = getTag("SuctionPressure");
    setValue(SuctionRawZero, (uint8_t*)&testValue);
    float* test = (float*)getValue(SuctionPressure);
}