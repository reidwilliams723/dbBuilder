
                /**************************************************************************
                *
                * Tag Database Data
                *
                **************************************************************************
                *
                * This file was automatically generated and includes the data that makes
                * up a tag database. The database was generated using a JSON configuration file.
                *
                * (c) 2019, IOT-eq LLC, All Rights Reserved
                * Programmed By: 	Reid Williams
                * 					Inaki Zuloaga
                *
                * Date: July 26, 2019
                * Contact: izi@iot-eq.com
                *
                *
                *
                *
                *
                **************************************************************************
                */

                #ifndef IOTEQDB_H_
                #define IOTEQDB_H_
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>

                #define TOTAL_NUMBER_OF_TAGS          47

                typedef struct Tag {
                    uint32_t valuePtr;
                    uint32_t valueSize;
                    uint32_t namePtr;
                    uint32_t nameSize;
                    uint32_t parentPtr;
                    uint32_t childPtr;
                    uint32_t numOfChildren;
                } Tag_t;

        extern const char str[];
extern const Tag_t tree[TOTAL_NUMBER_OF_TAGS];
extern uint8_t data[];
#endif