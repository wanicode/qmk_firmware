/* Copyright 2015-2017 Jack Humbert
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

extern keymap_config_t keymap_config;

#define _BASE 0
#define _SYMB 1
#define _NAVI 2
#define _NUMP 3
#define _CONF 4

// layer colors
#define RGBLIGHT_COLOR_LAYER_0 360,0x00,0xFF
#define RGBLIGHT_COLOR_LAYER_1 0,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_2 240,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_3 120,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_4 270,0xFF,0xFF

// more pronounced empty keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Key aliases
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define TG_CONF TG(_CONF)

#define WC_PRNT LSFT(LGUI(KC_4))
#define WC_1PW  LGUI(KC_BSLS)
#define WC_1PWM LALT(LGUI(KC_BSLS))

#define WC_SFTT LSFT_T(KC_T)
#define WC_ALTS LALT_T(KC_S)
#define WC_CTLR LCTL_T(KC_R)
#define WC_SFTN LSFT_T(KC_N)
#define WC_NUMD LT(_NUMP, KC_D)
#define WC_NAVA LT(_NAVI, KC_A)
#define WC_ALTE LALT_T(KC_E)
#define WC_CTLI LCTL_T(KC_I)
#define WC_GUIS LGUI_T(KC_SPC)
#define WC_GUIE LGUI_T(KC_ENT)
#define WC_SYME LT(_SYMB, KC_ESC)
#define WC_SYMB LT(_SYMB, KC_BSPC)

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   * ,-----------------------------------------------------------------------------------------------.
   * |       |   Q   |   W   |   F   |   P   |   B   |   J   |   L   |   U   |   Y   |   ;   | 1PWD  |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   R   |   S   |   T   |   G   |   K   |   N   |   E   |   I   |   O   |   '   |
   * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
   * |       |   Z   |   X   |   C   |   D   |   V   |   M   |   H   |   ,   |   .   |   /   |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |  ESC  | Space | Enter | BSpace|       |       |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_BASE] = LAYOUT_ortho_4x12(
    TG_CONF, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, WC_1PW,
    KC_TAB,  WC_NAVA, WC_CTLR, WC_ALTS, WC_SFTT, KC_G,    KC_K,    WC_SFTN, WC_ALTE, WC_CTLI, KC_O,    KC_QUOT,
    _______, KC_Z,    KC_X,    KC_C,    WC_NUMD, KC_V,    KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, WC_GUIS, WC_SYME, WC_SYMB, WC_GUIE, _______, _______, _______, _______
  ),

  /* Symbols
   * ,-----------------------------------------------------------------------------------------------.
   * |       |       |   ^   |   @   |   +   |   /   |   \   |   -   |   _   |   #   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   [   |   {   |   <   |   (   |   !   |   ?   |   )   |   >   |   }   |   ]   |       |
   * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
   * |       |       |   ~   |   %   |   $   |   &   |   |   |   =   |   `   |   *   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |       |       |       |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_SYMB] = LAYOUT_ortho_4x12(
    _______, _______, KC_CIRC, KC_AT,   KC_PLUS, KC_SLSH, KC_BSLS, KC_MINS, KC_UNDS, KC_HASH, _______, _______,
    _______, KC_LBRC, KC_LCBR, KC_LABK, KC_LPRN, KC_EXLM, KC_QUES, KC_RPRN, KC_RABK, KC_RCBR, KC_LBRC, _______,
    _______, _______, KC_TILD, KC_PERC, KC_DLR,  KC_AMPR, KC_PIPE, KC_EQL,  KC_GRV,  KC_ASTR, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Navigation
   * ,-----------------------------------------------------------------------------------------------.
   * |       |       |       |       |       |       |       |       |  UP   |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       | LEFT  | DOWN  | RIGHT |       |       |
   * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |       |       |       |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_NAVI] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  ),

  /* Numpad
   * ,-----------------------------------------------------------------------------------------------.
   * |       |       |       |       |       |       |       |   7   |   8   |   9   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |   #   |   4   |   5   |   6   |       |       |
   * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |   1   |   2   |   3   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |   0   |   0   |   .   |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_NUMP] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, _______,
    _______, _______, _______, _______, _______, _______, KC_HASH, KC_4,    KC_5,    KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_0,    KC_PDOT, _______, _______
  ),

  /* Config
   * ,-----------------------------------------------------------------------------------------------.
   * |       |       |       |       |       |       |       |   7   |   8   |   9   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |   #   |   4   |   5   |   6   |       |       |
   * |-------+-------+-------+-------+-------+-------|-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |   1   |   2   |   3   |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |       |       |   0   |   0   |   .   |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_CONF] = LAYOUT_ortho_4x12(
    _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, RESET,
    _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______, _______
  )
};


#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  }
  return true;
}
