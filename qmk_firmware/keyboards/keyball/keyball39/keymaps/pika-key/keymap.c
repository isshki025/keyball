#include QMK_KEYBOARD_H
#include "quantum.h"

#include "features/auto_mouse_layer.h"
#include "features/macro_keys.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_Q          , KC_W              , KC_E               , KC_R               , KC_T            ,                                      KC_Y          , KC_U               , KC_I               , KC_O               , KC_P      ,
    KC_A          , MT(MOD_LALT,KC_S) , MT(MOD_LSFT, KC_D) , MT(MOD_LCTL, KC_F) , KC_G            ,                                      KC_H          , MT(MOD_RCTL, KC_J) , MT(MOD_RSFT, KC_K) , MT(MOD_RALT, KC_L) , KC_ENTER  ,
    KC_Z          , KC_X              , KC_C               , KC_V               , KC_B            ,                                      KC_N          , KC_M               , KC_COMMA           , KC_DOT             , KC_RCTL   ,
    KC_LGUI       , KC_TRNS           , KC_TRNS            , KC_TRNS            , LT(1, KC_SPACE) , LT(2,KC_LNG2),       LT(1,KC_LNG1) , LT(2,KC_BSPC) , LT(3, KC_TAB)      , KC_RSFT            , KC_RALT            , KC_RCTL
  ),

  [1] = LAYOUT_universal(
    KC_QUES       , S(KC_QUOT)        , S(KC_1)            , KC_TRNS            , S(KC_BSLS)      ,                                      KC_BSLS       , S(KC_MINS)         , S(KC_3)            , S(KC_6)            , S(KC_5) ,
    S(KC_2)       , KC_QUOT           , S(KC_4)            , KC_TRNS            , KC_SLSH         ,                                      KC_MINUS      , KC_TRNS            , BRACKETS           , CURLY_BRACES       , KC_TRNS ,
    C(KC_LEFT)    , KC_GRV            , S(KC_SCLN)         , KC_SCLN            , KC_BSLS         ,                                      S(KC_GRV)     , S(KC_7)            , PARENS             , ANGLE_BRACKETS     , KC_TRNS ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         , KC_TRNS      ,       KC_TRNS       , LT(2, KC_DEL) , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_HOME       , KC_UP             , KC_END             , S(KC_EQL)          , KC_MINS         ,                                      KC_DOT        , KC_7               , KC_8               , KC_9               , KC_TRNS ,
    KC_LEFT       , KC_DOWN           , KC_RIGHT           , S(KC_8)            , KC_SLSH         ,                                      KC_EQUAL      , KC_4               , KC_5               , KC_6               , KC_TRNS ,
    KC_ESC        , KC_TRNS           , KC_TRNS            , KC_EQL             , KC_DOT          ,                                      KC_0          , KC_1               , KC_2               , KC_3               , KC_TRNS ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         , KC_TRNS      ,       KC_TRNS       , KC_TRNS       , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS  
  ),

  [3] = LAYOUT_universal(
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         ,                                      KC_F10        , KC_F7              , KC_F8              , KC_F9              , KC_TRNS  ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         ,                                      KC_F11        , KC_F4              , KC_F5              , KC_F6              , KC_TRNS  ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         ,                                      KC_F12        , KC_F1              , KC_F2              , KC_F3              , KC_TRNS  ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         , KC_TRNS      ,       KC_TRNS       , KC_TRNS       , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS  
  ),
  
  [4] = LAYOUT_universal(
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         ,                                      KC_TRNS       , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS  ,
    KC_LALT       , ALT_LEFT          , KC_MS_BTN2         , KC_MS_BTN1         , KC_TRNS         ,                                      ALT_LEFT      , KC_MS_BTN1         , KC_MS_BTN2         , KC_TRNS            , KC_TRNS  ,
    KC_TRNS       , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         ,                                      KC_TRNS       , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS  ,
    LT(2,KC_LGUI) , KC_TRNS           , KC_TRNS            , KC_TRNS            , KC_TRNS         , KC_TRNS      ,       KC_TRNS       , KC_TRNS       , KC_TRNS            , KC_TRNS            , KC_TRNS            , KC_TRNS  
  )
};


// レイヤーの状態が変わったときの処理
layer_state_t layer_state_set_user(layer_state_t state) {
  // レイヤー2の時、スクロールモードが有効になる
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
  return state;
}


//OLEDディスプレイの呼び出し

#include "lib/oledkit/oledkit.h"
oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

#ifdef OLED_ENABLE
bool oled_task_kb(void) {

    if (!oled_task_user()) { return false; }

    static const char PROGMEM my_logo[] = {
        0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xf3, 0xff, 0xfe, 0x7f, 0xf3, 0xff, 0xff, 0xff, 0xff, 
        0xe0, 0x8e, 0x64, 0x73, 0xe0, 0x06, 0x60, 0x33, 0xe6, 0x66, 0x67, 0x33, 0xe6, 0x66, 0x67, 0x33, 
        0xe6, 0x66, 0x67, 0x33, 0xe6, 0x66, 0x67, 0x33, 0xe6, 0x66, 0x67, 0x33, 0xe6, 0x66, 0x67, 0x33, 
        0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xbf, 0xbf, 0xff, 0xff, 
        0xbf, 0xbf, 0xff, 0xff, 0x83, 0x3f, 0xff, 0xff, 0xf7, 0x7f, 0xff, 0xff, 0xf6, 0xff, 0xff, 0xff, 
        0xee, 0xf1, 0xc8, 0xf3, 0xed, 0xe0, 0xc0, 0x61, 0xdd, 0xce, 0x4e, 0x4c, 0xdb, 0xce, 0x4e, 0x40, 
        0xbb, 0xce, 0x4e, 0x40, 0x30, 0x4e, 0x4e, 0x4f, 0x7f, 0xa0, 0xce, 0x61, 0x7f, 0xb1, 0xce, 0x70, 
        0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
    };

    oled_write_raw_P(my_logo, sizeof(my_logo));

    return false;

}
#endif