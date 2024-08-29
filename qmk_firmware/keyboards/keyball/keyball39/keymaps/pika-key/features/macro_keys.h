enum custom_keycodes {
    BRACKETS = SAFE_RANGE + 0x10,                 // [ と ] を同時入力
    PARENS,                                       // ( と ) を同時入力
    ANGLE_BRACKETS,                               // < と > を同時入力
    CURLY_BRACES,                                 // { と } を同時入力
    ALT_LEFT,                                     // ALT + LEFT
};

// マクロキーの処理を行う関数
extern uint8_t current_image;
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