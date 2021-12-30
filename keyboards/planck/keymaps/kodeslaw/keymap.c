/*
 * Copyright 2021 Kodeslaw
 */

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
#include "rgb_matrix.h"

enum planck_layers {
  _QWERTY,
  _FN1,
  _FN2,
  _FN3,
  _FN4,
  _FN5
};

#define FN1      MO(_FN1)
#define FN2      MO(_FN2)
#define FN3      MO(_FN3)
#define FN4      MO(_FN4)
#define FN5      MO(_FN5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |BKSP  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |ENTER |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | SHIFT|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  UP  |SHIFT |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Fn1  | Fn2  | CTRL | ALT  | GUI  |    Space    | GUI  | Fn3  | LEFT | DOWN |RIGHT |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_planck_grid(
        KC_GESC, KC_Q,  KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,  KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,
        FN1,     FN2,   KC_LCTL, KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_RGUI, FN3,     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* Fn1
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | CAPS |CTRL+A|CTRL+S|CTRL+D|CTRL+F|CTRL+G|CTRL+H|CTRL+J|CTRL+K|   _  |   +  | "    |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |CTRL+Z|CTRL+X|CTRL+C|CTRL+V|CTRL+B|CTRL+N|CTRL+M|      |   /  |Pg Up |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Fn4  |      |      |      |             |      |      |LAlt+L|Pg Dn |LAlt+R|
    * `-----------------------------------------------------------------------------------'
    */
    [_FN1] = LAYOUT_planck_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_DEL,
        KC_CAPS, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G), G(KC_H), G(KC_J), G(KC_K), KC_MINS,    KC_EQL,  KC_QUOT,
        KC_TRNS, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), G(KC_N), G(KC_M), KC_TRNS, KC_SLSH,    KC_PGUP, KC_RSFT,
        KC_TRNS, FN4,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, A(KC_LEFT), KC_PGDN, A(KC_RIGHT)
    ),

    /* Fn2
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Ins  |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |   [  |  ]   | \    |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |   /  |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Fn4  |      |      |      |      |             |      |      | Home |      | End  |
    * `-----------------------------------------------------------------------------------'
    */
    [_FN2] = LAYOUT_planck_grid(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_INS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_RBRC, KC_BSLS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS, KC_TRNS,
        FN4,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END
    ),


    /* Fn3
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      | F11  |  F12 | DEBUG|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |   /  |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FN3] = LAYOUT_planck_grid(
        KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_F11,  KC_F12,  DEBUG,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_TRNS, KC_END
    ),

    /* Fn4
    * ,-----------------------------------------------------------------------------------.
    * |WIN/ |      |      |      |      |      |      |      |      |      |      |RGBTOG|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |  Fn5 |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FN4] = LAYOUT_planck_grid(
        CG_TOGG, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RGB_TOG,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   FN5,     KC_NO,   KC_NO,   KC_NO
    ),

    /* Fn5
    * ,-----------------------------------------------------------------------------------.
    * |EEPROM|      |      |      |      |      |      |      |      |      |      | RESET|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |  Fn5 |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_FN5] = LAYOUT_planck_grid(

        EEP_RST, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO
    )
};

/* encoder handler */
bool encoder_update_user(uint8_t index, bool clockwise) {
    // use encoder as PgUp/PgDn
    if (clockwise) {
        tap_code(KC_WH_U);
    } else {
        tap_code(KC_WH_D);
    }
    return false;
}
