#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

// more pronounced empty keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// layers
#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAVI 2 // navigation
#define NUMP 3 // numpad
#define CONF 4 // configuration

// keyaliases
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define OS_SYMB OSL(SYMB)
#define TG_NAVI TG(NAVI)

#define WC_PRNT LSFT(LGUI(KC_4))
#define WC_1PW  LGUI(KC_BSLS)
#define WC_1PWM LALT(LGUI(KC_BSLS))

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

enum {
  TD_J_NUMP = 0,
  TD_J_BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  CONF  |   1  |   2  |   3  |   4  |   5  |      |           | 1PWM |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   B  | PRINT|           | 1PWD |   J  |   L  |   U  |   Y  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ESC  |   A  |   R  |   S  |   T  |   G  |------|           |------|   K  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  SHIFT |   Z  |   X  |   C  |   D  |   V  | HYPER|           |  MEH |   M  |   H  |   ,  |   .  |   /  |  SHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | CTRL |      |      |  ALT | SYMB |                                       | NAVI |  ALT |      |      | CTRL |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MUTE | PLAY |       | VOLDN| VOLUP|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|  Tab |------|       |------| Back-|Enter |
 *                                 |      |      |  GUI |       |  GUI | space|      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       TG(CONF),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,
        _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, WC_PRNT,
         KC_ESC,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,
         OS_SFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, OS_HYPR,
        OS_CTRL, _______, _______,  OS_ALT, OS_SYMB,
                                                     KC_MUTE, KC_MPLY,
                                                              _______,
                                             KC_SPC,  KC_TAB,  OS_GUI,
        // right hand
             WC_1PWM,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
              WC_1PW, TD(TD_J_NUMP),    KC_L,    KC_U,    KC_Y, KC_SCLN, _______,
                         KC_K,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
              OS_MEH,    KC_M,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  OS_SFT,
                               TG_NAVI,  OS_ALT, _______, _______, OS_CTRL,
             KC_VOLD, KC_VOLU,
             _______,
              OS_GUI, KC_BSPC,  KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   ^  |   @  |   +  |   #  |      |           |      |   \  |   -  |   _  |   /  |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   [  |   {  |   <  |   (  |   !  |------|           |------|   ?  |   )  |   >  |   }  |   ]  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |   ~  |   %  |   $  |   &  |      |           |      |   |  |   =  |   `  |   *  |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5, _______,
       _______, XXXXXXX, KC_CIRC,   KC_AT, KC_PLUS, KC_HASH, _______,
       _______, KC_LBRC, KC_LCBR, KC_LABK, KC_LPRN, KC_EXLM,
       _______, XXXXXXX, KC_TILD, KC_PERC,  KC_DLR, KC_AMPR, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       _______, KC_BSLS, KC_MINS, KC_UNDS, KC_SLSH, XXXXXXX,  KC_F12,
                KC_QUES, KC_RPRN, KC_RABK, KC_RCBR, KC_RBRC, _______,
       _______, KC_PIPE,  KC_EQL,  KC_GRV, KC_ASTR, XXXXXXX, _______,
                         _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Navigation keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | HOME |PGDOWN| PGUP |  END |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  ALT | SHIFT|      |------|           |------|      | LEFT | DOWN |  UP  | RIGHT|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |  GUI |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// NAVIGATION
[NAVI] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_LALT, KC_LSFT, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  KC_LGUI, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END, _______,
                 _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 3: Numpad keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |   #  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Numpad
[NUMP] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  TD(TD_J_BASE),    KC_7,    KC_8,    KC_9, _______, _______,
                 _______,    KC_4,    KC_5,    KC_6, _______, _______,
       _______,  _______,    KC_1,    KC_2,    KC_3, _______, _______,
                             KC_0,    KC_0, KC_PCMM, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_HASH
),
/* Keymap 4: Configuration keys
   *
   * ,--------------------------------------------------.           ,--------------------------------------------------.
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  RESET |
   * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      | HUEUP| SATUP| VALUP|      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |------|           |------|      | HUEDN| SATDN| VALDN|      |        |
   * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
   * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
   * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
   *   |      |      |      |      |      |                                       |      |      |      |      |      |
   *   `----------------------------------'                                       `----------------------------------'
   *                                        ,-------------.       ,-------------.
   *                                        |      |      |       |      |      |
   *                                 ,------|------|------|       |------+------+------.
   *                                 |      |      |      |       |      | NEXT |  TOGL |
   *                                 |      |      |------|       |------| ANIM |  RGB |
   *                                 |      |      |      |       |L ANIM|      |      |
   *                                 `--------------------'       `--------------------'
   */
  // Numpad
  [CONF] = LAYOUT_ergodox(
         _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______,
                                             _______, _______,
                                                      _______,
                                    _______, _______, _______,
      // right hand
         _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   RESET,
         _______,  XXXXXXX, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,
                   XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, _______,
         _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                            _______, _______, _______, _______, _______,
         _______, _______,
         _______,
        RGB_RMOD, RGB_MOD, RGB_TOG
  ),
};

qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for B, twice for Numpad Layer
  [TD_J_NUMP]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_J, NUMP),
  [TD_J_BASE]  = ACTION_TAP_DANCE_DUAL_ROLE(KC_J, BASE)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
