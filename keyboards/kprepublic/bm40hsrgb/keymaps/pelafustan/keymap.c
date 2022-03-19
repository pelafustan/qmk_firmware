/* Copyright 2020 tominabox1
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

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
};

enum {
  TD_ESC_GR,
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_ESC_GR] = ACTION_TAP_DANCE_DOUBLE(KC_TILD, KC_ESC),
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |  `   |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | BKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |ENTER |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTOG| CTRL | ALT  | GUI  |LOWER |    SPACE    |RAISE | ALT  | PSCR | CTRL | SHIFT|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
    LT(_NUM, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,                KC_T,    KC_Y,  KC_U,                KC_I,     KC_O,    KC_P,    KC_BSPC,
    TD(TD_ESC_GR),    KC_A,    KC_S,    KC_D,    KC_F,                KC_G,    KC_H,  KC_J,                KC_K,     KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,                KC_B,    KC_N,  KC_M,                KC_COMM,  KC_DOT,  KC_SLSH, RSFT_T(KC_QUOT),
    RGB_TOG,          KC_LCTL, KC_LALT, KC_LGUI, LT(_LOWER, KC_LBRC),     KC_SPC,     LT(_RAISE, KC_RBRC), KC_RALT,  KC_PSCR, KC_RCTL, KC_BSLS
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  | Shift| Ctrl | Alt  |  F4  |  F5  | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |  
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_CIRC, KC_AMPR, KC_LPRN,  KC_RPRN, KC_DEL,
    KC_DEL,  KC_LCTL, KC_LSFT, KC_LALT, KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_LCBR, KC_F11,  KC_F2,   KC_RCBR, KC_ASTR, KC_HOME,  KC_END,  _______,
    _______, _______, _______, _______, _______,      _______,     _______, KC_MNXT, KC_VOLD,  KC_VOLU, KC_MPLY
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LCBR, KC_RCBR, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______,     _______,      _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* aDJUST (lOWER + rAISE)
 *                      V------------------------rgb control--------------------V
 * ,-----------------------------------------------------------------------------------.
 * |      | rESET|dEBUG | rgb  |rgbmod| hue+ | hue- | sat+ | sat- |brgth+|brgth-|  dEL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_mit(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),


[_NUM] = LAYOUT_planck_mit(
    _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______, _______, KC_7, KC_8,    KC_9,    KC_PAST, KC_PSLS,
    _______, KC_LPRN, KC_RPRN, KC_DEL , _______, _______, _______, KC_4, KC_5,    KC_6,    KC_PPLS, KC_PMNS,
    _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,    KC_TAB,  KC_ENT,
    _______, _______, _______, _______, KC_BSPC,      _______,     KC_0, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
