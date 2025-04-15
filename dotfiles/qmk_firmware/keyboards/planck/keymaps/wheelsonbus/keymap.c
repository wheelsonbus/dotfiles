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

#include "shift.h"
const custom_shift_key_t custom_shift_keys[] = {
    {KC_COMM, KC_DOT},
    {KC_SCLN, KC_COLN},
    {KC_QUOT, KC_DQUO},
    {KC_QUES, KC_EXLM},
    {KC_MINS, KC_UNDS},
    {KC_EQL,  KC_PLUS},
    {KC_ASTR, KC_CIRC},
    {KC_DLR,  KC_PERC},
    {KC_LPRN, KC_LCBR},
    {KC_RPRN, KC_RCBR},
    {KC_LBRC, KC_LT  },
    {KC_RBRC, KC_GT  },
    {KC_SLSH, KC_BSLS},
    {KC_PIPE, KC_AMPR},
    {KC_TILD, KC_GRV },
    {KC_HASH, KC_AT  }
};
uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum planck_layers {
  _NAV,
  _NAV_UTIL,
  _SHORTCUTS,
  _MOD,
  _OIEA,
  _OIEA_UTIL,
  _OIEA_VKXJ,
  _NUMBERS,
  _SYMBOLS,
  _ADJUST
};

enum keycodes
{
    KC_NAV = SAFE_RANGE,
    KC_OIEA,
    KC_UTIL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Navigation */
  [_NAV] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, MO(_SHORTCUTS), KC_UTIL, _______, _______, _______, _______, KC_LCTL, MO(_MOD), _______, KC_LGUI,
    _______, _______, _______, _______, KC_LSFT, _______, _______, KC_SPC,  _______, _______, _______, MO(_ADJUST)
  ),

  /* Navigation Utilities */
  [_NAV_UTIL] = LAYOUT_planck_grid(
    QK_BOOT, EE_CLR,  _______, _______, _______, _______, _______, _______, LCTL(KC_V), LCTL(KC_C), LCTL(KC_X), LCTL(KC_Z),
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NAV,  KC_OIEA, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,  KC_DEL,  KC_TAB,  KC_ESC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Shortcuts */
  [_SHORTCUTS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, LCTL(KC_S), LCTL(KC_F), _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* MOD */
  [_MOD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* OIEA */
  [_OIEA] = LAYOUT_planck_grid(
    KC_B,    KC_Y,    KC_U,    KC_P,    _______, _______, _______, _______, KC_R,    KC_D,    KC_C,    KC_W,
    KC_O,    KC_I,    KC_E,    KC_A,    _______, _______, _______, _______, KC_H,    KC_T,    KC_N,    KC_S,
    MO(_OIEA_VKXJ), MO(_NUMBERS), MO(_SYMBOLS), KC_UTIL, _______, _______, _______, _______, KC_L,    KC_M,    KC_F,    KC_G,
    KC_LCTL, KC_LALT, KC_LGUI, _______, KC_LSFT, _______, _______, KC_SPC,  _______, _______, _______, MO(_ADJUST)
  ),

  /* OIEA Utilities */
  [_OIEA_UTIL] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_COMM, KC_SCLN, KC_QUOT, KC_QUES,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_NAV,  KC_OIEA, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,  KC_BSPC, KC_TAB,  KC_ESC,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* OIEA VKXJ */
  [_OIEA_VKXJ] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_Z,    KC_Q,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_V,    KC_K,    KC_X,    KC_J,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Numbers */
  [_NUMBERS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    KC_7,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_1,    KC_2,    KC_3,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_8,    KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Symbols */
  [_SYMBOLS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_ASTR, KC_DLR,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_SLSH, KC_PIPE, KC_TILD, KC_HASH,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Adjust (Lower + Raise)
  *                      v------------------------RGB CONTROL--------------------v
  * ,-----------------------------------------------------------------------------------.
  * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap| NAV  | SNTH |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, DF(_NAV), DF(_OIEA), _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record)
{
    if (!process_custom_shift_keys(keycode, record))
    {
        return false;
    }

    static enum planck_layers default_layer = _NAV;

    switch (keycode)
    {
    case KC_NAV:
        if (record->event.pressed)
        {
            set_single_default_layer(_NAV);
            default_layer = _NAV;
            layer_move(_NAV_UTIL);
            return false;
        }
        break;

    case KC_OIEA:
        if (record->event.pressed)
        {
            set_single_default_layer(_OIEA);
            default_layer = _OIEA;
            layer_move(_OIEA_UTIL);
            return false;
        }
        break;

    case KC_UTIL:
        if (record->event.pressed)
        {
            if (default_layer == _NAV)
            {
                layer_on(_NAV_UTIL);
                return false;
            }
            else if (default_layer == _OIEA)
            {
                layer_on(_OIEA_UTIL);
                return false;
            }
        }
        else
        {
            layer_off(_NAV_UTIL);
            layer_off(_OIEA_UTIL);
            return false;
        }
        break;
    }

    return true;
}
