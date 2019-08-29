
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
                * Date: August 28, 2019
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

                #define TOTAL_NUMBER_OF_TAGS          57
                #define CHECK_SUM                     0x00A5005A
                typedef struct Tag {
                    uint32_t valuePtr;
                    uint32_t valueSize;
                    uint32_t persistentPtr;
                    uint32_t namePtr;
                    uint32_t nameSize;
                    uint32_t parentPtr;
                    uint32_t childPtr;
                    uint32_t prevSibling;
                    uint32_t nextSibling;
                    uint32_t numOfChildren;
                    uint32_t isPersistent;
                } Tag_t;

        extern const char str[];
extern const Tag_t tree[TOTAL_NUMBER_OF_TAGS];
extern uint8_t data[];

volatile uint32_t* persistentData;

void initDB();

void setToDefault();

const Tag_t* Strokes;
const Tag_t* RunTime;
const Tag_t* AccelerometerData;
const Tag_t* DischargePressure;
const Tag_t* DischargeRawZero;
const Tag_t* DischargeRawScale;
const Tag_t* DischargeUnitsScale;
const Tag_t* DischargeRawValue;
const Tag_t* DischargePSIValue;
const Tag_t* DischargeRMS;
const Tag_t* SuctionPressure;
const Tag_t* SuctionRawZero;
const Tag_t* SuctionRawScale;
const Tag_t* SuctionUnitsScale;
const Tag_t* SuctionRawValue;
const Tag_t* SuctionPSIValue;
const Tag_t* SuctionRMS;
const Tag_t* FaultFlag;
const Tag_t* GPSData;
const Tag_t* Longitude;
const Tag_t* Latitude;
const Tag_t* Satellites;
const Tag_t* MinSNR;
const Tag_t* MaxSNR;
const Tag_t* SystemInformation;
const Tag_t* Bootloader;
const Tag_t* Firmware;
const Tag_t Bins[20];
const Tag_t CalculatedBins[5];
const Tag_t Temperature[4];
#endif