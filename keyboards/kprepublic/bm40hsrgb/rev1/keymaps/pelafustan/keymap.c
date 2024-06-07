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

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define DEBOUNCE_CAPS_DELAY 100

enum layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
};

typedef enum {
    NONE,
    UNKNOWN,
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
} td_state_t;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

enum {
    LSFT_CAPS,
    RSFT_QUOTE,
    SCLN_CLN,
};

td_state_t cur_dance(tap_dance_state_t *state);

void lsft_finished(tap_dance_state_t *state, void *user_data);
void lsft_reset(tap_dance_state_t *state, void *user_data);

void rsft_finished(tap_dance_state_t *state, void *user_data);
void rsft_reset(tap_dance_state_t *state, void *user_data);

void scln_finished(tap_dance_state_t *state, void *user_data);
void scln_reset(tap_dance_state_t *state, void *user_data);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | BKSP |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  |ENTER |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | SHIFT|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BLTOG| CTRL | ALT  | GUI  |LOWER |    SPACE    |RAISE | ALT  | PSCR | CTRL | SHIFT|
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_mit(
  LT(_NUM, KC_TAB), KC_Q,         KC_W,         KC_E,         KC_R,                KC_T,    KC_Y,  KC_U,                KC_I,         KC_O,         KC_P,         KC_BSPC,
  LCTL_T(KC_ESC),   LSFT_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), KC_F,                KC_G,    KC_H,  KC_J,                LGUI_T(KC_K), LALT_T(KC_L), TD(SCLN_CLN), LCTL_T(KC_ENT),
  TD(LSFT_CAPS),    KC_Z,         KC_X,         KC_C,         KC_V,                KC_B,    KC_N,  KC_M,                KC_COMM,      KC_DOT,       KC_SLSH,      TD(RSFT_QUOTE),
  RGB_TOG,          KC_LCTL,      KC_LALT,      KC_LGUI,      LT(_LOWER, KC_LBRC),     KC_SPC,     LT(_RAISE, KC_RBRC), KC_RALT,      KC_PSCR,      KC_RCTL,      KC_BSLS
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
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_CIRC, KC_AMPR, KC_LPRN,  KC_RPRN, KC_DEL,
  KC_TILD, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, XXXXXXX, XXXXXXX, KC_RCBR, KC_HOME, KC_END,   _______, _______,
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
  KC_GRV,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_DEL,  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_APP,  KC_F6,   KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN, KC_BSLS,
  KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F11,  KC_F12,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
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
  _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,     _______,      _______, _______, _______, _______, _______
),


[_NUM] = LAYOUT_planck_mit(
  _______, KC_LCTL, KC_LSFT, KC_LALT, _______, _______, _______, KC_7, KC_8,    KC_9,    KC_PAST, KC_PSLS,
  _______, KC_LPRN, KC_RPRN, KC_DEL , _______, _______, _______, KC_4, KC_5,    KC_6,    KC_PPLS, KC_PMNS,
  _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2,    KC_3,    KC_TAB,  KC_ENT,
  _______, _______, _______, _______, KC_BSPC,      _______,     KC_0, KC_DOT,  _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        return DOUBLE_TAP;
    }

    return UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'lsft' tap dance.
static td_tap_t lsft_tap_state = {
    .is_press_action = true,
    .state = NONE
};

// Create an instance of 'td_tap_t' for the 'rsft' tap dance.
static td_tap_t rsft_tap_state = {
    .is_press_action = true,
    .state = NONE
};

// Create an instance of 'td_tap_t' for the 'scln' tap dance.
static td_tap_t scln_tap_state = {
    .is_press_action = true,
    .state = NONE
};

void lsft_finished(tap_dance_state_t *state, void *user_data) {
    lsft_tap_state.state = cur_dance(state);
    switch (lsft_tap_state.state) {
        case SINGLE_TAP: register_code(KC_LSFT); register_code(KC_9); break;
        case SINGLE_HOLD: register_code(KC_LSFT); break;
        case DOUBLE_TAP: register_code(KC_CAPS); wait_ms(DEBOUNCE_CAPS_DELAY); break;
        default: break;
    }
}

void lsft_reset(tap_dance_state_t *state, void *user_data) {
    switch (lsft_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_9); unregister_code(KC_LSFT); break;
        case SINGLE_HOLD: unregister_code(KC_LSFT); break;
        case DOUBLE_TAP: unregister_code(KC_CAPS); break;
        default: break;
    }
    lsft_tap_state.state = NONE;
}

void rsft_finished(tap_dance_state_t *state, void *user_data) {
    rsft_tap_state.state = cur_dance(state);
    switch (rsft_tap_state.state) {
        case SINGLE_TAP: register_code(KC_QUOT); break;
        case SINGLE_HOLD: register_code(KC_RSFT); break;
        case DOUBLE_TAP: register_code(KC_RSFT); register_code(KC_QUOT); break;
        default: break;
    }
}

void rsft_reset(tap_dance_state_t *state, void *user_data) {
    switch (rsft_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_QUOT); break;
        case SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case DOUBLE_TAP: unregister_code(KC_QUOT); unregister_code(KC_RSFT); break;
        default: break;
    }
    rsft_tap_state.state = NONE;
}

void scln_finished(tap_dance_state_t *state, void *user_data) {
    scln_tap_state.state = cur_dance(state);
    switch (scln_tap_state.state) {
        case SINGLE_TAP: register_code(KC_SCLN); break;
        case SINGLE_HOLD: register_code(KC_RSFT); break;
        case DOUBLE_TAP: register_code(KC_RSFT); register_code(KC_SCLN); break;
        default: break;
    }
}

void scln_reset(tap_dance_state_t *state, void *user_data) {
    switch (scln_tap_state.state) {
        case SINGLE_TAP: unregister_code(KC_SCLN); break;
        case SINGLE_HOLD: unregister_code(KC_RSFT); break;
        case DOUBLE_TAP: unregister_code(KC_RSFT); unregister_code(KC_SCLN); break;
        default: break;
    }
    scln_tap_state.state = NONE;
}

tap_dance_action_t tap_dance_actions[] = {
    [LSFT_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lsft_finished, lsft_reset),
    [RSFT_QUOTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, rsft_finished, rsft_reset),
    [SCLN_CLN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, scln_finished, scln_reset),
};
