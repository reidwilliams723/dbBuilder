
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
const char str[] = {0x74, 0x61, 0x67, 0x73, 0x0, 0x53, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x73, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x39, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x39, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x30, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x31, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x32, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x33, 0x5d, 0x0, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x44, 0x61, 0x74, 0x61, 0x0, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x46, 0x61, 0x75, 0x6c, 0x74, 0x46, 0x6c, 0x61, 0x67, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x4d, 0x53, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x4d, 0x53, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x46, 0x61, 0x75, 0x6c, 0x74, 0x46, 0x6c, 0x61, 0x67, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x46, 0x61, 0x75, 0x6c, 0x74, 0x46, 0x6c, 0x61, 0x67, 0x0, 0x47, 0x50, 0x53, 0x44, 0x61, 0x74, 0x61, 0x0, 0x4c, 0x6f, 0x6e, 0x67, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x4c, 0x61, 0x74, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x53, 0x61, 0x74, 0x65, 0x6c, 0x6c, 0x69, 0x74, 0x65, 0x73, 0x0, 0x4d, 0x69, 0x6e, 0x53, 0x4e, 0x52, 0x0, 0x4d, 0x61, 0x78, 0x53, 0x4e, 0x52, 0x0, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x49, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x42, 0x6f, 0x6f, 0x74, 0x6c, 0x6f, 0x61, 0x64, 0x65, 0x72, 0x0, 0x46, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65, 0x0};

const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = {0x0, 0x0, 0x0, 0x4, 0x0, 0x24, 0x0, 0x0, 0x27, 0x0, 0x4, 0x5, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x4, 0xd, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0x4, 0x15, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0x4, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x4, 0x25, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0x4, 0x2d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x4, 0x35, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x4, 0x3d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x4, 0x45, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x4, 0x4d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x28, 0x4, 0x55, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c, 0x4, 0x5d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x4, 0x65, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x4, 0x6e, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x4, 0x77, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0x4, 0x80, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x4, 0x89, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0x4, 0x92, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x48, 0x4, 0x9b, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x4, 0xa4, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x4, 0xad, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x54, 0x4, 0xb6, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x58, 0x4, 0xbf, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5c, 0x4, 0xd1, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x4, 0xe3, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x4, 0xf5, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x4, 0x107, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x4, 0x119, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x4, 0x128, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x4, 0x137, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x4, 0x146, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c, 0x4, 0x155, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x4, 0x167, 0x17, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x17e, 0x12, 0x0, 0x5a0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x1f8, 0x10, 0x0, 0x678, 0x0, 0x0, 0x6, 0xb4, 0x4, 0x264, 0x11, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb8, 0x4, 0x275, 0x13, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x288, 0x8, 0x0, 0x750, 0x0, 0x0, 0x5, 0x0, 0x0, 0x2bc, 0x12, 0x0, 0x804, 0x0, 0x0, 0x2, 0x84, 0x4, 0x190, 0x11, 0x4c8, 0x0, 0x0, 0x5c4, 0x0, 0x88, 0x4, 0x1a1, 0x12, 0x4c8, 0x0, 0x5a0, 0x5e8, 0x0, 0x8c, 0x4, 0x1b3, 0x14, 0x4c8, 0x0, 0x5c4, 0x60c, 0x0, 0x90, 0x4, 0x1c7, 0x12, 0x4c8, 0x0, 0x5e8, 0x630, 0x0, 0x94, 0x4, 0x1d9, 0x12, 0x4c8, 0x0, 0x60c, 0x654, 0x0, 0x98, 0x4, 0x1eb, 0xd, 0x4c8, 0x0, 0x630, 0x0, 0x0, 0x9c, 0x4, 0x208, 0xf, 0x4ec, 0x0, 0x0, 0x69c, 0x0, 0xa0, 0x4, 0x217, 0x10, 0x4ec, 0x0, 0x678, 0x6c0, 0x0, 0xa4, 0x4, 0x227, 0x12, 0x4ec, 0x0, 0x69c, 0x6e4, 0x0, 0xa8, 0x4, 0x239, 0x10, 0x4ec, 0x0, 0x6c0, 0x708, 0x0, 0xac, 0x4, 0x249, 0x10, 0x4ec, 0x0, 0x6e4, 0x72c, 0x0, 0xb0, 0x4, 0x259, 0xb, 0x4ec, 0x0, 0x708, 0x0, 0x0, 0xbc, 0x4, 0x290, 0xa, 0x558, 0x0, 0x0, 0x774, 0x0, 0xc0, 0x4, 0x29a, 0x9, 0x558, 0x0, 0x750, 0x798, 0x0, 0xc4, 0x4, 0x2a3, 0xb, 0x558, 0x0, 0x774, 0x7bc, 0x0, 0xc8, 0x4, 0x2ae, 0x7, 0x558, 0x0, 0x798, 0x7e0, 0x0, 0xcc, 0x4, 0x2b5, 0x7, 0x558, 0x0, 0x7bc, 0x0, 0x0, 0xd0, 0x4, 0x2ce, 0xb, 0x57c, 0x0, 0x0, 0x828, 0x0, 0xd4, 0x4, 0x2d9, 0x9, 0x57c, 0x0, 0x804, 0x0, 0x0};

uint8_t data[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x0, 0x48, 0x43, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0xf2, 0x3, 0x42, 0x14, 0xae, 0x6f, 0x41, 0x0, 0x0, 0x80, 0x40, 0xae, 0x47, 0x83, 0x41, 0xb8, 0x1e, 0xa7, 0x41, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

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
        const Tag_t* currentChild = tree + ((tag->childPtr/sizeof(Tag_t)));

        return data + currentChild->valuePtr;
    }
    else{
        return data + tag->valuePtr;
    }
}

void setValue(const Tag_t* tag, uint8_t* value){

    if (tag->numOfChildren != 0){
        const Tag_t* child = tree + (tag->childPtr/sizeof(Tag_t));
        memcpy(data + child->valuePtr, value, getTagSize(tag, 0));
    }
    else{
        memcpy((data + tag->valuePtr), value, tag->valueSize);
    }
}


int main(void){
    const Tag_t* test = getTag("DischargePressure.DischargeRawScale");
    const Tag_t* test2 = tree + (test->nextSiblingPtr/sizeof(Tag_t));
    float* test3 = (float*)getValue(test2);
}