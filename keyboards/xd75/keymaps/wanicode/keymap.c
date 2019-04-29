/* Copyright 2017 Wunder
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
#include "xd75.h"
#include QMK_KEYBOARD_H
#include "wanicode.h"

void tap(uint16_t keycode){ register_code(keycode); unregister_code(keycode); };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | GAME   |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * |        | Q      | W      | F      | P      | B      |        |        |        | J      | L      | U      | Y      | ;      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TAB    | A      | R      | S      | T      | G      |        |        |        | K      | N      | E      | I      | O      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | SHIFT  | Z      | X      | C      | D      | V      |        |        |        | M      | H      | ,      | .      | /      | SHIFT  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CTRL   | ALT    |        | SPACE  | SPACE  | ESC    |        |        |        | ENTER  | BSPACE | DEL    |        | ALT    | CTRL   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_BASE] = LAYOUT_ortho_5x15_wrapper( /* Colemak DH */
   WC_GAME, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   KC_ESC,  _____________COLEMAK_MOD_DH_L1_____________, _______, _______, _______, _____________COLEMAK_MOD_DH_R1_____________, _______,
   WC_NAVT, _____________COLEMAK_MOD_DH_L2_____________, _______, _______, _______, _____________COLEMAK_MOD_DH_R2_____________, KC_QUOT,
   KC_LSFT, _____________COLEMAK_MOD_DH_L3_____________, _______, _______, _______, _____________COLEMAK_MOD_DH_R3_____________, KC_RSFT,
   KC_HYPR, _____________COLEMAK_MOD_DH_L4_____________, _______, _______, _______, _____________COLEMAK_MOD_DH_R4_____________, KC_HYPR
 ),

/* SYMBOLS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | !      | @      | +      | '      |        |        |        | "      | -      | _      | \      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | [      | {      | <      | (      | ^      |        |        |        | #      | )      | >      | }      | ]      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | ~      | %      | $      | &      |        |        |        | |      | =      | `      | *      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_SYMB] = LAYOUT_ortho_5x15_wrapper( /* Symbols */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _________________SYMBOLS_L1________________, _______, _______, _______, _________________SYMBOLS_R1________________, _______,
   _______, _________________SYMBOLS_L2________________, _______, _______, _______, _________________SYMBOLS_R2________________, _______,
   _______, _________________SYMBOLS_L3________________, _______, _______, _______, _________________SYMBOLS_R3________________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* NAVIGATION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        | UP     |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | LEFT   | DOWN   | RIGHT  |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NAVI] = LAYOUT_ortho_5x15_wrapper( /* Navigation */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _________________NAVIGATION_ROW1___________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _________________NAVIGATION_ROW2___________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

/* NUMPAD
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | #      | 4      | 5      | 6      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 1      | 2      | 3      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 0      | 0      | .      |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUMP] = LAYOUT_ortho_5x15_wrapper( /* NumPad */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _________________NUMBERS_LEFT______________, _______, _______, _______, _________________NUMBERS_RIGHT_____________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _________________NUMPAD_ROW2_______________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _________________NUMPAD_ROW3_______________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _________________NUMPAD_ROW4_______________, _______
 ),

/* FUNCTIONS
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | #      | 4      | 5      | 6      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 1      | 2      | 3      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | 0      | 0      | .      |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_FUNC] = LAYOUT_ortho_5x15_wrapper( /* NumPad */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _______________RFUNCPAD_ROW1_______________, _______, _______, _______, ________________FUNCPAD_ROW1_______________, _______,
   _______, _______________RFUNCPAD_ROW2_______________, _______, _______, _______, ________________FUNCPAD_ROW2_______________, _______,
   _______, _______________RFUNCPAD_ROW3_______________, _______, _______, _______, ________________FUNCPAD_ROW3_______________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),


 /* MACRO
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | LOCK   |        | PRINT  | 1PWD   |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        | 1PWD M |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_MCRO] = LAYOUT_ortho_5x15_wrapper( /* Macros */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
   _______, _________________MACROS_L1_________________, _______, _______, _______, _________________MACROS_R1_________________, _______,
   _______, _________________MACROS_L2_________________, _______, _______, _______, _________________MACROS_R2_________________, _______,
   _______, _________________MACROS_L3_________________, _______, _______, _______, _________________MACROS_R3_________________, _______,
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
 ),

 /* CONFIG
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        | RESET  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        |        | TGL RGB|        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_CONF] = LAYOUT_ortho_5x15_wrapper( /* Configuration */
   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET  ,
   _______, _________________CONFIG_L1_________________, _______, _______, _______, _________________CONFIG_R1_________________, _______,
   _______, _________________CONFIG_L2_________________, _______, _______, _______, _________________CONFIG_R2_________________, _______,
   _______, _________________CONFIG_L3_________________, _______, _______, _______, _________________CONFIG_R3_________________, _______,
   _______, _________________CONFIG_L4_________________, _______, _______, _______, _________________CONFIG_R4_________________, _______
 ),


 /* GAME
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        | 1      | 2      | 3      | 4      | 5      |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | Q      | W      | E      | R      | T      |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | TAB    |        | A      | S      | D      | F      | G      |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | SHIFT  | Z      | X      | C      | V      | B      |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | CTRL   |        |        |        | ALT    | SPACE  |        |        |        |        |        |        |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_GAME] = LAYOUT_ortho_5x15_wrapper( /* To play games */
   WC_BASE, XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
   _______, XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
   KC_TAB,  XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
   XXXXXXX, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, _______, _______, _______, _______, _______, _______, _______,
   KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, KC_LALT, KC_SPC,  XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______, _______, _______
 ),
};

const uint16_t PROGMEM fn_actions[] = {

};


void matrix_scan_user(void) {
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
      case _BASE:
        break;
      case _SYMB:
        break;
      case _NAVI:
        break;
      case _NUMP:
        break;
      case _CONF:
        break;
      default:
        break;
    }

  return update_tri_layer_state(state, _MCRO, _FUNC, _CONF);
};