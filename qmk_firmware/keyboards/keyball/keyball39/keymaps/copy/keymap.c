#include QMK_KEYBOARD_H
#include "keymap_japanese.h"

#include "utils/functions.h"
#include "features/swipe_gesture.h"
#include "features/auto_click_layer.h"
#include "features/macro_keys.h"
#include "features/combo.h"


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                       KC_Y         , KC_U          , KC_I      , KC_O     , KC_P      ,
    KC_A     , MT(MOD_LALT, KC_S)     , MT(MOD_RSFT, KC_D)     , MT(MOD_LCTL, KC_F) , KC_G     ,                                       KC_H         , MT(MOD_RCTL, KC_J)          , MT(MOD_RSFT, KC_K)      , MT(MOD_RALT, KC_L)     , KC_ENTER  ,
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                                       KC_N         , KC_M          , KC_COMMA  , KC_DOT   , KC_RCTL   ,
    KC_RCTL  , KC_TRNS  , KC_TRNS  , KC_TRNS  , LT(1, KC_SPACE), LT(2,KC_LNG2),    LT(1,KC_LNG1),LT(2,KC_BSPC), LT(3, KC_TAB) , KC_RSFT   , KC_RALT  , KC_LGUI
  ),

  [1] = LAYOUT_universal(
    JP_QUES    , JP_DQUO , JP_EXLM     , KC_TRNS  , JP_PIPE  ,                           JP_YEN         ,JP_UNDS   , JP_HASH  , JP_CIRC        , JP_PERC ,
    JP_AT    , JP_QUOT    ,JP_DLR    , KC_TRNS  ,JP_SLSH    ,                            JP_MINS      , KC_TRNS    , BRACKETS , BRACES   , KC_TRNS ,
    KC_TRNS , JP_GRV     , JP_COLN , JP_SCLN  , JP_BSLS    ,                            JP_TILD     , JP_AMPR    , PARENS   , ANGLE_BRACKETS , KC_TRNS ,
    KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  , KC_TRNS    , KC_TRNS ,        KC_TRNS , LT(2, KC_DEL) , KC_TRNS    , KC_TRNS  , KC_TRNS        , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_HOME  , KC_UP    , KC_END    , JP_PLUS , JP_MINS  ,                            KC_DOT     , KC_7     , KC_8     , KC_9     , KC_TRNS ,
    KC_LEFT  , KC_DOWN  , KC_RIGHT  , JP_ASTR   ,JP_SLSH  ,                            JP_EQL   , KC_4     , KC_5     , KC_6     , KC_TRNS ,
    KC_ESC   , KC_TRNS  , KC_TRNS   ,JP_EQL    , JP_DOT   ,                            KC_0       , KC_1     , KC_2     , KC_3     , KC_TRNS ,
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
    KC_LALT  , KC_TRNS    , KC_MS_BTN2 , KC_MS_BTN1 , KC_TRNS ,                            KC_WWW_BACK , KC_MS_BTN1 , KC_MS_BTN3 , KC_MS_BTN2 , KC_TRNS  ,
    KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS ,                            KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  ,
    LT(2,KC_LGUI)  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS , KC_TRNS  ,      KC_TRNS  , KC_TRNS     , KC_TRNS    , KC_TRNS    , KC_TRNS    , KC_TRNS  
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



