// Copyright 2021 @Yowkees: Keyball logo
//
//   - Keyball logo (0x80 ~ 0xAF)
//
// Copyright 2024 MURAOKA Taro (aka KoRoN, @kaoriya): Other glyphs
//
//   - ASCII characters (0x20 ~ 0x7E)
//   - Special characters (0xB0 ~ 0xC3)

#include "progmem.h"

// clang-format off
const unsigned char font[] PROGMEM = {

  ///////////////////////////////////////////////////////////////////////////
  // Standard ASCII characters, most of which fit within 5x6 area.

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x20 ' '
  0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, // 0x21 '!'
  0x00, 0x07, 0x00, 0x07, 0x00, 0x00, // 0x22 '"'
  0x12, 0x3F, 0x12, 0x3F, 0x12, 0x00, // 0x23 '#'
  0x24, 0x2A, 0x7F, 0x2A, 0x12, 0x00, // 0x24 '$'
  0x36, 0x09, 0x1E, 0x24, 0x1B, 0x00, // 0x25 '%'
  0x18, 0x26, 0x29, 0x12, 0x28, 0x00, // 0x26 '&'
  0x00, 0x00, 0x07, 0x00, 0x00, 0x00, // 0x27 '''
  0x00, 0x1E, 0x21, 0x40, 0x00, 0x00, // 0x28 '('
  0x00, 0x40, 0x21, 0x1E, 0x00, 0x00, // 0x29 ')'
  0x14, 0x08, 0x3E, 0x08, 0x14, 0x00, // 0x2A '*'
  0x08, 0x08, 0x3E, 0x08, 0x08, 0x00, // 0x2B '+'
  0x00, 0x00, 0x30, 0x70, 0x00, 0x00, // 0x2C ','
  0x08, 0x08, 0x08, 0x08, 0x08, 0x00, // 0x2D '-'
  0x00, 0x00, 0x30, 0x30, 0x00, 0x00, // 0x2E '.'
  0x20, 0x10, 0x0C, 0x02, 0x01, 0x00, // 0x2F '/'
  0x1E, 0x29, 0x25, 0x23, 0x1E, 0x00, // 0x30 '0'
  0x00, 0x22, 0x3F, 0x20, 0x00, 0x00, // 0x31 '1'
  0x22, 0x31, 0x29, 0x29, 0x26, 0x00, // 0x32 '2'
  0x12, 0x21, 0x25, 0x25, 0x1A, 0x00, // 0x33 '3'
  0x18, 0x14, 0x12, 0x3F, 0x10, 0x00, // 0x34 '4'
  0x17, 0x25, 0x25, 0x25, 0x18, 0x00, // 0x35 '5'
  0x1E, 0x25, 0x25, 0x25, 0x18, 0x00, // 0x36 '6'
  0x01, 0x31, 0x09, 0x05, 0x03, 0x00, // 0x37 '7'
  0x1A, 0x25, 0x25, 0x25, 0x1A, 0x00, // 0x38 '8'
  0x06, 0x29, 0x29, 0x29, 0x1E, 0x00, // 0x39 '9'
  0x00, 0x00, 0x33, 0x33, 0x00, 0x00, // 0x3A ':'
  0x00, 0x00, 0x33, 0x73, 0x00, 0x00, // 0x3B ';'
  0x08, 0x14, 0x14, 0x22, 0x22, 0x00, // 0x3C '<'
  0x14, 0x14, 0x14, 0x14, 0x14, 0x00, // 0x3D '='
  0x22, 0x22, 0x14, 0x14, 0x08, 0x00, // 0x3E '>'
  0x02, 0x01, 0x29, 0x05, 0x02, 0x00, // 0x3F '?'
  0x3E, 0x59, 0x55, 0x5D, 0x3E, 0x00, // 0x40 '@'
  0x38, 0x16, 0x11, 0x16, 0x38, 0x00, // 0x41 'A'
  0x3F, 0x25, 0x25, 0x25, 0x1A, 0x00, // 0x42 'B'
  0x1E, 0x21, 0x21, 0x21, 0x12, 0x00, // 0x43 'C'
  0x3F, 0x21, 0x21, 0x21, 0x1E, 0x00, // 0x44 'D'
  0x3F, 0x25, 0x25, 0x25, 0x21, 0x00, // 0x45 'E'
  0x3F, 0x09, 0x09, 0x09, 0x01, 0x00, // 0x46 'F'
  0x1E, 0x21, 0x21, 0x29, 0x1A, 0x00, // 0x47 'G'
  0x3F, 0x04, 0x04, 0x04, 0x3F, 0x00, // 0x48 'H'
  0x00, 0x21, 0x3F, 0x21, 0x00, 0x00, // 0x49 'I'
  0x10, 0x20, 0x20, 0x20, 0x1F, 0x00, // 0x4A 'J'
  0x3F, 0x04, 0x0C, 0x12, 0x21, 0x00, // 0x4B 'K'
  0x3F, 0x20, 0x20, 0x20, 0x20, 0x00, // 0x4C 'L'
  0x3F, 0x02, 0x04, 0x02, 0x3F, 0x00, // 0x4D 'M'
  0x3F, 0x02, 0x0C, 0x10, 0x3F, 0x00, // 0x4E 'N'
  0x1E, 0x21, 0x21, 0x21, 0x1E, 0x00, // 0x4F 'O'
  0x3F, 0x09, 0x09, 0x09, 0x06, 0x00, // 0x50 'P'
  0x1E, 0x21, 0x29, 0x11, 0x2E, 0x00, // 0x51 'Q'
  0x3F, 0x09, 0x09, 0x19, 0x26, 0x00, // 0x52 'R'
  0x12, 0x25, 0x25, 0x29, 0x12, 0x00, // 0x53 'S'
  0x01, 0x01, 0x3F, 0x01, 0x01, 0x00, // 0x54 'T'
  0x1F, 0x20, 0x20, 0x20, 0x1F, 0x00, // 0x55 'U'
  0x07, 0x18, 0x20, 0x18, 0x07, 0x00, // 0x56 'V'
  0x0F, 0x30, 0x0C, 0x30, 0x0F, 0x00, // 0x57 'W'
  0x21, 0x12, 0x0C, 0x12, 0x21, 0x00, // 0x58 'X'
  0x03, 0x04, 0x38, 0x04, 0x03, 0x00, // 0x59 'Y'
  0x31, 0x29, 0x25, 0x23, 0x21, 0x00, // 0x5A 'Z'
  0x00, 0x7F, 0x41, 0x41, 0x00, 0x00, // 0x5B '['
  0x01, 0x02, 0x0C, 0x10, 0x20, 0x00, // 0x5C '\'
  0x00, 0x41, 0x41, 0x7F, 0x00, 0x00, // 0x5D ']'
  0x04, 0x02, 0x01, 0x02, 0x04, 0x00, // 0x5E '^'
  0x40, 0x40, 0x40, 0x40, 0x40, 0x00, // 0x5F '_'
  0x00, 0x01, 0x03, 0x04, 0x00, 0x00, // 0x60 '`'
  0x10, 0x2A, 0x2A, 0x2A, 0x3C, 0x00, // 0x61 'a'
  0x3F, 0x24, 0x22, 0x22, 0x1C, 0x00, // 0x62 'b'
  0x1C, 0x22, 0x22, 0x22, 0x24, 0x00, // 0x63 'c'
  0x1C, 0x22, 0x22, 0x24, 0x3F, 0x00, // 0x64 'd'
  0x1C, 0x2A, 0x2A, 0x2A, 0x0C, 0x00, // 0x65 'e'
  0x00, 0x04, 0x3E, 0x05, 0x05, 0x00, // 0x66 'f'
  0x0C, 0x52, 0x52, 0x54, 0x3E, 0x00, // 0x67 'g'
  0x3F, 0x08, 0x04, 0x04, 0x38, 0x00, // 0x68 'h'
  0x00, 0x00, 0x3D, 0x00, 0x00, 0x00, // 0x69 'i'
  0x20, 0x40, 0x40, 0x3D, 0x00, 0x00, // 0x6A 'j'
  0x3F, 0x08, 0x08, 0x14, 0x22, 0x00, // 0x6B 'k'
  0x00, 0x01, 0x3F, 0x20, 0x00, 0x00, // 0x6C 'l'
  0x3E, 0x02, 0x3C, 0x02, 0x3C, 0x00, // 0x6D 'm'
  0x3E, 0x04, 0x02, 0x02, 0x3C, 0x00, // 0x6E 'n'
  0x1C, 0x22, 0x22, 0x22, 0x1C, 0x00, // 0x6F 'o'
  0x7E, 0x14, 0x22, 0x22, 0x1C, 0x00, // 0x70 'p'
  0x1C, 0x22, 0x22, 0x14, 0x7E, 0x00, // 0x71 'q'
  0x3E, 0x04, 0x02, 0x02, 0x04, 0x00, // 0x72 'r'
  0x24, 0x2A, 0x2A, 0x2A, 0x12, 0x00, // 0x73 's'
  0x00, 0x02, 0x1F, 0x22, 0x00, 0x00, // 0x74 't'
  0x1E, 0x20, 0x20, 0x10, 0x3E, 0x00, // 0x75 'u'
  0x06, 0x18, 0x20, 0x18, 0x06, 0x00, // 0x76 'v'
  0x0E, 0x30, 0x0C, 0x30, 0x0E, 0x00, // 0x77 'w'
  0x22, 0x14, 0x08, 0x14, 0x22, 0x00, // 0x78 'x'
  0x0E, 0x50, 0x50, 0x48, 0x3E, 0x00, // 0x79 'y'
  0x22, 0x32, 0x2A, 0x26, 0x22, 0x00, // 0x7A 'z'
  0x08, 0x08, 0x77, 0x41, 0x41, 0x00, // 0x7B '{'
  0x00, 0x00, 0x7F, 0x00, 0x00, 0x00, // 0x7C '|'
  0x41, 0x41, 0x77, 0x08, 0x08, 0x00, // 0x7D '}'
  0x18, 0x04, 0x08, 0x10, 0x0C, 0x00, // 0x7E '~'
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 0x7F

  ///////////////////////////////////////////////////////////////////////////
  // Keyball logo
  

  ///////////////////////////////////////////////////////////////////////////
  // Special characters for Keyball

  // 0xB0
  0x00, 0x10, 0x10, 0x10, 0x00, 0x00, // B0: blank indicator (BL)
  0x00, 0x00, 0x55, 0x00, 0x00, 0x00, // B1: vertical label separator
  0x3E, 0x63, 0x5D, 0x5D, 0x63, 0x7F, // B2, B3:
  0x41, 0x7B, 0x77, 0x41, 0x3E, 0x00, //   "ON" in 2 chars with light bg.
  0x00, 0x1C, 0x22, 0x22, 0x1C, 0x00, // B4, B5:
  0x3E, 0x0A, 0x00, 0x3E, 0x0A, 0x00, //   "OFF" in 2 chars
  0x32, 0x2A, 0x3C, 0x00, 0x26, 0x28, // B6, B7:
  0x1E, 0x00, 0x1C, 0x2A, 0x2C, 0x00, //   "aye" in 2 chars
  0x00, 0x00, 0x3F, 0x09, 0x36, 0x00, // B8: right half "R" indicate "row"
  0x00, 0x00, 0x1E, 0x21, 0x21, 0x00, // B9: right halc "C" indicate "column"
  0x00, 0x00, 0x00, 0x00, 0x3F, 0x08, // BA, BB:
  0x37, 0x00, 0x1E, 0x21, 0x21, 0x00, //   "KC" in 2 chars right aligned
  0x1E, 0x21, 0x21, 0x00, 0x3F, 0x09, // BC, BD:
  0x06, 0x00, 0x21, 0x3F, 0x21, 0x00, //   "CPI" in 2 chars
  0x22, 0x25, 0x19, 0x00, 0x1E, 0x21, // BE, BF:
  0x21, 0x00, 0x3F, 0x09, 0x36, 0x00, //   "SCR" in 2 chars indicate "scroll"

  // 0xC0
  0x3F, 0x21, 0x1E, 0x00, 0x21, 0x3F, // C0, C1:
  0x21, 0x00, 0x0F, 0x30, 0x0F, 0x00, //   "DIV" in 2 chars indicate "divider"
  0x3E, 0x09, 0x3E, 0x00, 0x3F, 0x06, // C2, C3:
  0x3F, 0x00, 0x3F, 0x20, 0x20, 0x00, //   "AML" in 2 chars
};
// clang-format on
static const char PROGMEM meat_ball_logo_1[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1c, 0x7e, 0xfc,
    0xf8, 0xf0, 0x70, 0x60, 0xc0, 0x80,
    0x00, 0x00, 0x00, 0x02, 0x06, 0x0c,
    0x0c, 0x0c, 0x8c, 0x8c, 0x8c, 0x88,
    0x90, 0xa6, 0xec, 0xd8, 0x08, 0x08,
    0x10, 0xb0, 0xb0, 0xe0, 0xf0, 0xf8,
    0xfc, 0xfc, 0xbc, 0xfc, 0xfc, 0xf8,
};

static const char PROGMEM meat_ball_logo_2[] = {
    0xf0, 0x00, 0xf0, 0x30, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x30, 0xf0, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x03, 0x04, 0x08, 0x10, 0x20,
    0xc1, 0x81, 0x06, 0x0c, 0x04, 0x02, 
    0x03, 0x03, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x0f, 0xff, 0xe7, 0xff, 0x7f, 0x07,  
};

static const char PROGMEM meat_ball_logo_3[] = {
    0x03, 0x01, 0x00, 0x1f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x1f,
    0x18, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x18, 0x1f, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x3f, 0xf0, 0x80, 0x00, 0x00,
    0x00, 0x80, 0xc0, 0x80, 0x10, 0x38,
    0x7c, 0x38, 0x10, 0x00, 0xe0, 0xe0, 
    0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x0f, 0x1f, 0x30, 0xe0,
};

static const char PROGMEM meat_ball_logo_4[] = {
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x06,
    0x08, 0x18, 0x19, 0x19, 0x10, 0x30,
    0x30, 0x30, 0x18, 0x0c, 0x06, 0x0f,
    0x3f, 0x70, 0x70, 0x3f, 0x1f, 0x1e,
    0x1e, 0x7e, 0xfc, 0xfc, 0xfc, 0xec,
};

static const char PROGMEM meat_ball_logo_5[] = {
    0xff, 0xff, 0xfe, 0x7c, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01
};


void oledkit_render_logo_user(void) {
    oled_write_raw_P(meat_ball_logo_1, sizeof(meat_ball_logo_1));
    oled_set_cursor(0, 1);
    oled_write_raw_P(meat_ball_logo_2, sizeof(meat_ball_logo_2));
    oled_set_cursor(0, 2);
    oled_write_raw_P(meat_ball_logo_3, sizeof(meat_ball_logo_3));
    oled_set_cursor(0, 3);
    oled_write_raw_P(meat_ball_logo_4, sizeof(meat_ball_logo_4));
    oled_set_cursor(0, 4);
    oled_write_raw_P(meat_ball_logo_4, sizeof(meat_ball_logo_5));

}