/* Copyright 2023 Etienne Collin (@etiennecollin)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define LT_ENT LT(2, KC_ENT)
#define LT_TAB LT(1, KC_TAB)
#define MD_QUOT MT(MOD_RCTL, KC_QUOT)

// homerow mods
#define A_GUI MT(MOD_LGUI, KC_A)
#define S_ALT MT(MOD_LALT, KC_S)
#define D_SHFT MT(MOD_LSFT, KC_D)
#define F_CTL MT(MOD_LCTL, KC_F)
#define J_CTL MT(MOD_RCTL, KC_J)
#define K_SHFT MT(MOD_RSFT, KC_K)
#define L_ALT MT(MOD_LALT, KC_L)
#define SC_GUI MT(MOD_RGUI, KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
        A_GUI,   S_ALT,  D_SHFT,    F_CTL,   KC_G,                                  KC_H,   J_CTL,   K_SHFT,  L_ALT,  SC_GUI,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
                                          QK_GESC,  KC_SPC,  LT_ENT,     LT_TAB, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
  ),
    [1] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_PGDN, KC_PGUP,  KC_GRV,                               KC_MINS,    KC_4,    KC_5,    KC_6, KC_PLUS,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                  KC_0,    KC_1,    KC_2,    KC_3,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
      KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                               KC_CIRC,  KC_LPRN, KC_RPRN, KC_AMPR,KC_ASTR,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT,                                KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT,KC_PIPE,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               KC_UNDS,  KC_LCBR, KC_RCBR, KC_TILD,KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                 _______, _______, _______,      MO(3), _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,   KC_F7,   KC_F8,   KC_F9,  KC_F10,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,   KC_F4,   KC_F5,   KC_F6, QK_BOOT,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX,   KC_F1,   KC_F2,   KC_F3, XXXXXXX,
  //|--------+--------+--------+----- --+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [4] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, KC_MPRV, XXXXXXX, KC_MPLY, KC_MNXT,                               KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, XXXXXXX,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
                                        _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
    [5] = LAYOUT_split_3x5_3(
  //,--------------------------------------------.                             ,---------------------------------------------.
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                  KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                  KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
  //|--------+--------+--------+ -------+ -------|                             |--------+--------+--------+--------+--------|
                                          QK_GESC,  KC_SPC,  LT_ENT,     LT_TAB, KC_BSPC, KC_DEL
                                      //`--------------------------'  `--------------------------'
    )
};

