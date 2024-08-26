/* Copyright 2023 kamidai (@d_kamiichi)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * コード表：
 * - 公式ファームウェアのキーコード：
 *   KBC_RST(0x5DA5): Keyball 設定のリセット
 *   KBC_SAVE(0x5DA6): 現在の Keyball 設定を EEPROM に保存します
 *   CPI_I100(0x5DA7): CPI を 100 増加させます(最大:12000)
 *   CPI_D100(0x5DA8): CPI を 100 減少させます(最小:100)
 *   CPI_I1K(0x5DA9): CPI を 1000 増加させます(最大:12000)
 *   CPI_D1K(0x5DAA): CPI を 1000 減少させます(最小:100)
 *   SCRL_TO(0x5DAB): タップごとにスクロールモードの ON/OFF を切り替えます
 *   SCRL_MO(0x5DAC): キーを押している間、スクロールモードになります
 *   SCRL_DVI(0x5DAD): スクロール除数を１つ上げます(max D7 = 1/128)← 最もスクロール遅い
 *   SCRL_DVD(0x5DAE): スクロール除数を１つ下げます(min D0 = 1/1)← 最もスクロール速い
 */

enum custom_keycodes {
    KC_BACK_TO_LAYER0_BTN1 = KEYBALL_SAFE_RANGE,  // (0x5DAF): レイヤー0に遷移できるBTN1
    KC_DOUBLE_CLICK_BTN1,                         // (0x5DB0): 1タップでダブルクリックできるBTN1
    KC_TRIPLE_CLICK_BTN1,                         // (0x5DB1): 1タップでトリプルクリックできるBTN1
    SFT_T_G_KC_A,                                 // (0x5DB2):
    SFT_T_S_KC_SCOLON,                            // (0x5DB3):

    BRACKETS = SAFE_RANGE + 0x10,                 // [ と ] を同時入力
    PARENS,                                       // ( と ) を同時入力
    ANGLE_BRACKETS,                               // < と > を同時入力
    CURLY_BRACES,                                 // { と } を同時入力

    MIDDLE_DOT = SAFE_RANGE + 0x20,               // ・(中黒)
    ALT_LEFT,                                     // ALT + LEFT
};

// マクロキーの処理を行う関数
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static bool is_gui_active = false;
    static bool is_ctrl_active = false;

    // キー入力に応じた画像切り替え処理 (keyball.c)
    if (record->event.pressed) {
        current_image = !current_image;
    }

    // macrokeys.h からの処理
    current_keycode = keycode;

  switch (keycode) {
    case KC_MS_BTN1:
    case KC_MS_BTN2:
    case KC_MS_BTN3:
    case KC_MS_BTN4:
    case KC_MS_BTN5: {
      if (click_layer && get_highest_layer(layer_state) == click_layer) {
        if (record->event.pressed) {
          state = CLICKING;
        } else {
          enable_click_layer();
          state = CLICKED;
        }
      }
      return true;
    }

    case KC_LALT:
    case KC_LSFT: {
      return true;
    }

    case KC_TAB: {
      if (record->event.pressed) {
        if (get_highest_layer(layer_state) == 1) {
          register_code(KC_LGUI);
          is_gui_active = true;
        } else if (get_highest_layer(layer_state) == 3) {
          register_code(KC_LCTL);
          is_ctrl_active = true;
        }
      }
      return true;
    }

    case LT(1, KC_LNG2):
    case LT(1, KC_LNG1):
    case LT(2, KC_V):
    case LT(3, KC_ESC): {
      if (record->event.pressed) {
        click_timer = timer_read();
        if (keycode == LT(1, KC_LNG2) || keycode == LT(1, KC_LNG1)) {
          layer_on(1);
        } else if (keycode == LT(2, KC_V)) {
          layer_on(2);
        } else if (keycode == LT(3, KC_ESC)) {
          layer_on(3);
        }
        disable_click_layer();
      } else {
        if (keycode == LT(1, KC_LNG2) || keycode == LT(1, KC_LNG1)) {
          layer_off(1);
        } else if (keycode == LT(2, KC_V)) {
          layer_off(2);
        } else if (keycode == LT(3, KC_ESC)) {
          layer_off(3);
        }

        if (timer_elapsed(click_timer) < TAPPING_TERM) {
          if (keycode == LT(1, KC_LNG2)) {
            tap_code(KC_LNG2);
          } else if (keycode == LT(1, KC_LNG1)) {
            tap_code(KC_LNG1);
          } else if (keycode == LT(2, KC_V)) {
            tap_code(KC_V);
          } else if (keycode == LT(3, KC_ESC)) {
            tap_code(KC_ESC);
          }
        }

        if (is_gui_active) {
          unregister_code(KC_LGUI);
          is_gui_active = false;
        }

        if (is_ctrl_active) {
          unregister_code(KC_LCTL);
          is_ctrl_active = false;
        }
      }
      return false;
    }


    // ショートカットの入力
    case BRACKETS:
      if (record->event.pressed) {
          SEND_STRING("[]");
      }
      return false;

    case CURLY_BRACES:
      if (record->event.pressed) {
          SEND_STRING("{}");
      }
      return false;

    case PARENS:
      if (record->event.pressed) {
          SEND_STRING("()");
      }
      return false;

    case ANGLE_BRACKETS:
      if (record->event.pressed) {
          SEND_STRING("<>");
      }
      return false;

    default:
      if (record->event.pressed) {
        disable_click_layer();
      }
    break;
    
    case ALT_LEFT:
      if (record->event.pressed) {
          register_code(KC_LALT);
          register_code(KC_LEFT);
      } else {
          unregister_code(KC_LEFT);
          unregister_code(KC_LALT);
      }
      return false;
  }
  return true;
}