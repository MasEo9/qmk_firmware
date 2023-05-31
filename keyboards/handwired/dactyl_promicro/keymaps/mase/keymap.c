#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LWR_ENT LT(_LOWER, KC_ENT)
#define UNDO LCTL(KC_Z)
#define CTLZ CTL_T(KC_Z)
#define CTLSLSH CTL_T(KC_SLSH)
#define LG_QUOT LGUI_T(KC_QUOT)
#define ALT_MNU LALT_T(KC_MENU)
#define TD_LEFT TD(TD_HOME_LEFT)
#define TD_RGT TD(TD_END_RIGHT)
#define TD_UP TD(TD_PGUP_UP)
#define TD_DOWN TD(TD_PGDWN_DOWN)
#define RCS_RGT RCS(KC_RIGHT)
#define RCS_LFT RCS(KC_LEFT)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RIGHT)
#define TD_DELT TD(TD_DEL)
#define RAISE MO(_RAISE)
#define REDO LCTL(KC_Y)
#define CTSTAR LCTL(LSFT(KC_LEFT))

enum {
  TD_HOME_LEFT,
  TD_END_RIGHT,
  TD_PGUP_UP,
  TD_PGDWN_DOWN
};

tap_dance_action_t tap_dance_actions[] = {
	[TD_HOME_LEFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
	[TD_END_RIGHT]  = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    [TD_PGUP_UP]    = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
    [TD_PGDWN_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN)
    };

/* Keymap: 
 *
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Del  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |'/Cmd |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|Z/Ctrl|   X  |   C  |   V  |   B  |                    |   N  |   M  |   ,  |   .  | /Ctrl|RShift|
 * |------+------+------+------+------+------'                    `------+------+------+------+------+------|
 * |Grv/L1|      |AltShf| Left | Right|                                  |  Up  | Down |      |      |      |
 * `----------------------------------'                                  `----------------------------------'
 *                                      ,-------------.  ,-------------.
 *                                      | Undo | LGui |  | Alt  | ^/Esc|
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Home |  | PgUp |      |      |
 *                               | Space|LwrEnt|------|  |------|Raise |BackSP|
 *                               |      |      | End  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                        KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, LG_QUOT,
        KC_LSFT, CTLZ   , KC_X   , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, KC_DOT , CTLSLSH, KC_RSFT,
        QK_BOOT, DB_TOGG, XXXXXXX, CTSTAR , KC_LALT,                                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
        UNDO   , KC_LGUI, KC_SPC , LWR_ENT, KC_HOME, KC_END ,                                        KC_RALT, KC_PGDN, KC_PGUP, RAISE  , KC_BSPC, KC_ESC  
    ),
    [_LOWER] = LAYOUT_6x6(
        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                                        KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
        _______, XXXXXXX, RCS_LFT, TD_UP  , RCS_RGT, XXXXXXX,                                        KC_ASTR, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, _______,
        _______, CTL_LFT, TD_LEFT, TD_DOWN, TD_RGT , CTL_RGT,                                        KC_EQL , KC_LPRN, KC_RPRN, KC_PERC, KC_EXLM, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_HASH, KC_LCBR, KC_RCBR, KC_AT  , KC_AMPR, _______,
        _______, _______, _______, _______, _______, _______,                                        KC_DLR , _______, _______, _______, _______, _______,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    ),
    [_RAISE] = LAYOUT_6x6(
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, RCS_LFT, TD_UP  , RCS_RGT, XXXXXXX,                                        KC_PAST, KC_7   , KC_8   , KC_9   , KC_PMNS, _______,
        _______, CTL_LFT, TD_LEFT, TD_DOWN, TD_RGT , CTL_RGT,                                        KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_PDOT, KC_1   , KC_2   , KC_3   , KC_PAST, _______,
        _______, _______, _______, _______, _______, _______,                                        _______, KC_0   , KC_0   , _______, _______, _______,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    ),
      [_ADJUST] = LAYOUT_6x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, XXXXXXX, KC_MSTP, KC_VOLU, KC_MPLY, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLD, KC_MNXT, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_matrix=true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}