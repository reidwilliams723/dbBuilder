#include "ioteqDB.h"

const Tag_t* parseTag(char* strTest, char delim[], const Tag_t* currentTag);
const Tag_t* getTag(char * tagName);
uint8_t* getValue(const Tag_t* tag);
void setValue(const Tag_t* tag, uint8_t* value);
uint8_t getTagSize(const Tag_t* tag, uint8_t size);
uint8_t* iterateChildrenValues(const Tag_t* tag, uint8_t* dataArray, uint8_t index);
uint8_t iterateChildren(const Tag_t* tag, uint8_t size);
uint8_t* getDefaultValue(const Tag_t* tag);
void setDefaultValue(const Tag_t* tag);
#ifdef PERSISTENCE_ENABLED
void savePersistentTags();
#endif