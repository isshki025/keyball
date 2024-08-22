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

oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#ifdef OLED_ENABLE
bool oled_task_kb(void) {

    if (!oled_task_user()) { return false; }

    static const char PROGMEM my_logo[] = {
        0xf7, 0xff, 0xff, 0xf6, 0xbe, 0xfe, 0xf6, 0xfe, 0xfe, 0xff, 0xff, 0xf7, 0xd6, 0xf6, 0xf7, 0xff, 
0xff, 0xdf, 0xde, 0xfe, 0xde, 0xfe, 0xff, 0xfb, 0xdf, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xfb, 0xff, 
0xbf, 0xbe, 0xf7, 0xff, 0xff, 0xbe, 0xff, 0xff, 0xff, 0xfe, 0xff, 0xdf, 0xff, 0xde, 0xfe, 0xf6, 
0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xfb, 0xdf, 0xff, 0xfb, 0xfe, 0xff, 0xff, 0xff, 0xfb, 0xdf, 
0xfe, 0xf7, 0xfe, 0xff, 0xff, 0xb7, 0xf7, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xde, 0xff, 0xff, 0xff, 
0xf7, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xdb, 0xfb, 0xff, 0xdf, 0xde, 0xdf, 0xdf, 0xff, 0xff, 0xff, 
0xff, 0xfe, 0xff, 0xff, 0xf7, 0xb7, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x5f, 0x7f, 0x7f, 0x7e, 0x7e, 
0x76, 0x7e, 0x7f, 0x7f, 0x7f, 0x7f, 0x7b, 0x7f, 0x7f, 0x7f, 0x7e, 0x7f, 0xff, 0x7f, 0xff, 0xff, 
0xfa, 0xfb, 0xfb, 0xbb, 0xfb, 0xfb, 0xdb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xfb, 0xf3, 0xfb, 
0xfb, 0xfb, 0xff, 0xfb, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xfd, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 
0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xbf, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xbf, 0xf7, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xfb, 
0xff, 0xf7, 0xff, 0xff, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0x5f, 0x5e, 0x5f, 0x7f, 0x7f, 0x7f, 
0xfe, 0xfe, 0xbe, 0xbe, 0xbf, 0xbf, 0xbf, 0xbe, 0xfe, 0xfe, 0xde, 0xfe, 0xfe, 0xf6, 0xfe, 0xf7, 
0xf7, 0xd7, 0xd7, 0xff, 0xff, 0xfb, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xfa, 0xfe, 0xff, 0xff, 0xff, 
0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xbf, 0xbf, 0xbf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xf7, 
0xf7, 0xd7, 0xf7, 0xff, 0xdf, 0xdf, 0xdf, 0xdf, 0xda, 0xde, 0xda, 0xfa, 0xfe, 0xfe, 0xfb, 0xff, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
0xfe, 0xff, 0xdf, 0xdf, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xfe, 0xfa, 0xff, 0xff, 0xff, 
0x1f, 0x1f, 0x1f, 0x1f, 0x17, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 0x1f, 0x1f, 0x1f, 0x1f, 0x1e, 
0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1b, 

    };

    oled_write_raw_P(my_logo, sizeof(my_logo));
    oled_set_cursor(0, 5);

    return false;

}
#endif

