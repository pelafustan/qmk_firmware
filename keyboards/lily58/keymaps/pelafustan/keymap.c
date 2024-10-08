#include QMK_KEYBOARD_H

enum layer_number {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
    _NUMPAD,
    _ADJUST,
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
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

  [_QWERTY] = LAYOUT(
    KC_ESC,              KC_1, KC_2, KC_3, KC_4, KC_5,                   KC_6, KC_7, KC_8,    KC_9,    KC_0,    KC_MINS,
    LT(_NUMPAD, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T,                   KC_Y, KC_U, KC_I,    KC_O,    KC_P,    KC_BSPC,
    LSFT_T(KC_ESC),      KC_A, KC_S, KC_D, KC_F, KC_G,                   KC_H, KC_J, KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
    KC_LCTRL,            KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LCBR, KC_RCBR, KC_N, KC_M, KC_COMM, KC_DOT,  KC_SLSH, RCTL_T(KC_BSLS),
                KC_LALT, KC_LGUI, LT(_LOWER, KC_LBRC), KC_SPC,  KC_ENT,  LT(_RAISE, KC_RBRC), KC_RALT, RGUI_T(KC_APP)
  ),
  /* LOWER
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   -  |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      |   _  |   +  |   {  |   }  |   |  |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_LOWER] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_CIRC, KC_AMPR, KC_LPRN,  KC_RPRN, KC_BSPC,
    KC_DEL,  KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PSCR, KC_HOME, KC_END,   _______, _______, _______,
                               _______, _______, _______, _______, _______, _______, KC_DEL, _______
  ),
  /* RAISE
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
   * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
   * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */

  [_RAISE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_GRV,  KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,  KC_BSPC,
    _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                   XXXXXXX, KC_MINS, KC_EQL,  KC_PGUP, KC_PGDN, KC_BSLS,
    KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX, _______, _______, XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_7,    KC_8,    KC_9,    KC_PAST, KC_PSLS,
    XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_4,    KC_5,    KC_6,    KC_PPLS, KC_PMNS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_TAB,  KC_ENT,
                               _______, _______, _______, KC_DEL , KC_BSPC, KC_0,    KC_DOT,  _______
  ),
  /* ADJUST
   * ,-----------------------------------------.                    ,-----------------------------------------.
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
   * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
   * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
   * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
   * `-----------------------------------------/       /     \      \-----------------------------------------'
   *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
   *                   |      |      |      |/       /         \      \ |      |      |      |
   *                   `----------------------------'           '------''--------------------'
   */
  [_ADJUST] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, _______, _______, _______, _______, _______, _______, _______
)};

layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
        // oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
        // oled_write_ln(read_host_led_state(), false);
        // oled_write_ln(read_timelog(), false);
    } else {
        oled_write(read_logo(), false);
    }
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }
    return true;
}

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
