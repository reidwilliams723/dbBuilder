#include "ioteqDB.h"

const Tag_t* parseTag(char* strTest, char delim[], const Tag_t* currentTag);
const Tag_t* getTag(char * tagName);
float* getValue(const Tag_t* tag);
float* getChildrenValues(const Tag_t* tag, float* dataArray, uint8_t* index);
void setValue(const Tag_t* tag, uint8_t* value);
uint8_t getTagSize(const Tag_t* tag, uint8_t size);