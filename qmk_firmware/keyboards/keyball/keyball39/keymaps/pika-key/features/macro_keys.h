enum custom_keycodes {
    BRACKETS = SAFE_RANGE + 0x10,                 // [ と ] を同時入力
    PARENS,                                       // ( と ) を同時入力
    ANGLE_BRACKETS,                               // < と > を同時入力
    CURLY_BRACES,                                 // { と } を同時入力
    ALT_LEFT,                                     // ALT + LEFT
};

// マクロキーの処理を行う関数
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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