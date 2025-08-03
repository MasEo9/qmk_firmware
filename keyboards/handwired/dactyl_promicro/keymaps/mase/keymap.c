#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _QWERTY = 0,
  _NAV,
  _SYM,
  _NUM,
  _MEDIA,
  _FUN,
};

// layers
// nav
#define NAV_SPC LT(_NAV, KC_SPC)
// sym
#define SYM_BK LT(_SYM, KC_BSPC)
// media
#define MDA_TAB LT(_MEDIA, KC_TAB)

//tmux
#define TMUX LCTL(KC_S)

// homerow mods
// left
#define HRM_A MT(MOD_LGUI, KC_A)
#define HRM_S MT(MOD_LALT, KC_S)
#define HRM_D MT(MOD_LSFT, KC_D)
#define HRM_F MT(MOD_LCTL, KC_F)
// right
#define HRM_SCL MT(MOD_LGUI, KC_SCLN)
#define HRM_L MT(MOD_LALT, KC_L)
#define HRM_K MT(MOD_LSFT, KC_K)
#define HRM_J MT(MOD_LCTL, KC_J)

/* Keymap:
tap_dance_action_t tap_dance_actions[] = {
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
 *                                      | BOOT | LGui |  | Esc  | Alt  |
 *                               ,------|------|------|  |------+------+------.
 *                               |      |      | Alt  |  | PgUp |      |      |
 *                               | Space|LwrEnt|------|  |------|TbRas |BackSP|
 *                               |      |      | Esc  |  | PgDn |      |      |
 *                               `--------------------'  `--------------------'
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_6x6(
        KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                        KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                        KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_MINS,
        KC_LCTL, HRM_A  , HRM_S  , HRM_D  , HRM_F  , KC_G   ,                                        KC_H   , HRM_J  , HRM_K  , HRM_L  , HRM_SCL, KC_RCTL,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                        KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RGUI,
        KC_LGUI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        QK_BOOT, KC_LGUI, NAV_SPC, KC_ENT, KC_LALT, KC_ESC ,                                        KC_RALT, TMUX   , KC_PGUP, MDA_TAB , SYM_BK , KC_ESC
    ),
    [_NAV] = LAYOUT_6x6(
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, KC_HOME, KC_UP  , KC_PGUP, XXXXXXX,                                        KC_PSLS, KC_7   , KC_8   , KC_9   , KC_PAST, _______,
        _______, XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                                        KC_PMNS, KC_4   , KC_5   , KC_6   , KC_PPLS, _______,
        _______, XXXXXXX, KC_END , XXXXXXX, KC_PGDN, XXXXXXX,                                        KC_0   , KC_1   , KC_2   , KC_3   , KC_PERC, _______,
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    ),
    [_SYM] = LAYOUT_6x6(
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
        _______, KC_GRV , KC_LT  , KC_GT  , KC_PMNS, KC_UNDS,                                        KC_PSLS, KC_LCBR, KC_RCBR, KC_DLR , KC_PIPE, _______,
        _______, KC_EXLM, KC_ASTR, KC_SLSH, KC_EQL , KC_AMPR,                                        KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_COLN, _______,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                                        KC_AT  , KC_DQUO, KC_COMM, KC_DOT , KC_QUOT, _______,
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, _______,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    ),
      [_FUN] = LAYOUT_6x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_F7  , KC_F8  , KC_F9  , KC_F12 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_F4  , KC_F5  , KC_F6  , KC_F11 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F10 , XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                     _______, _______, _______,    _______, _______, _______,
                                                                       _______,    _______,
                                                                       _______,    _______
    ),
      [_MEDIA] = LAYOUT_6x6(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        KC_VOLD ,KC_VOLU, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
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



//layer_state_t layer_state_set_user(layer_state_t state) {
//    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
//    return state;
//}
