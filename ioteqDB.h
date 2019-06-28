
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>

                #define TOTAL_NUMBER_OF_TAGS          5

                typedef struct Tag {
                    uint32_t valuePtr;
                    uint32_t valueSize;
                    uint32_t namePtr;
                    uint32_t nameSize;
                    uint32_t parentPtr;
                    uint32_t childPtr;
                    uint32_t numOfChildren;
                } Tag_t;

        const Tag_t* DeviceName;
const Tag_t* Temperature;
const Tag_t* ManufacturerData;
const Tag_t* Flags;
