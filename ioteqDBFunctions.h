#include "ioteqDB.h"

const Tag_t* parseTag(char* strTest, char delim[], const Tag_t* currentTag);
const Tag_t* getTag(char * tagName);
uint8_t* getValue(const Tag_t* tag);
void setValue(const Tag_t* tag, uint8_t* value);