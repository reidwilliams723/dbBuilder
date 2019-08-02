
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                #include "ioteqDB.h"
        
const char str[] = {0x74, 0x61, 0x67, 0x73, 0x0, 0x53, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x73, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x39, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x39, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x43, 0x61, 0x6c, 0x63, 0x75, 0x6c, 0x61, 0x74, 0x65, 0x64, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x50, 0x53, 0x49, 0x44, 0x61, 0x74, 0x61, 0x0, 0x52, 0x61, 0x77, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x52, 0x61, 0x77, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x55, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x50, 0x53, 0x49, 0x52, 0x61, 0x77, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x64, 0x50, 0x53, 0x49, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, 0x47, 0x50, 0x53, 0x44, 0x61, 0x74, 0x61, 0x0, 0x4c, 0x6f, 0x6e, 0x67, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x4c, 0x61, 0x74, 0x69, 0x74, 0x75, 0x64, 0x65, 0x0, 0x53, 0x61, 0x74, 0x65, 0x6c, 0x6c, 0x69, 0x74, 0x65, 0x73, 0x0, 0x4d, 0x69, 0x6e, 0x53, 0x4e, 0x52, 0x0, 0x4d, 0x61, 0x78, 0x53, 0x4e, 0x52, 0x0, 0x41, 0x63, 0x63, 0x65, 0x6c, 0x65, 0x72, 0x6f, 0x6d, 0x65, 0x74, 0x65, 0x72, 0x44, 0x61, 0x74, 0x61, 0x0, 0x50, 0x65, 0x61, 0x6b, 0x58, 0x0, 0x50, 0x65, 0x61, 0x6b, 0x59, 0x0, 0x50, 0x65, 0x61, 0x6b, 0x5a, 0x0, 0x53, 0x79, 0x73, 0x74, 0x65, 0x6d, 0x49, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0, 0x42, 0x6f, 0x6f, 0x74, 0x6c, 0x6f, 0x61, 0x64, 0x65, 0x72, 0x0, 0x46, 0x69, 0x72, 0x6d, 0x77, 0x61, 0x72, 0x65, 0x0};

const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = {0x0, 0x0, 0x0, 0x4, 0x0, 0x1c, 0x1f, 0x0, 0x4, 0x5, 0x8, 0x0, 0x0, 0x0, 0x4, 0x4, 0xd, 0x8, 0x0, 0x0, 0x0, 0x8, 0x4, 0x15, 0x8, 0x0, 0x0, 0x0, 0xc, 0x4, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x10, 0x4, 0x25, 0x8, 0x0, 0x0, 0x0, 0x14, 0x4, 0x2d, 0x8, 0x0, 0x0, 0x0, 0x18, 0x4, 0x35, 0x8, 0x0, 0x0, 0x0, 0x1c, 0x4, 0x3d, 0x8, 0x0, 0x0, 0x0, 0x20, 0x4, 0x45, 0x8, 0x0, 0x0, 0x0, 0x24, 0x4, 0x4d, 0x8, 0x0, 0x0, 0x0, 0x28, 0x4, 0x55, 0x8, 0x0, 0x0, 0x0, 0x2c, 0x4, 0x5d, 0x8, 0x0, 0x0, 0x0, 0x30, 0x4, 0x65, 0x9, 0x0, 0x0, 0x0, 0x34, 0x4, 0x6e, 0x9, 0x0, 0x0, 0x0, 0x38, 0x4, 0x77, 0x9, 0x0, 0x0, 0x0, 0x3c, 0x4, 0x80, 0x9, 0x0, 0x0, 0x0, 0x40, 0x4, 0x89, 0x9, 0x0, 0x0, 0x0, 0x44, 0x4, 0x92, 0x9, 0x0, 0x0, 0x0, 0x48, 0x4, 0x9b, 0x9, 0x0, 0x0, 0x0, 0x4c, 0x4, 0xa4, 0x9, 0x0, 0x0, 0x0, 0x50, 0x4, 0xad, 0x9, 0x0, 0x0, 0x0, 0x54, 0x4, 0xb6, 0x9, 0x0, 0x0, 0x0, 0x58, 0x4, 0xbf, 0x12, 0x0, 0x0, 0x0, 0x5c, 0x4, 0xd1, 0x12, 0x0, 0x0, 0x0, 0x60, 0x4, 0xe3, 0x12, 0x0, 0x0, 0x0, 0x64, 0x4, 0xf5, 0x12, 0x0, 0x0, 0x0, 0x68, 0x4, 0x107, 0x12, 0x0, 0x0, 0x0, 0x0, 0x0, 0x119, 0x8, 0x0, 0x380, 0x5, 0x0, 0x0, 0x158, 0x8, 0x0, 0x40c, 0x5, 0x0, 0x0, 0x18c, 0x12, 0x0, 0x498, 0x3, 0x0, 0x0, 0x1b0, 0x12, 0x0, 0x4ec, 0x2, 0x6c, 0x4, 0x121, 0x8, 0x310, 0x0, 0x0, 0x70, 0x4, 0x129, 0x9, 0x310, 0x0, 0x0, 0x74, 0x4, 0x132, 0xb, 0x310, 0x0, 0x0, 0x78, 0x4, 0x13d, 0xc, 0x310, 0x0, 0x0, 0x7c, 0x4, 0x149, 0xf, 0x310, 0x0, 0x0, 0x80, 0x4, 0x160, 0xa, 0x32c, 0x0, 0x0, 0x84, 0x4, 0x16a, 0x9, 0x32c, 0x0, 0x0, 0x88, 0x4, 0x173, 0xb, 0x32c, 0x0, 0x0, 0x8c, 0x4, 0x17e, 0x7, 0x32c, 0x0, 0x0, 0x90, 0x4, 0x185, 0x7, 0x32c, 0x0, 0x0, 0x94, 0x4, 0x19e, 0x6, 0x348, 0x0, 0x0, 0x98, 0x4, 0x1a4, 0x6, 0x348, 0x0, 0x0, 0x9c, 0x4, 0x1aa, 0x6, 0x348, 0x0, 0x0, 0xa0, 0x4, 0x1c2, 0xb, 0x364, 0x0, 0x0, 0xa4, 0x4, 0x1cd, 0x9, 0x364, 0x0, 0x0};

uint8_t data[] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x80, 0x40, 0x0, 0x0, 0xa0, 0x41, 0x0, 0x40, 0x9c, 0x46, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb0, 0xf2, 0x3, 0x42, 0x14, 0xae, 0x6f, 0x41, 0x0, 0x0, 0x80, 0x40, 0xae, 0x47, 0x83, 0x41, 0xb8, 0x1e, 0xa7, 0x41, 0x0, 0x0, 0xf0, 0x41, 0x0, 0x0, 0x20, 0x42, 0x0, 0x0, 0x48, 0x42, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

