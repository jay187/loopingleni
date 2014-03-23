/*
 * Font.h
 *
 *  Created on: 20.07.2013
 *      Author: jensheidrich
 */

#ifndef FONT_H_
#define FONT_H_
// defines 8x8 ascii characters 0x20-0x7F (32-127)
PROGMEM const byte font_8x8[98][8] = { { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }, //
    { 0x00, 0x60, 0xfa, 0xfa, 0x60, 0x00, 0x00, 0x00 }, // !
    { 0x00, 0xe0, 0xe0, 0x00, 0xe0, 0xe0, 0x00, 0x00 }, // "
    { 0x28, 0xfe, 0xfe, 0x28, 0xfe, 0xfe, 0x28, 0x00 }, // #
    { 0x24, 0x74, 0xd6, 0xd6, 0x5c, 0x48, 0x00, 0x00 }, // $
    { 0x62, 0x66, 0x0c, 0x18, 0x30, 0x66, 0x46, 0x00 }, // %
    { 0x0c, 0x5e, 0xf2, 0xba, 0xec, 0x5e, 0x12, 0x00 }, // &
    { 0x20, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00 }, // '
    { 0x00, 0x38, 0x7c, 0xc6, 0x82, 0x00, 0x00, 0x00 }, // (
    { 0x00, 0x82, 0xc6, 0x7c, 0x38, 0x00, 0x00, 0x00 }, // )
    { 0x10, 0x54, 0x7c, 0x38, 0x38, 0x7c, 0x54, 0x10 }, // *
    { 0x10, 0x10, 0x7c, 0x7c, 0x10, 0x10, 0x00, 0x00 }, // +
    { 0x00, 0x05, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00 }, // ,
    { 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00 }, // -
    { 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00 }, // .
    { 0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00 }, // /
    { 0x7c, 0xfe, 0x9a, 0xb2, 0xfe, 0x7c, 0x00, 0x00 }, // 0
    { 0x42, 0x42, 0xfe, 0xfe, 0x02, 0x02, 0x00, 0x00 }, // 1
    { 0x46, 0xce, 0x9a, 0x92, 0xf6, 0x66, 0x00, 0x00 }, // 2
    { 0x44, 0xc6, 0x92, 0x92, 0xfe, 0x6c, 0x00, 0x00 }, // 3
    { 0x18, 0x38, 0x68, 0xc8, 0xfe, 0xfe, 0x08, 0x00 }, // 4
    { 0xe4, 0xe6, 0xa2, 0xa2, 0xbe, 0x9c, 0x00, 0x00 }, // 5
    { 0x3c, 0x7e, 0xd2, 0x92, 0x9e, 0x0c, 0x00, 0x00 }, // 6
    { 0xc0, 0xc6, 0x8e, 0x98, 0xf0, 0xe0, 0x00, 0x00 }, // 7
    { 0x6c, 0xfe, 0x92, 0x92, 0xfe, 0x6c, 0x00, 0x00 }, // 8
    { 0x60, 0xf2, 0x92, 0x96, 0xfc, 0x78, 0x00, 0x00 }, // 9
    { 0x00, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00 }, // :
    { 0x00, 0x05, 0x37, 0x36, 0x00, 0x00, 0x00, 0x00 }, // ;
    { 0x10, 0x38, 0x6c, 0xc6, 0x82, 0x00, 0x00, 0x00 }, // <
    { 0x28, 0x28, 0x28, 0x28, 0x28, 0x28, 0x00, 0x00 }, // =
    { 0x00, 0x82, 0xc6, 0x6c, 0x38, 0x10, 0x00, 0x00 }, // >
    { 0x40, 0xc0, 0x8a, 0x9a, 0xf0, 0x60, 0x00, 0x00 }, // ?
    { 0x7c, 0xfe, 0x82, 0xba, 0xba, 0xf8, 0x78, 0x00 }, // @
    { 0x3e, 0x7e, 0xc8, 0xc8, 0x7e, 0x3e, 0x00, 0x00 }, // A
    { 0x82, 0xfe, 0xfe, 0x92, 0x92, 0xfe, 0x6c, 0x00 }, // B
    { 0x38, 0x7c, 0xc6, 0x82, 0x82, 0xc6, 0x44, 0x00 }, // C
    { 0x82, 0xfe, 0xfe, 0x82, 0xc6, 0xfe, 0x38, 0x00 }, // D
    { 0x82, 0xfe, 0xfe, 0x92, 0xba, 0x82, 0xc6, 0x00 }, // E
    { 0x82, 0xfe, 0xfe, 0x92, 0xb8, 0x80, 0xc0, 0x00 }, // F
    { 0x38, 0x7c, 0xc6, 0x82, 0x8a, 0xce, 0x4e, 0x00 }, // G
    { 0xfe, 0xfe, 0x10, 0x10, 0xfe, 0xfe, 0x00, 0x00 }, // H
    { 0x00, 0x82, 0xfe, 0xfe, 0x82, 0x00, 0x00, 0x00 }, // I
    { 0x0c, 0x0e, 0x02, 0x82, 0xfe, 0xfc, 0x80, 0x00 }, // J
    { 0x82, 0xfe, 0xfe, 0x10, 0x38, 0xee, 0xc6, 0x00 }, // K
    { 0x82, 0xfe, 0xfe, 0x82, 0x02, 0x06, 0x0e, 0x00 }, // L
    { 0xfe, 0xfe, 0x60, 0x30, 0x60, 0xfe, 0xfe, 0x00 }, // M
    { 0xfe, 0xfe, 0x60, 0x30, 0x18, 0xfe, 0xfe, 0x00 }, // N
    { 0x38, 0x7c, 0xc6, 0x82, 0xc6, 0x7c, 0x38, 0x00 }, // O
    { 0x82, 0xfe, 0xfe, 0x92, 0x90, 0xf0, 0x60, 0x00 }, // P
    { 0x78, 0xfc, 0x84, 0x8e, 0xfe, 0x7a, 0x00, 0x00 }, // Q
    { 0x82, 0xfe, 0xfe, 0x98, 0x9c, 0xf6, 0x62, 0x00 }, // R
    { 0x64, 0xe6, 0xb2, 0x9a, 0xde, 0x4c, 0x00, 0x00 }, // S
    { 0xc0, 0x82, 0xfe, 0xfe, 0x82, 0xc0, 0x00, 0x00 }, // T
    { 0xfe, 0xfe, 0x02, 0x02, 0xfe, 0xfe, 0x00, 0x00 }, // U
    { 0xf8, 0xfc, 0x06, 0x06, 0xfc, 0xf8, 0x00, 0x00 }, // V
    { 0xfe, 0xfe, 0x0c, 0x18, 0x0c, 0xfe, 0xfe, 0x00 }, // W
    { 0xc6, 0xee, 0x38, 0x10, 0x38, 0xee, 0xc6, 0x00 }, // X
    { 0xe0, 0xf2, 0x1e, 0x1e, 0xf2, 0xe0, 0x00, 0x00 }, // Y
    { 0xe6, 0xce, 0x9a, 0xb2, 0xe2, 0xc6, 0x8e, 0x00 }, // Z
    { 0x00, 0xfe, 0xfe, 0x82, 0x82, 0x00, 0x00, 0x00 }, // [
    { 0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x00 }, // "\"
    { 0x00, 0x82, 0x82, 0xfe, 0xfe, 0x00, 0x00, 0x00 }, // ]
    { 0x10, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x10, 0x00 }, // ^
    { 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01 }, // _
    { 0x00, 0x00, 0xc0, 0xe0, 0x20, 0x00, 0x00, 0x00 }, // `
    { 0x04, 0x2e, 0x2a, 0x2a, 0x3c, 0x1e, 0x02, 0x00 }, // a
    { 0x82, 0xfc, 0xfe, 0x22, 0x22, 0x3e, 0x1c, 0x00 }, // b
    { 0x1c, 0x3e, 0x22, 0x22, 0x36, 0x14, 0x00, 0x00 }, // c
    { 0x0c, 0x1e, 0x12, 0x92, 0xfc, 0xfe, 0x02, 0x00 }, // d
    { 0x1c, 0x3e, 0x2a, 0x2a, 0x3a, 0x18, 0x00, 0x00 }, // e
    { 0x12, 0x7e, 0xfe, 0x92, 0xc0, 0x40, 0x00, 0x00 }, // f
    { 0x19, 0x3d, 0x25, 0x25, 0x1f, 0x3e, 0x20, 0x00 }, // g
    { 0x82, 0xfe, 0xfe, 0x10, 0x20, 0x3e, 0x1e, 0x00 }, // h
    { 0x00, 0x22, 0xbe, 0xbe, 0x02, 0x00, 0x00, 0x00 }, // i
    { 0x02, 0x23, 0x21, 0xbf, 0xbe, 0x00, 0x00, 0x00 }, // j
    { 0x82, 0xfe, 0xfe, 0x08, 0x1c, 0x36, 0x22, 0x00 }, // k
    { 0x00, 0x82, 0xfe, 0xfe, 0x02, 0x00, 0x00, 0x00 }, // l
    { 0x3e, 0x3e, 0x30, 0x18, 0x30, 0x3e, 0x1e, 0x00 }, // m
    { 0x3e, 0x3e, 0x20, 0x20, 0x3e, 0x1e, 0x00, 0x00 }, // n
    { 0x1c, 0x3e, 0x22, 0x22, 0x3e, 0x1c, 0x00, 0x00 }, // o
    { 0x21, 0x3f, 0x1f, 0x25, 0x24, 0x3c, 0x18, 0x00 }, // p
    { 0x18, 0x3c, 0x24, 0x25, 0x1f, 0x3f, 0x21, 0x00 }, // q
    { 0x22, 0x3e, 0x1e, 0x22, 0x38, 0x18, 0x00, 0x00 }, // r
    { 0x12, 0x3a, 0x2a, 0x2a, 0x2e, 0x24, 0x00, 0x00 }, // s
    { 0x00, 0x20, 0x7c, 0xfe, 0x22, 0x24, 0x00, 0x00 }, // t
    { 0x3c, 0x3e, 0x02, 0x02, 0x3c, 0x3e, 0x02, 0x00 }, // u
    { 0x38, 0x3c, 0x06, 0x06, 0x3c, 0x38, 0x00, 0x00 }, // v
    { 0x3c, 0x3e, 0x06, 0x0c, 0x06, 0x3e, 0x3c, 0x00 }, // w
    { 0x22, 0x36, 0x1c, 0x08, 0x1c, 0x36, 0x22, 0x00 }, // x
    { 0x39, 0x3d, 0x05, 0x05, 0x3f, 0x3e, 0x00, 0x00 }, // y
    { 0x32, 0x26, 0x2e, 0x3a, 0x32, 0x26, 0x00, 0x00 }, // z
    { 0x10, 0x10, 0x7c, 0xee, 0x82, 0x82, 0x00, 0x00 }, // {
    { 0x00, 0x00, 0x00, 0xee, 0xee, 0x00, 0x00, 0x00 }, // |
    { 0x82, 0x82, 0xee, 0x7c, 0x10, 0x10, 0x00, 0x00 }, // }
//    { 0x40, 0xc0, 0x80, 0xc0, 0x40, 0xc0, 0x80, 0x00 }, // ~
    { B00000000, B01100010, B01100100, B00000100, B00000100, B01100100, B01100010, B00000000 }, // ~
    { 0x1e, 0x3e, 0x62, 0xc2, 0x62, 0x3e, 0x1e, 0x00 }, //
    //SOME NICE PICTURES
    { B00000000, B01100010, B01100100, B00000100, B00000100, B01100100, B01100010, B00000000 }, //
    { B00000000, B01100010, B01100100, B00000100, B00000100, B01100100, B01100010, B00000000 }, //
    };

PROGMEM const byte font_3x5[10][3] = {
    { B11111000, B10001000, B11111000 }, //0
    { B00000000, B00000000, B11111000 }, //1
    { B10111000, B10101000, B11101000 }, //2
    { B10001000, B10101000, B11111000 }, //3
    { B11100000, B00100000, B11111000 }, //4
    { B11101000, B10101000, B10111000 }, //5
    { B11111000, B10101000, B10111000 }, //6
    { B10000000, B10000000, B11111000 }, //7
    { B11111000, B10101000, B11111000 }, //8
    { B11100000, B10100000, B11111000 }, //9
    };




#endif /* FONT_H_ */
