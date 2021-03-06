#include <Arduino.h>

/* byte arrays that contain various Z80 programs */


const byte ipl[] = {
0x31, 0x00, 0x10, 0xCD, 0x35, 0x20, 0x06, 0x31,
0x11, 0x02, 0x00, 0x21, 0x00, 0xDC, 0x7A, 0xD3, // second byte was 01, i think should be 02
0x10, 0x7B, 0xD3, 0x12, 0x7D, 0xD3, 0x14, 0x7C,
0xD3, 0x15, 0x3E, 0x01, 0xD3, 0x16, 0xC5, 0x01,
0x80, 0x00, 0x09, 0xC1, 0x1C, 0x7B, 0xFE, 0x1A,
0xC2, 0x2E, 0x20, 0x14, 0x1E, 0x00, 0x05, 0xC2,
0x0E, 0x20, 0xC3, 0x00, 0xF2, 0x3E, 0x49, 0xD3,
0x02, 0x3E, 0x50, 0xD3, 0x02, 0x3E, 0x4C, 0xD3,
0x02, 0x3E, 0x0D, 0xD3, 0x02, 0x3E, 0x0A, 0xD3,
0x02, 0xC9
};

const byte opcodetest[] = {
0x3E, 0x01, 0xFE, 0x02, 0xCA, 0x00, 0x00, 0xFE, 0x01, 0xC2, 0x00, 0x00, 0xC3, 0x11, 0x01, 0x76, // 10f
0xFF, 0xCD, 0x17, 0x01, 0xC3, 0x00, 0x00, 0xE1, 0x7C, 0xFE, 0x01, 0xCA, 0x21, 0x01, 0xC3, 0x00, // 11f
0x00, 0x7D, 0xFE, 0x14, 0xCA, 0x2A, 0x01, 0xC3, 0x00, 0x00, 0x31, 0xAC, 0x04, 0xF1, 0xC1, 0xD1, // 12f
0xE1, 0x08, 0xD9, 0xF1, 0xC1, 0xD1, 0xE1, 0xDD, 0xE1, 0xFD, 0xE1, 0x31, 0xD4, 0x04, 0xFD, 0xE5, // 13f
0xDD, 0xE5, 0xE5, 0xD5, 0xC5, 0xF5, 0x08, 0xD9, 0xE5, 0xD5, 0xC5, 0xF5, 0x3A, 0xC0, 0x04, 0xFE, // 14f
0x02, 0xC2, 0x00, 0x00, 0x3A, 0xC1, 0x04, 0xFE, 0x04, 0xC2, 0x00, 0x00, 0x3A, 0xC2, 0x04, 0xFE, // 15f
0x06, 0xC2, 0x00, 0x00, 0x3A, 0xC3, 0x04, 0xFE, 0x08, 0xC2, 0x00, 0x00, 0x3A, 0xC4, 0x04, 0xFE, // 16f
0x0A, 0xC2, 0x00, 0x00, 0x3A, 0xC5, 0x04, 0xFE, 0x0C, 0xC2, 0x00, 0x00, 0x3A, 0xC6, 0x04, 0xFE, // 17f
0x0E, 0xC2, 0x00, 0x00, 0x3A, 0xC7, 0x04, 0xFE, 0x10, 0xC2, 0x00, 0x00, 0x3A, 0xC8, 0x04, 0xFE, // 18f
0x12, 0xC2, 0x00, 0x00, 0x3A, 0xC9, 0x04, 0xFE, 0x14, 0xC2, 0x00, 0x00, 0x3A, 0xCA, 0x04, 0xFE, // 19f
0x16, 0xC2, 0x00, 0x00, 0x3A, 0xCB, 0x04, 0xFE, 0x18, 0xC2, 0x00, 0x00, 0x3A, 0xCC, 0x04, 0xFE, // 1af
0x1A, 0xC2, 0x00, 0x00, 0x3A, 0xCD, 0x04, 0xFE, 0x1C, 0xC2, 0x00, 0x00, 0x3A, 0xCE, 0x04, 0xFE, // 1bf
0x1E, 0xC2, 0x00, 0x00, 0x3A, 0xCF, 0x04, 0xFE, 0x20, 0xC2, 0x00, 0x00, 0x3A, 0xD0, 0x04, 0xFE, // 1cf
0x22, 0xC2, 0x00, 0x00, 0x3A, 0xD1, 0x04, 0xFE, 0x24, 0xC2, 0x00, 0x00, 0x3A, 0xD2, 0x04, 0xFE, // 1df
0x26, 0xC2, 0x00, 0x00, 0x3A, 0xD3, 0x04, 0xFE, 0x28, 0xC2, 0x00, 0x00, 0x21, 0xD4, 0x04, 0x7E, // 1ef
0xFE, 0xA5, 0xC2, 0x00, 0x00, 0x21, 0xD5, 0x04, 0x7E, 0xFE, 0x3C, 0xC2, 0x00, 0x00, 0x31, 0x00, // 1ff
0x06, 0x21, 0x09, 0x02, 0xE5, 0xC9, 0xC3, 0x00, 0x00, 0x3E, 0xFF, 0xE6, 0x0F, 0xFE, 0x0F, 0xC2, // 20f
0x00, 0x00, 0x3E, 0x5A, 0xE6, 0x0F, 0xFE, 0x0A, 0xC2, 0x00, 0x00, 0x0F, 0xFE, 0x05, 0xC2, 0x00, // 21f
0x00, 0x0F, 0xFE, 0x82, 0xC2, 0x00, 0x00, 0x0F, 0xFE, 0x41, 0xC2, 0x00, 0x00, 0x0F, 0xFE, 0xA0, // 22f
0xC2, 0x00, 0x00, 0x21, 0x34, 0x12, 0xE5, 0xC1, 0x78, 0xFE, 0x12, 0xC2, 0x00, 0x00, 0x79, 0xFE, // 23f
0x34, 0xC2, 0x00, 0x00, 0x21, 0x01, 0x00, 0xE5, 0xF1, 0xDC, 0x4F, 0x02, 0xC3, 0x65, 0x04, 0xE1, // 24f
0x21, 0xD6, 0x00, 0xE5, 0xF1, 0xD4, 0x5B, 0x02, 0xC3, 0x65, 0x04, 0xE1, 0x21, 0x69, 0x02, 0xE5, // 25f
0x21, 0x01, 0x00, 0xE5, 0xF1, 0xD8, 0xCD, 0x65, 0x04, 0x21, 0x76, 0x02, 0xE5, 0x21, 0xD6, 0x00, // 26f
0xE5, 0xF1, 0xD0, 0xCD, 0x65, 0x04, 0x21, 0x01, 0x00, 0xE5, 0xF1, 0xDA, 0x81, 0x02, 0xCD, 0x65, // 27f
0x04, 0x21, 0xD6, 0x00, 0xE5, 0xF1, 0xD2, 0x8C, 0x02, 0xCD, 0x65, 0x04, 0x21, 0x01, 0x00, 0xE5, // 28f
0xF1, 0x38, 0x03, 0xCD, 0x65, 0x04, 0x21, 0xD6, 0x00, 0xE5, 0xF1, 0x30, 0x03, 0xCD, 0x65, 0x04, // 29f
0x21, 0x04, 0x00, 0xE5, 0xF1, 0xEC, 0xAB, 0x02, 0xC3, 0x65, 0x04, 0xE1, 0x21, 0xD3, 0x00, 0xE5, // 2af
0xF1, 0xE4, 0xB7, 0x02, 0xC3, 0x65, 0x04, 0xE1, 0x21, 0xC5, 0x02, 0xE5, 0x21, 0x04, 0x00, 0xE5, // 2bf
0xF1, 0xE8, 0xCD, 0x65, 0x04, 0x21, 0xD2, 0x02, 0xE5, 0x21, 0xD3, 0x00, 0xE5, 0xF1, 0xE0, 0xCD, // 2cf
0x65, 0x04, 0x21, 0x04, 0x00, 0xE5, 0xF1, 0xEA, 0xDD, 0x02, 0xCD, 0x65, 0x04, 0x21, 0xD3, 0x00, // 2df
0xE5, 0xF1, 0xE2, 0xE8, 0x02, 0xCD, 0x65, 0x04, 0x21, 0x40, 0x00, 0xE5, 0xF1, 0xCC, 0xF3, 0x02, // 2ef
0xC3, 0x65, 0x04, 0xE1, 0x21, 0x97, 0x00, 0xE5, 0xF1, 0xC4, 0xFF, 0x02, 0xC3, 0x65, 0x04, 0xE1, // 2ff
0x21, 0x0D, 0x03, 0xE5, 0x21, 0x40, 0x00, 0xE5, 0xF1, 0xC8, 0xCD, 0x65, 0x04, 0x21, 0x1A, 0x03, // 30f
0xE5, 0x21, 0x97, 0x00, 0xE5, 0xF1, 0xC0, 0xCD, 0x65, 0x04, 0x21, 0x40, 0x00, 0xE5, 0xF1, 0xCA,
0x25, 0x03, 0xCD, 0x65, 0x04, 0x21, 0x97, 0x00, 0xE5, 0xF1, 0xC2, 0x30, 0x03, 0xCD, 0x65, 0x04,
0x21, 0x40, 0x00, 0xE5, 0xF1, 0x28, 0x03, 0xCD, 0x65, 0x04, 0x21, 0x97, 0x00, 0xE5, 0xF1, 0x20,
0x03, 0xCD, 0x65, 0x04, 0x21, 0x80, 0x00, 0xE5, 0xF1, 0xFC, 0x4F, 0x03, 0xC3, 0x65, 0x04, 0xE1,
0x21, 0x57, 0x00, 0xE5, 0xF1, 0xF4, 0x5B, 0x03, 0xC3, 0x65, 0x04, 0xE1, 0x21, 0x69, 0x03, 0xE5,
0x21, 0x80, 0x00, 0xE5, 0xF1, 0xF8, 0xCD, 0x65, 0x04, 0x21, 0x76, 0x03, 0xE5, 0x21, 0x57, 0x00,
0xE5, 0xF1, 0xF0, 0xCD, 0x65, 0x04, 0x21, 0x80, 0x00, 0xE5, 0xF1, 0xFA, 0x81, 0x03, 0xCD, 0x65, // 37f
0x04, 0x21, 0x57, 0x00, 0xE5, 0xF1, 0xF2, 0x8C, 0x03, 0xCD, 0x65, 0x04, 0x21, 0x93, 0x03, 0xE9,
0xCD, 0x65, 0x04, 0x21, 0x9E, 0x03, 0xE5, 0xDD, 0xE1, 0xDD, 0xE9, 0xCD, 0x65, 0x04, 0x21, 0xA9,
0x03, 0xE5, 0xFD, 0xE1, 0xFD, 0xE9, 0xCD, 0x65, 0x04, 0x3E, 0xA5, 0x06, 0x04, 0x0F, 0x10, 0xFD,
0xFE, 0x5A, 0xC4, 0x65, 0x04, 0x06, 0x10, 0x3C, 0x10, 0xFD, 0xFE, 0x6A, 0xC4, 0x65, 0x04, 0x06,
0x00, 0x21, 0x00, 0x00, 0x23, 0x10, 0xFD, 0x7C, 0xFE, 0x01, 0xC4, 0x65, 0x04, 0x7D, 0xFE, 0x00, // 3cf
0xC4, 0x65, 0x04, 0xDD, 0x21, 0xD4, 0x04, 0xDD, 0x7E, 0x00, 0xFE, 0xA5, 0xC4, 0x65, 0x04, 0xDD,
0x7E, 0x01, 0xFE, 0x3C, 0xC4, 0x65, 0x04, 0xDD, 0x23, 0xDD, 0x7E, 0xFF, 0xFE, 0xA5, 0xC4, 0x65,
0x04, 0xDD, 0x21, 0x56, 0x04, 0xDD, 0x7E, 0x7F, 0xFE, 0x3C, 0xC4, 0x65, 0x04, 0xDD, 0x21, 0x54, // 3ff
0x05, 0xDD, 0x7E, 0x80, 0xFE, 0xA5, 0xC4, 0x65, 0x04, 0xFD, 0x21, 0xD4, 0x04, 0xFD, 0x7E, 0x00, // 40f
0xFE, 0xA5, 0xC4, 0x65, 0x04, 0xFD, 0x7E, 0x01, 0xFE, 0x3C, 0xC4, 0x65, 0x04, 0xFD, 0x23, 0xFD,
0x7E, 0xFF, 0xFE, 0xA5, 0xC4, 0x65, 0x04, 0xFD, 0x21, 0x56, 0x04, 0xFD, 0x7E, 0x7F, 0xFE, 0x3C,
0xC4, 0x65, 0x04, 0xFD, 0x21, 0x54, 0x05, 0xFD, 0x7E, 0x80, 0xFE, 0xA5, 0xC4, 0x65, 0x04, 0x11,
0x4A, 0x04, 0x0E, 0x09, 0xCD, 0x05, 0x00, 0xC3, 0x00, 0x00, 0x50, 0x72, 0x65, 0x6C, 0x69, 0x6D, // 44f
0x69, 0x6E, 0x61, 0x72, 0x79, 0x20, 0x74, 0x65, 0x73, 0x74, 0x73, 0x20, 0x63, 0x6F, 0x6D, 0x70,
0x6C, 0x65, 0x74, 0x65, 0x24, 0xC1, 0x26, 0x05, 0x78, 0x0F, 0x0F, 0x0F, 0x0F, 0xE6, 0x0F, 0x6F,
0x7E, 0xCD, 0x9D, 0x04, 0x78, 0xE6, 0x0F, 0x6F, 0x7E, 0xCD, 0x9D, 0x04, 0x79, 0x0F, 0x0F, 0x0F, // 47f
0x0F, 0xE6, 0x0F, 0x6F, 0x7E, 0xCD, 0x9D, 0x04, 0x79, 0xE6, 0x0F, 0x6F, 0x7E, 0xCD, 0x9D, 0x04,
0x3E, 0x0D, 0xCD, 0x9D, 0x04, 0x3E, 0x0A, 0xCD, 0x9D, 0x04, 0xC3, 0x00, 0x00, 0xF5, 0xC5, 0xD5,
0xE5, 0x0E, 0x02, 0x5F, 0xCD, 0x05, 0x00, 0xE1, 0xD1, 0xC1, 0xF1, 0xC9, 0x02, 0x04, 0x06, 0x08,
0x0A, 0x0C, 0x0E, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1A, 0x1C, 0x1E, 0x20, 0x22, 0x24, 0x26, 0x28,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xA5, 0x3C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 4ff
0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, // 50f
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00  // 5ff
};
