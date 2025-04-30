/* Copyright 2015-2021 Jack Humbert
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
 */

#include QMK_KEYBOARD_H

enum planck_layers {
  _TEN
};

enum keycodes {
  KC_L0 = SAFE_RANGE,
  KC_L1,
  KC_L2,
  KC_L3,
  KC_L4,
  KC_R0,
  KC_R1,
  KC_R2,
  KC_R3,
  KC_R4,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Navigation */
  [_TEN] = LAYOUT_planck_grid(
    KC_R4,   KC_R3,   KC_R2,   KC_R1,   _______, _______, _______, _______, KC_L1,   KC_L2,   KC_L3,   KC_L4,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_L0,   _______, _______, KC_R0,   _______, _______, _______, _______
  )
};

const uint16_t km_l[1 << 5][4] = {
  {KC_LEFT, KC_UP, KC_DOWN, KC_RIGHT},
  {S(KC_LEFT), S(KC_UP), S(KC_DOWN), S(KC_RIGHT)},
  {C(KC_LEFT), C(KC_UP), C(KC_DOWN), C(KC_RIGHT)},
  {S(C(KC_LEFT)), S(C(KC_UP)), S(C(KC_DOWN)), S(C(KC_RIGHT))},
  {KC_HOME, KC_PAGE_UP, KC_PAGE_DOWN, KC_END},
  {S(KC_HOME), S(KC_PAGE_UP), S(KC_PAGE_DOWN), S(KC_END)},
  {C(KC_PAGE_UP), C(KC_HOME), C(KC_END), C(KC_PAGE_DOWN)},
  {S(C(KC_PAGE_UP)), S(C(KC_HOME)), S(C(KC_END)), S(C(KC_PAGE_DOWN))},
  {G(KC_LEFT), G(KC_UP), G(KC_DOWN), G(KC_RIGHT)},
  {G(S(KC_LEFT)), G(S(KC_UP)), G(S(KC_DOWN)), G(S(KC_RIGHT))},
  {G(C(KC_LEFT)), G(C(KC_UP)), G(C(KC_DOWN)), G(C(KC_RIGHT))},
  {G(S(C(KC_LEFT))), G(S(C(KC_UP))), G(S(C(KC_DOWN))), G(S(C(KC_RIGHT)))},
  {G(KC_HOME), G(KC_PAGE_UP), G(KC_PAGE_DOWN), G(KC_END)},
  {G(S(KC_HOME)), G(S(KC_PAGE_UP)), G(S(KC_PAGE_DOWN)), G(S(KC_END))},
  {G(C(KC_PAGE_UP)), G(C(KC_HOME)), G(C(KC_END)), G(C(KC_PAGE_DOWN))},
  {G(S(C(KC_PAGE_UP))), G(S(C(KC_HOME))), G(S(C(KC_END))), G(S(C(KC_PAGE_DOWN)))},
  {C(KC_Z), C(KC_X), C(KC_C), C(KC_V)},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
};

const uint16_t km_r[1 << 5][4] = {
  {KC_SPACE, KC_TAB, KC_ENTER, KC_BACKSPACE},
  {S(KC_SPACE), S(KC_TAB), S(KC_ENTER), KC_DELETE},
  {KC_A, KC_E, KC_I, KC_O},
  {S(KC_A), S(KC_E), S(KC_I), S(KC_O)},
  {KC_U, KC_R, KC_Y, KC_W},
  {S(KC_U), S(KC_R), S(KC_Y), S(KC_W)},
  {KC_H, KC_T, KC_N, KC_S},
  {S(KC_H), S(KC_T), S(KC_N), S(KC_S)},
  {KC_D, KC_L, KC_C, KC_G},
  {S(KC_D), S(KC_L), S(KC_C), S(KC_G)},
  {KC_M, KC_F, KC_P, KC_B},
  {S(KC_M), S(KC_F), S(KC_P), S(KC_B)},
  {KC_V, KC_K, KC_X, KC_J},
  {S(KC_V), S(KC_K), S(KC_X), S(KC_J)},
  {KC_Z, KC_Q, XXXXXXX, XXXXXXX},
  {S(KC_Z), S(KC_Q), XXXXXXX, XXXXXXX},
  {KC_COMMA, KC_SEMICOLON, KC_QUOTE, KC_QUESTION},
  {KC_DOT, KC_COLON, KC_DOUBLE_QUOTE, KC_EXCLAIM},
  {KC_LEFT_PAREN, KC_RIGHT_PAREN, KC_LEFT_BRACKET, KC_RIGHT_BRACKET},
  {KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET},
  {KC_MINUS, KC_EQUAL, KC_ASTERISK, KC_DOLLAR},
  {KC_UNDERSCORE, KC_PLUS, KC_CIRCUMFLEX, KC_PERCENT},
  {KC_SLASH, KC_PIPE, KC_TILDE, KC_HASH},
  {KC_BACKSLASH, KC_AMPERSAND, KC_GRAVE, KC_AT},
  {KC_0, KC_1, KC_2, KC_3},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_4, KC_5, KC_6, KC_7},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {KC_8, KC_9, S(KC_A), S(KC_B)},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX},
  {S(KC_C), S(KC_D), S(KC_E), S(KC_F)},
  {XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX}
};

enum first {
  FIRST_NONE,
  FIRST_L,
  FIRST_R
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  static uint8_t l = 0;
  static uint8_t r = 0;
  static enum first first = FIRST_NONE;
  static uint16_t registered_KC = KC_NO;
  static uint16_t registered_KC_L1 = KC_NO;
  static uint16_t registered_KC_L2 = KC_NO;
  static uint16_t registered_KC_L3 = KC_NO;
  static uint16_t registered_KC_L4 = KC_NO;
  static uint16_t registered_KC_R1 = KC_NO;
  static uint16_t registered_KC_R2 = KC_NO;
  static uint16_t registered_KC_R3 = KC_NO;
  static uint16_t registered_KC_R4 = KC_NO;

  switch (keycode) {
  case KC_L0:
    if (record->event.pressed) {
      l |= (1 << 0);
      if (first == FIRST_NONE) {
        first = FIRST_R;
      }
    } else {
      l &= ~(1 << 0);
      if (first == FIRST_R) {
        if (r & (1 << 0)) {
          first = FIRST_L;
        } else {
          first = FIRST_NONE;
        }
      }
    }
    return false;
    case KC_L1:
    if (record->event.pressed) {
      l |= (1 << 1);
      if (first == FIRST_R) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_r[r][0]);
        registered_KC_L1 = km_r[r][0];
      }
    } else {
      l &= ~(1 << 1);
      if (registered_KC_L1 != KC_NO) {
        unregister_code16(registered_KC_L1);
        registered_KC_L1 = KC_NO;
      }
    }
    return false;
    case KC_L2:
    if (record->event.pressed) {
      l |= (1 << 2);
      if (first == FIRST_R) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_r[r][1]);
        registered_KC_L2 = km_r[r][1];
      }
    } else {
      l &= ~(1 << 2);
      if (registered_KC_L2 != KC_NO) {
        unregister_code16(registered_KC_L2);
        registered_KC_L2 = KC_NO;
      }
    }
    return false;
    case KC_L3:
    if (record->event.pressed) {
      l |= (1 << 3);
      if (first == FIRST_R) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_r[r][2]);
        registered_KC_L3 = km_r[r][2];
      }
    } else {
      l &= ~(1 << 3);
      if (registered_KC_L3 != KC_NO) {
        unregister_code16(registered_KC_L3);
        registered_KC_L3 = KC_NO;
      }
    }
    return false;
    case KC_L4:
    if (record->event.pressed) {
      l |= (1 << 4);
      if (first == FIRST_R) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_r[r][3]);
        registered_KC_L4 = km_r[r][3];
      }
    } else {
      l &= ~(1 << 4);
      if (registered_KC_L4 != KC_NO) {
        unregister_code16(registered_KC_L4);
        registered_KC_L4 = KC_NO;
      }
    }
    return false;
  case KC_R0:
    if (record->event.pressed) {
      r |= (1 << 0);
      if (first == FIRST_NONE) {
        first = FIRST_L;
      }
    } else {
      r &= ~(1 << 0);
      if (first == FIRST_L) {
        if (l & (1 << 0)) {
          first = FIRST_R;
        } else {
          first = FIRST_NONE;
        }
      }
    }
    return false;
  case KC_R1:
    if (record->event.pressed) {
      r |= (1 << 1);
      if (first == FIRST_L) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_l[l][3]);
        registered_KC_R1 = km_l[l][3];
      }
    } else {
      r &= ~(1 << 1);
      if (registered_KC_R1 != KC_NO) {
        unregister_code16(registered_KC_R1);
        registered_KC_R1 = KC_NO;
      }
    }
    return false;
  case KC_R2:
    if (record->event.pressed) {
      r |= (1 << 2);
      if (first == FIRST_L) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_l[l][2]);
        registered_KC_R2 = km_l[l][2];
      }
    } else {
      r &= ~(1 << 2);
      if (registered_KC_R2 != KC_NO) {
        unregister_code16(registered_KC_R2);
        registered_KC_R2 = KC_NO;
      }
    }
    return false;
  case KC_R3:
    if (record->event.pressed) {
      r |= (1 << 3);
      if (first == FIRST_L) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_l[l][1]);
        registered_KC_R3 = km_l[l][1];
      }
    } else {
      r &= ~(1 << 3);
      if (registered_KC_R3 != KC_NO) {
        unregister_code16(registered_KC_R3);
        registered_KC_R3 = KC_NO;
      }
    }
    return false;
  case KC_R4:
    if (record->event.pressed) {
      r |= (1 << 4);
      if (first == FIRST_L) {
        if (registered_KC != KC_NO) {
          unregister_code16(registered_KC);
          registered_KC = KC_NO;
        }
        register_code16(km_l[l][0]);
        registered_KC_R4 = km_l[l][0];
      }
    } else {
      r &= ~(1 << 4);
      if (registered_KC_R4 != KC_NO) {
        unregister_code16(registered_KC_R4);
        registered_KC_R4 = KC_NO;
      }
    }
    return false;
  }

  return true;
}
