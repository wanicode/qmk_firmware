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

// more pronounced empty keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define _BASE 0
#define _SYMB 1
#define _NAVI 2
#define _NUMP 3
#define _CONF 4

// layer colors
#define RGBLIGHT_COLOR_LAYER_0 360,0x00,0x00
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
#define WC_SFTN RSFT_T(KC_N)
#define WC_SFT4 RSFT_T(KC_4)
#define WC_ALTS LALT_T(KC_S)
#define WC_ALTE RALT_T(KC_E)
#define WC_ALT5 RALT_T(KC_5)
#define WC_CTLR LCTL_T(KC_R)
#define WC_CTLI RCTL_T(KC_I)
#define WC_CTL6 RCTL_T(KC_6)
#define WC_MGEN LGUI_T(KC_ENT)
#define WC_MGES RGUI_T(KC_ESC)
#define WC_GUID RGUI_T(KC_DEL)
#define WC_GUIH RGUI_T(KC_HASH)
#define WC_NUMD LT(_NUMP, KC_D)
#define WC_NAVA LT(_NAVI, KC_A)
#define WC_NUMS LT(_NUMP, KC_SPC)
#define WC_NUME LT(_NUMP, KC_ESC)
#define WC_SYMB LT(_SYMB, KC_BSPC)
#define WC_SYME LT(_SYMB, KC_ENT)

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1      | 2      | 3      | 4      | 5      | VOL UP | PLAY   | VOL DN | 6      | 7      | 8      | 9      | 0      | 1PWMINI|
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | TAB    | Q      | W      | F      | P      | B      |        | MUTE   |        | J      | L      | U      | Y      | ;      | 1PW    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | BSPC   | A      | R      | S      | T      | G      | HYPER  |        | MEH    | K      | N      | E      | I      | O      | '      |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | SHIFT  | Z      | X      | C      | D      | V      |        |        |        | M      | H      | ,      | .      | /      | SHIFT  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | CTRL   | ALT    |        | LEAD   | SPACE  | ESC    |        |        |        | ENTER  | BSPACE | DEL    |        | ALT    | CTRL   |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_BASE] = { /* Colemak DH */
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_VOLU, KC_MPLY, KC_VOLD, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______  },
  { KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    _______, KC_MUTE, _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC  },
  { KC_TAB,  WC_NAVA, WC_CTLR, WC_ALTS, WC_SFTT, KC_G,    OS_HYPR, _______, OS_MEH,  KC_K,    WC_SFTN, WC_ALTE, WC_CTLI, KC_O,    KC_QUOT  },
  { KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, _______, KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT   },
  { KC_LCTL, KC_LALT, _______, KC_LEAD, WC_NUMS, WC_MGEN, _______, WC_1PW,  _______, WC_MGES, WC_SYMB, KC_DEL,  _______, KC_RALT, KC_RCTL  },
 },

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

 [_SYMB] = { /* Symbols */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, KC_EXLM, KC_AT,   KC_PLUS, KC_QUOT, _______, _______, _______, KC_DQUO, KC_MINS, KC_UNDS, KC_BSLS, _______, _______  },
  { _______, KC_LBRC, KC_LCBR, KC_LABK, KC_LPRN, KC_CIRC, _______, _______, _______, KC_HASH, KC_RPRN, KC_RABK, KC_RCBR, KC_RBRC, _______  },
  { _______, _______, KC_TILD, KC_PERC, KC_DLR,  KC_AMPR, _______, _______, _______, KC_PIPE, KC_EQL,  KC_GRV,  KC_ASTR, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

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

 [_NAVI] = { /* Navigation */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
 },

/* NUMPAD
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | 1      | 2      | 3      | 4      | 5      |        |        |        | 6      | 7      | 8      | 9      | 0      |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F1     | F2     | F3     | F4     | F5     |        |        |        | F6     | 4      | 5      | 6      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        | F7     | F8     | F9     | F10    | F11    |        |        |        | F12    | 1      | 2      | 3      |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        |        |        |        |        |        |        |        | #      | 0      |        | .      |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

 [_NUMP] = { /* NumPad */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______, _______, _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______  },
  { _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______, _______, _______, KC_F6,   WC_SFT4, WC_ALT5, WC_CTL6, _______, _______  },
  { _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  _______, _______, _______, KC_F12,  KC_1,    KC_2,    KC_3,    _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HASH, KC_0,    _______, KC_PDOT, _______, _______  },
 },

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

 [_CONF] = { /* Configuration */
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  },
  { _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______  },
 }
};

const uint16_t PROGMEM fn_actions[] = {

};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // Mac Trigger 1Password
    SEQ_TWO_KEYS(KC_P, KC_W) {
      register_code(KC_LGUI);
      register_code(KC_BSLS);
      unregister_code(KC_BSLS);
      unregister_code(KC_LGUI);
    }

    // Mac Print Area
    SEQ_TWO_KEYS(KC_P, KC_R) {
      register_code(KC_LGUI);
      register_code(KC_LSFT);
      register_code(KC_4);
      unregister_code(KC_4);
      unregister_code(KC_LSFT);
      unregister_code(KC_LGUI);
    }
  }
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
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case _SYMB:
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case _NAVI:
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case _NUMP:
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case _CONF:
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      default:
        break;
    }

  return update_tri_layer_state(state, _SYMB, _NUMP, _CONF);
};
