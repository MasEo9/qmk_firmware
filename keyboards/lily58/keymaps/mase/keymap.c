#include QMK_KEYBOARD_H
#include <stdio.h>

extern uint8_t is_master;
uint8_t mod_state;

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

enum {
  TD_HOME_LEFT,
  TD_END_RIGHT,
  TD_PGUP_UP,
  TD_PGDWN_DOWN
};

qk_tap_dance_action_t tap_dance_actions[] = {
	[TD_HOME_LEFT]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
	[TD_END_RIGHT]  = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT, KC_END),
    [TD_PGUP_UP]  = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
    [TD_PGDWN_DOWN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN)
    };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | GRV  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  UNDO |    |       |------+------+------+------+------+------|
 * |LShift| CTLZ |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |CTLSLH|RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |ALTMNU|Space | /Enter  /       \RAISE \  |BackSP  | ALTMNU|      |
 *                   |      |      |      |/       /         \      \ |        |       |      |
 *                   `----------------------------'           '------''-----------------------'
 */

 [_QWERTY] = LAYOUT( \
   KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS, \
   KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS, \
   KC_TAB , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, LG_QUOT, \
   KC_LSFT, CTLZ   , KC_X   , KC_C   , KC_V   , KC_B   , UNDO   , XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , CTLSLSH, KC_RSFT, \
                              XXXXXXX, ALT_MNU, KC_SPC , LWR_ENT, RAISE  , KC_BSPC, ALT_MNU, XXXXXXX   \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | RCSL |  UP  | RCSR |      |                    |   *  |   7  |   8  |   9  |  -   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | CTLL | LEFT | DOWN | RIGHT| CTLR |-------.    ,-------|   /  |   4  |   5  |   6  |  +   |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   0  |   1  |   2  |   3  |  *   |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |   0  |   0  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, \
  _______, XXXXXXX, RCS_LFT, TD_UP  , RCS_RGT, XXXXXXX,                   KC_PAST, KC_7   , KC_8   , KC_9   , KC_PMNS, _______, \
  _______, CTL_LFT, TD_LEFT, TD_DOWN, TD_RGT , CTL_RGT,                   KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PPLS, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, KC_PDOT, KC_1   , KC_2   , KC_3   , KC_PAST, _______, \
                             _______, _______, _______, _______, _______, _______, KC_0   , KC_0   \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      | RCSL |  UP  | RCSR |      |                    |   *  |   [  |   ]  |   _  |   |  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | CTLL | LEFT | DOWN | RIGHT| CTLR |-------.    ,-------|   =  |   (  |   )  |   %  |   !  |      |
 * |------+------+------+------+------+------|       |    |   $   |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   #  |   {  |   }  |   @  |   &  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
 [_LOWER] = LAYOUT( \
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  ,  KC_F5  ,                   KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
  _______, XXXXXXX, RCS_LFT, TD_UP  , RCS_RGT,  XXXXXXX,                   KC_ASTR, KC_LBRC, KC_RBRC, KC_UNDS, KC_PIPE, _______, \
  _______, CTL_LFT, TD_LEFT, TD_DOWN, TD_RGT ,  CTL_RGT,                   KC_EQL , KC_LPRN, KC_RPRN, KC_PERC, KC_EXLM, _______, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, _______, KC_DLR , KC_HASH, KC_LCBR, KC_RCBR, KC_AT  , KC_AMPR, _______, \
                             _______, _______,  _______, _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RESET |      | Stop | VolUp|PsePly|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |PrvTrk|VolDwn|NxtTrk|      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      | Mute |      |      |-------|    |-------|      | RMOD | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */ 
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET  , XXXXXXX, KC_MSTP, KC_VOLU, KC_MPLY, XXXXXXX,                   XXXXXXX, XXXXXXX, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, KC_MNXT, KC_VOLD, KC_MNXT, XXXXXXX,                   XXXXXXX, RGB_SPI, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  _______, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_SPD, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, \
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    } else {
        return OLED_ROTATION_0;
    }
}

void render_lily58_logo(void) {
    static const char PROGMEM lily58_logo[] = {
    // 'logo', 128x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0x40, 0x40, 0xc0, 0x80, 0x80, 0x80, 0x00, 0x00,
    0x80, 0xe0, 0x70, 0x3c, 0x0e, 0x06, 0x0e, 0x3c, 0x70, 0xe0, 0x80, 0x00, 0x00, 0xc0, 0xc0, 0x00,
    0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x80,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0xc0, 0x80, 0x80, 0x80, 0x81, 0x83, 0x83,
    0x07, 0x07, 0x0c, 0x18, 0x70, 0xe0, 0x80, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x80, 0xb6, 0xb6, 0x80,
    0xb0, 0xb0, 0x00, 0x36, 0x36, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf1, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x00, 0x00, 0x00, 0x30, 0xf0, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xf0, 0xf0,
    0x30, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xe1, 0x71, 0x71, 0xf1, 0xf1, 0xe1, 0xc1, 0x81, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x3f, 0xff, 0xf3, 0xe1, 0xc1, 0xc1, 0x81, 0x81, 0xc3, 0xff, 0x7f, 0x1c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x20, 0x70, 0x78, 0xdc, 0xcc, 0x86, 0x06, 0x03, 0x03, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x03, 0x02, 0x06, 0x84, 0xe1, 0xfb, 0x38, 0x1c, 0x0c, 0x02, 0x01, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x03, 0x03, 0x06, 0x86, 0xcc, 0xdc, 0x78, 0x70, 0x20, 0x00, 0xff, 0xff, 0x80, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x1f, 0x7e, 0xf8, 0xe0, 0xf0, 0x7e, 0x1f, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xe0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe1, 0xff, 0x7f, 0x3f, 0x00,
    0x00, 0x00, 0x3e, 0xff, 0xff, 0xc1, 0xc0, 0x80, 0x81, 0x81, 0xc3, 0xc3, 0xff, 0xfe, 0x3c, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x06, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04, 0x06,
    0x06, 0x02, 0x03, 0x01, 0x01, 0x00, 0x01, 0x01, 0x03, 0x02, 0x06, 0x06, 0x04, 0x04, 0x04, 0x04,
    0x06, 0x06, 0x06, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01,
    0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x01, 0x01, 0x01, 0x00, 0x00, 0x60, 0x60, 0x70, 0x38, 0x1f, 0x0f, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x00
};
    oled_write_raw_P(lily58_logo, sizeof(lily58_logo));
}


#define KEYLOG_LEN 6
char     keylog_str[KEYLOG_LEN] = {};
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN - 1; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN - 1] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}

void render_keylogger_status(void) {
    oled_write_P(PSTR("KLogr"), false);
    oled_write(keylog_str, false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("Layer"), false);
    oled_write_P(PSTR(" "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QRTY"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("LOW"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("HIGH"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("ADJ"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

void render_keylock_status(led_t led_state) {
    oled_write_ln_P(PSTR("Lock"), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("N"), led_state.num_lock);
    oled_write_P(PSTR("C"), led_state.caps_lock);
    oled_write_ln_P(PSTR("S"), led_state.scroll_lock);
}

// void render_mod_status(uint8_t modifiers) {
//     oled_write_ln_P(PSTR("Mods"), false);
//     oled_write_P(PSTR(" "), false);
//     oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
//     oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
//     oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
//     oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
// }

void render_rgb_status(void) {
    oled_write_ln_P(PSTR("RGB"), false);
    static char temp[20] = {0};
    snprintf(temp, sizeof(temp) + 1, "  %3d", rgb_matrix_config.mode);
    oled_write(temp, false);
}

void wpm_status(void) {
    oled_write_ln_P(PSTR("WPM"), false);
    static char wpm_str[20] = {0};
    snprintf(wpm_str, sizeof(wpm_str) + 1, "  %3d", get_current_wpm());
    oled_write(wpm_str, false);
}


void render_status_main(void) {
    // Show keyboard layout
    render_default_layer_state();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show host keyboard led status
    render_keylock_status(host_keyboard_led_state());
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Show modifier status
    wpm_status();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    // Add a empty line
    render_rgb_status();
    // Add a empty line
    oled_write_P(PSTR("-----"), false);
    render_keylogger_status();
}

bool oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_lily58_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode); 
        
        //shift delete and enter
        mod_state = get_mods();
        switch (keycode) {

        case KC_BSPC:
            {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
        }
        return true;
        //end shift delete and enter
    }
    return true;
};
#endif