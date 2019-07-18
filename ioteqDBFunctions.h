#include "ioteqDB.h"

const Tag_t* parseTag(char* strTest, char delim[], const Tag_t* currentTag);
const Tag_t* getTag(char * tagName);
uint8_t* getValue(const Tag_t* tag);
uint8_t* getChildrenValues(const Tag_t* tag, char* dataArray, uint8_t* index);
void setValue(const Tag_t* tag, uint8_t* value);
uint8_t getTagSize(const Tag_t* tag, uint8_t size);