// Copyright 2019 Silicon Laboratories, Inc.
//
//

/********************************************************************
 * Autogenerated file, do not edit.
 *******************************************************************/

#include <stdint.h>
#include "bg_gattdb_def.h"

#ifdef __GNUC__
#define GATT_HEADER(F) F __attribute__ ((section (".gatt_header"))) 
#define GATT_DATA(F) F __attribute__ ((section (".gatt_data"))) 
#else
#ifdef __ICCARM__
#define GATT_HEADER(F) _Pragma("location=\".gatt_header\"") F 
#define GATT_DATA(F) _Pragma("location=\".gatt_data\"") F 
#else
#define GATT_HEADER(F) F 
#define GATT_DATA(F) F 
#endif
#endif

GATT_DATA(const uint16_t bg_gattdb_data_uuidtable_16_map [])=
{
    0x2800,
    0x2801,
    0x2803,
    0x1800,
    0x2a00,
    0x2a01,
    0x180a,
    0x2a29,
    0x2a24,
    0x2a23,
    0x2a6d,
    0x2a6e,
    0x2a6f,
    0x2a70,
    0x2a71,
    0x2a72,
    0x2a73,
    0x2a74,
    0x2a75,
    0x2a76,
    0x2a77,
    0x2a78,
    0x2a79,
    0x2a7a,
    0x2a7b,
    0x2a7c,
    0x2a7d,
    0x2a7e,
    0x2a7f,
    0x2a80,
    0x1801,
    0x2a05,
    0x2b2a,
    0x2b29,
    0x2902,
};

GATT_DATA(const uint8_t bg_gattdb_data_uuidtable_128_map [])=
{
0xf0, 0x19, 0x21, 0xb4, 0x47, 0x8f, 0xa4, 0xbf, 0xa1, 0x4f, 0x63, 0xfd, 0xee, 0xd6, 0x14, 0x1d, 
0x63, 0x60, 0x32, 0xe0, 0x37, 0x5e, 0xa4, 0x88, 0x53, 0x4e, 0x6d, 0xfb, 0x64, 0x35, 0xbf, 0xf7, 
0xf5, 0x0a, 0x2c, 0xd4, 0xda, 0xa6, 0xa5, 0xac, 0x6e, 0x4f, 0x26, 0xd5, 0xd2, 0x9a, 0x77, 0x83, 
0x27, 0x4b, 0x8b, 0x16, 0xab, 0x83, 0x45, 0x97, 0xd8, 0x47, 0xc5, 0xc2, 0x29, 0x07, 0x08, 0x82, 
0x79, 0xf2, 0xee, 0x7b, 0xc0, 0x4e, 0xa2, 0x9e, 0x0f, 0x43, 0xdc, 0xf4, 0x40, 0x9f, 0xaf, 0xd7, 
0xd6, 0x81, 0x93, 0x8a, 0x4a, 0x8f, 0x72, 0xa3, 0x38, 0x4c, 0xfd, 0xac, 0x50, 0x7f, 0x05, 0xc3, 
0x64, 0xf3, 0x1e, 0x80, 0xa0, 0x55, 0x84, 0xa6, 0xdc, 0x45, 0xb7, 0x8a, 0x49, 0x74, 0x37, 0xe0, 
};




GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_81 ) = {
	.properties=0x12,
	.index=29,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_80 ) = {
	.len=19,
	.data={0x12,0x52,0x00,0x64,0xf3,0x1e,0x80,0xa0,0x55,0x84,0xa6,0xdc,0x45,0xb7,0x8a,0x49,0x74,0x37,0xe0,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_78 ) = {
	.properties=0x12,
	.index=28,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_77 ) = {
	.len=19,
	.data={0x12,0x4f,0x00,0xd6,0x81,0x93,0x8a,0x4a,0x8f,0x72,0xa3,0x38,0x4c,0xfd,0xac,0x50,0x7f,0x05,0xc3,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_75 ) = {
	.properties=0x12,
	.index=27,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_74 ) = {
	.len=5,
	.data={0x12,0x4c,0x00,0x6e,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_72 ) = {
	.properties=0x12,
	.index=26,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_71 ) = {
	.len=5,
	.data={0x12,0x49,0x00,0x6f,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_70 ) = {
	.len=16,
	.data={0x79,0xf2,0xee,0x7b,0xc0,0x4e,0xa2,0x9e,0x0f,0x43,0xdc,0xf4,0x40,0x9f,0xaf,0xd7,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_69 ) = {
	.properties=0x02,
	.index=25,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_68 ) = {
	.len=5,
	.data={0x02,0x46,0x00,0x80,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_67 ) = {
	.properties=0x02,
	.index=24,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_66 ) = {
	.len=5,
	.data={0x02,0x44,0x00,0x7f,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_65 ) = {
	.properties=0x02,
	.index=23,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_64 ) = {
	.len=5,
	.data={0x02,0x42,0x00,0x7e,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_63 ) = {
	.properties=0x02,
	.index=22,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_62 ) = {
	.len=5,
	.data={0x02,0x40,0x00,0x7d,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_61 ) = {
	.properties=0x02,
	.index=21,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_60 ) = {
	.len=5,
	.data={0x02,0x3e,0x00,0x7c,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_59 ) = {
	.properties=0x02,
	.index=20,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_58 ) = {
	.len=5,
	.data={0x02,0x3c,0x00,0x7b,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_57 ) = {
	.properties=0x02,
	.index=19,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_56 ) = {
	.len=5,
	.data={0x02,0x3a,0x00,0x7a,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_55 ) = {
	.properties=0x02,
	.index=18,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_54 ) = {
	.len=5,
	.data={0x02,0x38,0x00,0x79,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_53 ) = {
	.properties=0x02,
	.index=17,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_52 ) = {
	.len=5,
	.data={0x02,0x36,0x00,0x78,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_51 ) = {
	.properties=0x02,
	.index=16,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_50 ) = {
	.len=5,
	.data={0x02,0x34,0x00,0x77,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_49 ) = {
	.properties=0x02,
	.index=15,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_48 ) = {
	.len=5,
	.data={0x02,0x32,0x00,0x76,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_47 ) = {
	.properties=0x02,
	.index=14,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_46 ) = {
	.len=5,
	.data={0x02,0x30,0x00,0x75,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_45 ) = {
	.properties=0x02,
	.index=13,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_44 ) = {
	.len=5,
	.data={0x02,0x2e,0x00,0x74,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_43 ) = {
	.properties=0x02,
	.index=12,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_42 ) = {
	.len=5,
	.data={0x02,0x2c,0x00,0x73,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_41 ) = {
	.properties=0x02,
	.index=11,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_40 ) = {
	.len=5,
	.data={0x02,0x2a,0x00,0x72,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_39 ) = {
	.properties=0x02,
	.index=10,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_38 ) = {
	.len=5,
	.data={0x02,0x28,0x00,0x71,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_36 ) = {
	.properties=0x12,
	.index=9,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_35 ) = {
	.len=5,
	.data={0x12,0x25,0x00,0x70,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_33 ) = {
	.properties=0x12,
	.index=8,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_32 ) = {
	.len=5,
	.data={0x12,0x22,0x00,0x6f,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_30 ) = {
	.properties=0x12,
	.index=7,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_29 ) = {
	.len=5,
	.data={0x12,0x1f,0x00,0x6e,0x2a,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_27 ) = {
	.properties=0x12,
	.index=6,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_26 ) = {
	.len=5,
	.data={0x12,0x1c,0x00,0x6d,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_25 ) = {
	.len=16,
	.data={0x27,0x4b,0x8b,0x16,0xab,0x83,0x45,0x97,0xd8,0x47,0xc5,0xc2,0x29,0x07,0x08,0x82,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_24 ) = {
	.properties=0x02,
	.index=5,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_23 ) = {
	.len=19,
	.data={0x02,0x19,0x00,0xf5,0x0a,0x2c,0xd4,0xda,0xa6,0xa5,0xac,0x6e,0x4f,0x26,0xd5,0xd2,0x9a,0x77,0x83,}
};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_22 ) = {
	.properties=0x08,
	.index=4,
	.max_len=0,
	.data=NULL,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_21 ) = {
	.len=19,
	.data={0x08,0x17,0x00,0x63,0x60,0x32,0xe0,0x37,0x5e,0xa4,0x88,0x53,0x4e,0x6d,0xfb,0x64,0x35,0xbf,0xf7,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_20 ) = {
	.len=16,
	.data={0xf0,0x19,0x21,0xb4,0x47,0x8f,0xa4,0xbf,0xa1,0x4f,0x63,0xfd,0xee,0xd6,0x14,0x1d,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_19 ) = {
	.len=6,
	.data={0x00,0x01,0x02,0x03,0x04,0x05,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_18 ) = {
	.len=5,
	.data={0x02,0x14,0x00,0x23,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_17 ) = {
	.len=10,
	.data={0x42,0x6c,0x75,0x65,0x20,0x47,0x65,0x63,0x6b,0x6f,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_16 ) = {
	.len=5,
	.data={0x02,0x12,0x00,0x24,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_15 ) = {
	.len=12,
	.data={0x53,0x69,0x6c,0x69,0x63,0x6f,0x6e,0x20,0x4c,0x61,0x62,0x73,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_14 ) = {
	.len=5,
	.data={0x02,0x10,0x00,0x29,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_13 ) = {
	.len=2,
	.data={0x0a,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_12 ) = {
	.len=2,
	.data={0x00,0x00,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_11 ) = {
	.len=5,
	.data={0x02,0x0d,0x00,0x01,0x2a,}
};
uint8_t bg_gattdb_data_attribute_field_10_data[9]={0x57,0x65,0x69,0x72,0x20,0x44,0x65,0x6d,0x6f,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_10 ) = {
	.properties=0x0a,
	.index=3,
	.max_len=9,
	.data=bg_gattdb_data_attribute_field_10_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_9 ) = {
	.len=5,
	.data={0x0a,0x0b,0x00,0x00,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_8 ) = {
	.len=2,
	.data={0x00,0x18,}
};
uint8_t bg_gattdb_data_attribute_field_7_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_7 ) = {
	.properties=0x0a,
	.index=2,
	.max_len=1,
	.data=bg_gattdb_data_attribute_field_7_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_6 ) = {
	.len=5,
	.data={0x0a,0x08,0x00,0x29,0x2b,}
};
uint8_t bg_gattdb_data_attribute_field_5_data[16]={0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_5 ) = {
	.properties=0x02,
	.index=1,
	.max_len=16,
	.data=bg_gattdb_data_attribute_field_5_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_4 ) = {
	.len=5,
	.data={0x02,0x06,0x00,0x2a,0x2b,}
};
uint8_t bg_gattdb_data_attribute_field_2_data[4]={0x00,0x00,0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_data_attribute_field_2 ) = {
	.properties=0x20,
	.index=0,
	.max_len=4,
	.data=bg_gattdb_data_attribute_field_2_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_1 ) = {
	.len=5,
	.data={0x20,0x03,0x00,0x05,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_data_attribute_field_0 ) = {
	.len=2,
	.data={0x01,0x18,}
};
GATT_DATA(const struct bg_gattdb_attribute bg_gattdb_data_attributes_map[])={
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_0},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_1},
    {.uuid=0x001f,.permissions=0x800,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_2},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x02,.index=0x00,.clientconfig_index=0x00}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_4},
    {.uuid=0x0020,.permissions=0x801,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_5},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_6},
    {.uuid=0x0021,.permissions=0x803,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_7},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_8},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_9},
    {.uuid=0x0004,.permissions=0x803,.caps=0xffff,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_10},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_11},
    {.uuid=0x0005,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_12},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_13},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_14},
    {.uuid=0x0007,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_15},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_16},
    {.uuid=0x0008,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_17},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_18},
    {.uuid=0x0009,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_19},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_20},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_21},
    {.uuid=0x8001,.permissions=0x802,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_22},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_23},
    {.uuid=0x8002,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_24},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_25},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_26},
    {.uuid=0x000a,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_27},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x06,.clientconfig_index=0x01}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_29},
    {.uuid=0x000b,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_30},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x07,.clientconfig_index=0x02}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_32},
    {.uuid=0x000c,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_33},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x08,.clientconfig_index=0x03}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_35},
    {.uuid=0x000d,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_36},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x09,.clientconfig_index=0x04}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_38},
    {.uuid=0x000e,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_39},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_40},
    {.uuid=0x000f,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_41},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_42},
    {.uuid=0x0010,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_43},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_44},
    {.uuid=0x0011,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_45},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_46},
    {.uuid=0x0012,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_47},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_48},
    {.uuid=0x0013,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_49},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_50},
    {.uuid=0x0014,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_51},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_52},
    {.uuid=0x0015,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_53},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_54},
    {.uuid=0x0016,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_55},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_56},
    {.uuid=0x0017,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_57},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_58},
    {.uuid=0x0018,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_59},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_60},
    {.uuid=0x0019,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_61},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_62},
    {.uuid=0x001a,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_63},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_64},
    {.uuid=0x001b,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_65},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_66},
    {.uuid=0x001c,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_67},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_68},
    {.uuid=0x001d,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_69},
    {.uuid=0x0000,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_70},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_71},
    {.uuid=0x000c,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_72},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x1a,.clientconfig_index=0x05}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_74},
    {.uuid=0x000b,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_75},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x1b,.clientconfig_index=0x06}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_77},
    {.uuid=0x8005,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_78},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x1c,.clientconfig_index=0x07}},
    {.uuid=0x0002,.permissions=0x801,.caps=0xffff,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_data_attribute_field_80},
    {.uuid=0x8006,.permissions=0x801,.caps=0xffff,.datatype=0x07,.min_key_size=0x00,.dynamicdata=&bg_gattdb_data_attribute_field_81},
    {.uuid=0x0022,.permissions=0x807,.caps=0xffff,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x1d,.clientconfig_index=0x08}},
};

GATT_DATA(const uint16_t bg_gattdb_data_attributes_dynamic_mapping_map[])={
	0x0003,
	0x0006,
	0x0008,
	0x000b,
	0x0017,
	0x0019,
	0x001c,
	0x001f,
	0x0022,
	0x0025,
	0x0028,
	0x002a,
	0x002c,
	0x002e,
	0x0030,
	0x0032,
	0x0034,
	0x0036,
	0x0038,
	0x003a,
	0x003c,
	0x003e,
	0x0040,
	0x0042,
	0x0044,
	0x0046,
	0x0049,
	0x004c,
	0x004f,
	0x0052,
};

GATT_DATA(const uint8_t bg_gattdb_data_adv_uuid16_map[])={0x0};
GATT_DATA(const uint8_t bg_gattdb_data_adv_uuid128_map[])={0x0};
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data)={
    .attributes=bg_gattdb_data_attributes_map,
    .attributes_max=83,
    .uuidtable_16_size=35,
    .uuidtable_16=bg_gattdb_data_uuidtable_16_map,
    .uuidtable_128_size=7,
    .uuidtable_128=bg_gattdb_data_uuidtable_128_map,
    .attributes_dynamic_max=30,
    .attributes_dynamic_mapping=bg_gattdb_data_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_data_adv_uuid16_map,
    .adv_uuid16_num=0,
    .adv_uuid128=bg_gattdb_data_adv_uuid128_map,
    .adv_uuid128_num=0,
    .caps_mask=0xffff,
    .enabled_caps=0xffff,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
