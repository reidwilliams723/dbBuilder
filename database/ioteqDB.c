
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
                #include "ioteqDBFunctions.h"
        
const char str[] = {0x74, 0x61, 0x67, 0x73, 0x0, 0x53, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x73, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x39, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x39, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x30, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x31, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x32, 0x5d, 0x0, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x5b, 0x33, 0x5d, 0x0, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x44, 0x61, 0x74, 0x61, 0x0, 0x4d, 0x65, 0x6d, 0x73, 0x0, 0x4d, 0x65, 0x6d, 0x73, 0x52, 0x4d, 0x53, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x44, 0x69, 0x73, 0x63, 0x68, 0x61, 0x72, 0x67, 0x65, 0x52, 0x4d, 0x53, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x75, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x4d, 0x53, 0x0, 0x46, 0x61, 0x75, 0x6c, 0x74, 0x46, 0x6c, 0x61, 0x67, 0x0, 0x47, 0x50, 0x53, 0x44, 0x61, 0x74, 0x61, 0x0, 0x4c, 0x6f, 0x6e, 0x67, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x4c, 0x61, 0x74, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x53, 0x61, 0x74, 0x65, 0x6c, 0x6c, 0x69, 0x74, 0x65, 0x73, 0x0, 0x4d, 0x69, 0x6e, 0x53, 0x4e, 0x52, 0x0, 0x4d, 0x61, 0x78, 0x53, 0x4e, 0x52, 0x0, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x49, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x42, 0x6f, 0x6f, 0x74, 0x6c, 0x6f, 0x61, 0x64, 0x65, 0x72, 0x0, 0x46, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65, 0x0};

const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = {0x0, 0x0, 0x0, 0x0, 0x4, 0x0, 0x2c, 0x0, 0x0, 0x25, 0x0, 0x0, 0x4, 0x0, 0x5, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x4, 0x4, 0x4, 0xd, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0x8, 0x4, 0x0, 0x15, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc, 0x4, 0x0, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x4, 0x0, 0x25, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x14, 0x4, 0x0, 0x2d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x18, 0x4, 0x0, 0x35, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1c, 0x4, 0x0, 0x3d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x20, 0x4, 0x0, 0x45, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x24, 0x4, 0x0, 0x4d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x28, 0x4, 0x0, 0x55, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2c, 0x4, 0x0, 0x5d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30, 0x4, 0x0, 0x65, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x34, 0x4, 0x0, 0x6e, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x38, 0x4, 0x0, 0x77, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3c, 0x4, 0x0, 0x80, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x40, 0x4, 0x0, 0x89, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x44, 0x4, 0x0, 0x92, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x48, 0x4, 0x0, 0x9b, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4c, 0x4, 0x0, 0xa4, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x50, 0x4, 0x0, 0xad, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x54, 0x4, 0x0, 0xb6, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x58, 0x4, 0x0, 0xbf, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5c, 0x4, 0x0, 0xd1, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x60, 0x4, 0x0, 0xe3, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x64, 0x4, 0x0, 0xf5, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x68, 0x4, 0x0, 0x107, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6c, 0x4, 0x0, 0x119, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70, 0x4, 0x0, 0x128, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x74, 0x4, 0x0, 0x137, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x4, 0x0, 0x146, 0xf, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x155, 0x12, 0x0, 0x688, 0x0, 0x0, 0x2, 0x0, 0x0, 0x0, 0x0, 0x174, 0x12, 0x0, 0x6e0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x1ee, 0x10, 0x0, 0x7e8, 0x0, 0x0, 0x6, 0x0, 0xb4, 0x4, 0x0, 0x25a, 0xa, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x264, 0x8, 0x0, 0x8f0, 0x0, 0x0, 0x5, 0x0, 0x0, 0x0, 0x0, 0x298, 0x12, 0x0, 0x9cc, 0x0, 0x0, 0x2, 0x0, 0x7c, 0x4, 0x0, 0x167, 0x5, 0x580, 0x0, 0x0, 0x6b4, 0x0, 0x0, 0x80, 0x4, 0x0, 0x16c, 0x8, 0x580, 0x0, 0x688, 0x0, 0x0, 0x0, 0x84, 0x4, 0x8, 0x186, 0x11, 0x5ac, 0x0, 0x0, 0x70c, 0x0, 0x1, 0x88, 0x4, 0xc, 0x197, 0x12, 0x5ac, 0x0, 0x6e0, 0x738, 0x0, 0x1, 0x8c, 0x4, 0x10, 0x1a9, 0x14, 0x5ac, 0x0, 0x70c, 0x764, 0x0, 0x1, 0x90, 0x4, 0x0, 0x1bd, 0x12, 0x5ac, 0x0, 0x738, 0x790, 0x0, 0x0, 0x94, 0x4, 0x0, 0x1cf, 0x12, 0x5ac, 0x0, 0x764, 0x7bc, 0x0, 0x0, 0x98, 0x4, 0x0, 0x1e1, 0xd, 0x5ac, 0x0, 0x790, 0x0, 0x0, 0x0, 0x9c, 0x4, 0x14, 0x1fe, 0xf, 0x5d8, 0x0, 0x0, 0x814, 0x0, 0x1, 0xa0, 0x4, 0x18, 0x20d, 0x10, 0x5d8, 0x0, 0x7e8, 0x840, 0x0, 0x1, 0xa4, 0x4, 0x1c, 0x21d, 0x12, 0x5d8, 0x0, 0x814, 0x86c, 0x0, 0x1, 0xa8, 0x4, 0x0, 0x22f, 0x10, 0x5d8, 0x0, 0x840, 0x898, 0x0, 0x0, 0xac, 0x4, 0x0, 0x23f, 0x10, 0x5d8, 0x0, 0x86c, 0x8c4, 0x0, 0x0, 0xb0, 0x4, 0x0, 0x24f, 0xb, 0x5d8, 0x0, 0x898, 0x0, 0x0, 0x0, 0xb8, 0x4, 0x0, 0x26c, 0xa, 0x630, 0x0, 0x0, 0x91c, 0x0, 0x0, 0xbc, 0x4, 0x0, 0x276, 0x9, 0x630, 0x0, 0x8f0, 0x948, 0x0, 0x0, 0xc0, 0x4, 0x0, 0x27f, 0xb, 0x630, 0x0, 0x91c, 0x974, 0x0, 0x0, 0xc4, 0x4, 0x0, 0x28a, 0x7, 0x630, 0x0, 0x948, 0x9a0, 0x0, 0x0, 0xc8, 0x4, 0x0, 0x291, 0x7, 0x630, 0x0, 0x974, 0x0, 0x0, 0x0, 0xcc, 0x4, 0x0, 0x2aa, 0xb, 0x65c, 0x0, 0x0, 0x9f8, 0x0, 0x0, 0xd0, 0x4, 0x0, 0x2b5, 0x9, 0x65c, 0x0, 0x9cc, 0x0, 0x0, 0x0};

uint8_t data[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};


        /**
            *
            * initDB
            *
            * @param address	Persistent Memory Address
            *
            * Initializes all database tags and sets the persistent data address to use
            * in memory.
            *
            **/
            void initDB(volatile uint32_t* address){Strokes = getTag("Strokes");
RunTime = getTag("RunTime");
AccelerometerData = getTag("AccelerometerData");
Mems = getTag("AccelerometerData.Mems");
MemsRMS = getTag("AccelerometerData.MemsRMS");
DischargePressure = getTag("DischargePressure");
DischargeRawZero = getTag("DischargePressure.DischargeRawZero");
DischargeRawScale = getTag("DischargePressure.DischargeRawScale");
DischargeUnitsScale = getTag("DischargePressure.DischargeUnitsScale");
DischargeRawValue = getTag("DischargePressure.DischargeRawValue");
DischargePSIValue = getTag("DischargePressure.DischargePSIValue");
DischargeRMS = getTag("DischargePressure.DischargeRMS");
SuctionPressure = getTag("SuctionPressure");
SuctionRawZero = getTag("SuctionPressure.SuctionRawZero");
SuctionRawScale = getTag("SuctionPressure.SuctionRawScale");
SuctionUnitsScale = getTag("SuctionPressure.SuctionUnitsScale");
SuctionRawValue = getTag("SuctionPressure.SuctionRawValue");
SuctionPSIValue = getTag("SuctionPressure.SuctionPSIValue");
SuctionRMS = getTag("SuctionPressure.SuctionRMS");
FaultFlag = getTag("FaultFlag");
GPSData = getTag("GPSData");
Longitude = getTag("GPSData.Longitude");
Latitude = getTag("GPSData.Latitude");
Satellites = getTag("GPSData.Satellites");
MinSNR = getTag("GPSData.MinSNR");
MaxSNR = getTag("GPSData.MaxSNR");
SystemInformation = getTag("SystemInformation");
Bootloader = getTag("SystemInformation.Bootloader");
Firmware = getTag("SystemInformation.Firmware");
for(int i = 0; i < sizeof(Bins)/sizeof(Tag_t); i++){
                    			char BinsTag[8];
                                char strIndex[4] = "";
                                sprintf(strIndex, "%d", i);
                                strcpy(BinsTag, "Bins[");
                                strcat(BinsTag, strIndex);
                                strcat(BinsTag,"]");
                                memcpy(Bins+i, getTag(BinsTag), sizeof(Tag_t));
            }for(int i = 0; i < sizeof(CalculatedBins)/sizeof(Tag_t); i++){
                    			char CalculatedBinsTag[18];
                                char strIndex[4] = "";
                                sprintf(strIndex, "%d", i);
                                strcpy(CalculatedBinsTag, "CalculatedBins[");
                                strcat(CalculatedBinsTag, strIndex);
                                strcat(CalculatedBinsTag,"]");
                                memcpy(CalculatedBins+i, getTag(CalculatedBinsTag), sizeof(Tag_t));
            }for(int i = 0; i < sizeof(Temperature)/sizeof(Tag_t); i++){
                    			char TemperatureTag[15];
                                char strIndex[4] = "";
                                sprintf(strIndex, "%d", i);
                                strcpy(TemperatureTag, "Temperature[");
                                strcat(TemperatureTag, strIndex);
                                strcat(TemperatureTag,"]");
                                memcpy(Temperature+i, getTag(TemperatureTag), sizeof(Tag_t));
            }persistentData = address;
        /* If memory CHECK_SUM does not match, set persistent tags to default values */
        if(*persistentData != CHECK_SUM){
uint8_t* StrokesDefault = getValue(Strokes);
uint8_t* RunTimeDefault = getValue(RunTime);
uint8_t* DischargeRawZeroDefault = getValue(DischargeRawZero);
uint8_t* DischargeRawScaleDefault = getValue(DischargeRawScale);
uint8_t* DischargeUnitsScaleDefault = getValue(DischargeUnitsScale);
uint8_t* SuctionRawZeroDefault = getValue(SuctionRawZero);
uint8_t* SuctionRawScaleDefault = getValue(SuctionRawScale);
uint8_t* SuctionUnitsScaleDefault = getValue(SuctionUnitsScale);
/* Set CHECK_SUM to memory address */
*persistentData = CHECK_SUM;
setValue(Strokes, StrokesDefault);
setValue(RunTime, RunTimeDefault);
setValue(DischargeRawZero, DischargeRawZeroDefault);
setValue(DischargeRawScale, DischargeRawScaleDefault);
setValue(DischargeUnitsScale, DischargeUnitsScaleDefault);
setValue(SuctionRawZero, SuctionRawZeroDefault);
setValue(SuctionRawScale, SuctionRawScaleDefault);
setValue(SuctionUnitsScale, SuctionUnitsScaleDefault);
}
}
        /**
            *
            * setToDefault
            *
            *
            * Sets all persistent tags back to default values.
            *
            **/
            void setToDefault(){setValue(Strokes, (uint8_t*)getDefaultValue(Strokes));
setValue(RunTime, (uint8_t*)getDefaultValue(RunTime));
setValue(DischargeRawZero, (uint8_t*)getDefaultValue(DischargeRawZero));
setValue(DischargeRawScale, (uint8_t*)getDefaultValue(DischargeRawScale));
setValue(DischargeUnitsScale, (uint8_t*)getDefaultValue(DischargeUnitsScale));
setValue(SuctionRawZero, (uint8_t*)getDefaultValue(SuctionRawZero));
setValue(SuctionRawScale, (uint8_t*)getDefaultValue(SuctionRawScale));
setValue(SuctionUnitsScale, (uint8_t*)getDefaultValue(SuctionUnitsScale));
}