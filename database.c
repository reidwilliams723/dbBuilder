
                #include <stdio.h>
                #include <stdlib.h>
                #include <string.h>
                
                    #define TOTAL_NUMBER_OF_TAGS          33
                    typedef struct Tag {
            uint32_t valuePtr;
            uint32_t valueSize;
            uint32_t namePtr;
            uint32_t nameSize;
            uint32_t parentPtr;
            uint32_t childPtr;
            uint32_t numOfChildren;
        } Tag_t;const char str[] = {0x74, 0x61, 0x67, 0x73, 0x0, 0x53, 0x74, 0x72, 0x6f, 0x6b, 0x65, 0x73, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x39, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x30, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x31, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x32, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x33, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x34, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x35, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x36, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x37, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x38, 0x5d, 0x0, 0x42, 0x69, 0x6e, 0x73, 0x5b, 0x31, 0x39, 0x5d, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x0, 0x52, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x46, 0x6f, 0x6c, 0x64, 0x65, 0x72, 0x0, 0x72, 0x75, 0x6e, 0x54, 0x69, 0x6d, 0x65, 0x43, 0x68, 0x69, 0x6c, 0x64, 0x0, 0x50, 0x53, 0x49, 0x53, 0x63, 0x61, 0x6c, 0x69, 0x6e, 0x67, 0x0, 0x72, 0x61, 0x77, 0x41, 0x74, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x72, 0x61, 0x77, 0x41, 0x74, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x0, 0x75, 0x6e, 0x69, 0x74, 0x73, 0x5a, 0x65, 0x72, 0x6f, 0x0, 0x54, 0x65, 0x73, 0x74, 0x0, 0x75, 0x6e, 0x69, 0x74, 0x73, 0x53, 0x63, 0x61, 0x6c, 0x65, 0x64, 0x0, 0x72, 0x61, 0x77, 0x50, 0x53, 0x49, 0x0, 0x73, 0x63, 0x61, 0x6c, 0x65, 0x64, 0x50, 0x53, 0x49, 0x0};

const Tag_t tree[TOTAL_NUMBER_OF_TAGS] = {0x0, 0x0, 0x0, 0x4, 0x0, 0x1c, 0x18, 0x0, 0x0, 0x5, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xd, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x15, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x25, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x35, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x45, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4d, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x55, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5d, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x66, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x78, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x81, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8a, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x93, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9c, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa5, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0x9, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb7, 0x8, 0x0, 0x0, 0x0, 0x0, 0x0, 0xbf, 0xe, 0x0, 0x2bc, 0x1, 0x0, 0x0, 0xcd, 0xd, 0x284, 0x0, 0x0, 0x0, 0x0, 0xda, 0xb, 0x0, 0x2d8, 0x6, 0x0, 0x0, 0xe5, 0xa, 0x2a0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xb, 0x2a0, 0x0, 0x0, 0x0, 0x0, 0xfa, 0xa, 0x2a0, 0x380, 0x1, 0x0, 0x0, 0x104, 0x5, 0x310, 0x0, 0x0, 0x0, 0x0, 0x109, 0xc, 0x2a0, 0x0, 0x0, 0x0, 0x0, 0x115, 0x7, 0x2a0, 0x0, 0x0, 0x0, 0x0, 0x11c, 0xa, 0x2a0, 0x0, 0x0};

