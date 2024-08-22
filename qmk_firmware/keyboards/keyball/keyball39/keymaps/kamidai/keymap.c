#include QMK_KEYBOARD_H

#include "utils/functions.h"
#include "features/swipe_gesture.h"
#include "features/auto_click_layer.h"
#include "features/macro_keys.h"
#include "features/combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                       KC_Y         , KC_U          , KC_I      , KC_O     , KC_P      ,
    KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                       KC_H         , KC_J          , KC_K      , KC_L     , KC_ENTER  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                       KC_N         , KC_M          , KC_COMMA  , KC_DOT   , KC_RCTL   ,
    KC_LGUI  , KC_TRNS  , KC_TRNS  , KC_TRNS  , LT(1, KC_SPACE), LT(2,KC_LNG2),    LT(1,KC_LNG1),LT(2,KC_BSPC), LT(3, KC_TAB) , KC_RSFT   , KC_RALT  , KC_RCTL
  ),

  [1] = LAYOUT_universal(
    KC_QUES    , S(KC_QUOT) , S(KC_1)    , KC_TRNS  , S(KC_BSLS) ,                            KC_BSLS       , S(KC_MINS) , S(KC_3)  , S(KC_6)        , S(KC_5) ,
    S(KC_2)    , KC_QUOT    , S(KC_4)    , KC_TRNS  , KC_SLSH    ,                            KC_MINUS      , KC_TRNS    , BRACKETS , CURLY_BRACES   , KC_TRNS ,
    C(KC_LEFT) , KC_GRV     , S(KC_SCLN) , KC_SCLN  , KC_BSLS    ,                            S(KC_GRV)     , S(KC_7)    , PARENS   , ANGLE_BRACKETS , KC_TRNS ,
    KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  , KC_TRNS    , KC_TRNS ,        KC_TRNS , LT(2, KC_DEL) , KC_TRNS    , KC_TRNS  , KC_TRNS        , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_HOME  , KC_UP    , KC_END    , S(KC_EQL) , KC_MINS  ,                            KC_DOT     , KC_7     , KC_8     , KC_9     , KC_TRNS ,
    KC_LEFT  , KC_DOWN  , KC_RIGHT  , S(KC_8)   , KC_SLSH  ,                            KC_EQUAL   , KC_4     , KC_5     , KC_6     , KC_TRNS ,
    KC_ESC   , KC_TRNS  , KC_TRNS   , KC_EQL    , KC_DOT   ,                            KC_0       , KC_1     , KC_2     , KC_3     , KC_TRNS ,
    KC_TRNS  , KC_TRNS  , KC_TRNS   , KC_TRNS   , KC_TRNS  , KC_TRNS  ,      KC_TRNS  , KC_TRNS    , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  
  ),

  [3] = LAYOUT_universal(
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_F10   , KC_F7    , KC_F8    , KC_F9    , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_F11   , KC_F4    , KC_F5    , KC_F6    , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_F12   , KC_F1    , KC_F2    , KC_F3    , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,      KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  
  ),

  [4] = LAYOUT_universal(
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,      KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  
  ),

  [5] = LAYOUT_universal(
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_TRNS  , SCRL_DVI , CPI_I100 , KC_TRNS  , RGB_TOG  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            SCRL_DVD , CPI_D100 , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,        KC_TRNS, KBC_RST  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  
  ),

  [6] = LAYOUT_universal(
    KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS ,                            KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  ,
    KC_LALT  , KC_WWW_BACK , KC_MS_BTN1 , KC_MS_BTN2 , KC_TRNS ,                            KC_WWW_BACK , KC_MS_BTN1 , KC_MS_BTN3 , KC_MS_BTN2 , KC_TRNS  ,
    KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS ,                            KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  ,
    KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS  ,      KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤーが2の時のみスクロールモードを有効にする
  keyball_set_scroll_mode(get_highest_layer(state) == 2);

  // レイヤーに応じたRGBライトの設定
  switch (get_highest_layer(state)) {
    case click_layer:
      rgblight_sethsv(HSV_WHITE);  // click_layerでは白色
      break;
    case 2:
      rgblight_sethsv(HSV_YELLOW);  // レイヤー2では黄色
      break;
    default:
      rgblight_sethsv(HSV_OFF);     // それ以外はライトをオフ
  }

  #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    keyball_handle_auto_mouse_layer_change(state);
  #endif

  return state;
}

// #ifdef OLED_ENABLE

// #include "lib/oledkit/oledkit.h"

// void oledkit_render_info_user(void) {
//   // デバッグ用に変数を表示する
//   // oled_write_P(PSTR("Debug:"), false);
//   // oled_write(get_u8_str(xxx, ' '), false);

//   keyball_oled_render_keyinfo();   // キー情報を表示
//   keyball_oled_render_ballinfo();  // トラックボール情報を表示

//   // <Layer>を表示する
//   oled_write_P(PSTR("Layer:"), false);
//   oled_write(get_u8_str(get_highest_layer(layer_state), ' '), false);

//   // <マウス移動量 / クリックレイヤーしきい値>を表示
//   // oled_write_P(PSTR(" MV:"), false);
//   // oled_write(get_u8_str(mouse_movement, ' '), false);
//   // oled_write_P(PSTR("/"), false);
//   // oled_write(get_u8_str(to_clickable_movement, ' '), false);

//   // <state>を表示
//   switch (state) {
//     case WAITING:
//       oled_write_ln_P(PSTR("  WAITING"), false);
//       break;
//     case CLICKABLE:
//       oled_write_ln_P(PSTR("  CLICKABLE"), false);
//       break;
//     case CLICKING:
//       oled_write_ln_P(PSTR("  CLICKING"), false);
//       break;
//     case CLICKED:
//       oled_write_ln_P(PSTR("  CLICKED"), false);
//       break;
//     case SWIPE:
//       oled_write_ln_P(PSTR("  SWIPE"), false);
//       break;
//     case SWIPING:
//       oled_write_ln_P(PSTR("  SWIPING"), false);
//       break;
//     case NONE:
//       oled_write_ln_P(PSTR("  NONE"), false);
//       break;
//   }
// }
// #endif

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
    0x00, 0xf0, 0x30, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x30, 0xf0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
    0x03, 0x04, 0x08, 0x10, 0x20, 0xc1,
    0x81, 0x06, 0x0c, 0x04, 0x02, 0x03,
    0x03, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x01, 0x01, 0x01, 0x0f,
    0xff, 0xe7, 0xff, 0x7f, 0x07, 0x03,
  
};

static const char PROGMEM meat_ball_logo_3[] = {
    0x00, 0x1f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1f, 0x18, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x18, 0x1f,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x06, 0x3f,
    0xf0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x80, 0x10, 0x38, 0x7c, 0x38,
    0x10, 0x00, 0xe0, 0xe0, 0x00, 0x00,
    0x80, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0x1f, 0x30, 0xe0, 0xc0, 0x00,
};

static const char PROGMEM meat_ball_logo_4[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x06, 0x08, 0x18, 0x19,
    0x19, 0x10, 0x30, 0x30, 0x30, 0x18,
    0x0c, 0x06, 0x0f, 0x3f, 0x70, 0x70,
    0x3f, 0x1f, 0x1e, 0x1e, 0x7e, 0xfc,
    0xfc, 0xfc, 0xec, 0xff, 0xff, 0xfe
};



void oledkit_render_logo_user(void) {
    oled_write_raw_P(meat_ball_logo_1, sizeof(meat_ball_logo_1));
    oled_set_cursor(0, 1);
    oled_write_raw_P(meat_ball_logo_2, sizeof(meat_ball_logo_2));
    oled_set_cursor(0, 2);
    oled_write_raw_P(meat_ball_logo_3, sizeof(meat_ball_logo_3));
    oled_set_cursor(0, 3);
    oled_write_raw_P(meat_ball_logo_4, sizeof(meat_ball_logo_4));
   

}