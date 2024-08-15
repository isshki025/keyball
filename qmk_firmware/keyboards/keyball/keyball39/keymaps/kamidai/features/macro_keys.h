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
  COMBO_BRC,                                    // (0x5DB5):
  COMBO_select_BRC,                             // (0x5DB5):
  COMBO_S9_S0,                                  // (0x5DB5):
  COMBO_select_S9_S0,                           // (0x5DB5):
  COMBO_S_BRC,                                  // (0x5DB5):
  COMBO_select_S_BRC,                           // (0x5DB5):
  COMBO_sumitsuki_BRC,                          // (0x5DB5):
  COMBO_select_sumitsuki_BRC,                   // (0x5DB5):
  COMBO_MINUS_SPACE,                            // (0x5DB5):
  // CUSTOM_LT1_LEFT,                           //
  // CUSTOM_LT1_LEFT,                           //
  // CUSTOM_S9,                                 //
  // CUSTOM_S0,                                 //
  // KC_ALT_BTN1,                               //
  // select_BRC,
  // CMD_SCRL,
  CUSTOM_QUES,                                  // ' and ?
  CUSTOM_EXEQ,                                  // ! and =
  CUSTOM_ATAMP,                                 // @ and &
  CUSTOM_HASHSC,                                // # and ;
  CUSTOM_DOTDLR,                                // . and $
  CUSTOM_COMMCLN,                               // , and :
  CUSTOM_GRVSLH,                                // ` and /
  CUSTOM_TILDCRT,                               // ~ and ^
  CUSTOM_PERCPIPE,                              // % and |
  CUSTOM_COMMA_LPAREN = SAFE_RANGE,             // , and (
  CUSTOM_DOT_RPAREN,                            // . and )
  BRACES = SAFE_RANGE,                          // { と } を同時入力
  BRACKETS = SAFE_RANGE,                        // [ と ] を同時入力
  PARENS,                                       // ( と ) を同時入力
  ANGLE_BRACKETS,                               // < と > を同時入力
  MIDDLE_DOT = SAFE_RANGE,                      // ・(中黒) 
};

// マクロキーの処理を行う関数
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  current_keycode = keycode;

  static bool is_gui_active = false;
  static bool is_ctrl_active = false;

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

    // カスタムキーコード
    case CUSTOM_QUES:
    case CUSTOM_EXEQ:
    case CUSTOM_ATAMP:
    case CUSTOM_HASHSC:
    case CUSTOM_DOTDLR:
    case CUSTOM_COMMCLN:
    case CUSTOM_GRVSLH:
    case CUSTOM_TILDCRT:
    case CUSTOM_PERCPIPE: {
      if (record->event.pressed) {
        switch (keycode) {
          case CUSTOM_QUES:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? KC_QUES : KC_QUOT);
            break;
          case CUSTOM_EXEQ:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? S(KC_1) : KC_EQUAL);
            break;
          case CUSTOM_ATAMP:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? KC_AMPR : KC_AT);
            break;
          case CUSTOM_HASHSC:
            if (get_mods() & MOD_MASK_SHIFT) {
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_SCLN);
                set_mods(MOD_MASK_SHIFT);
            } else {
                tap_code16(S(KC_3));
            }
            break;
          case CUSTOM_DOTDLR:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? S(KC_4) : KC_DOT);
            break;
          case CUSTOM_COMMCLN:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? KC_COLN : KC_COMM);
            break;
          case CUSTOM_GRVSLH:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? KC_GRV : KC_SLSH);
            break;
            
case BRACKETS:  // このケースは重複しているので削除
      if (record->event.pressed) {
          SEND_STRING("[]");
      }
      return false;
          case CUSTOM_TILDCRT:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? S(KC_6) : KC_TILD);
            break;
          case CUSTOM_PERCPIPE:
            tap_code16((get_mods() & MOD_MASK_SHIFT) ? S(KC_BSLS) : S(KC_5));
            break;
        }
      }
      return false;
    }

    // ショートカットの入力
    case BRACES:
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
  }
  return true;
}