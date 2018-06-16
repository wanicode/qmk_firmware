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

// layer colors
#define RGBLIGHT_COLOR_LAYER_0 360,0x00,0xFF
#define RGBLIGHT_COLOR_LAYER_1 0,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_2 240,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_3 120,0xFF,0xFF
#define RGBLIGHT_COLOR_LAYER_4 270,0xFF,0xFF

// keyaliases
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

#define OS_SYMB OSL(SYMB)
#define TG_NAVI TG(NAVI)
#define TG_NUMP TG(NUMP)

#define WC_PRNT LSFT(LGUI(KC_4))
#define WC_1PW  LGUI(KC_BSLS)
#define WC_1PWM LALT(LGUI(KC_BSLS))

#define WC_SFTT LSFT_T(KC_T)
#define WC_ALTS LALT_T(KC_S)
#define WC_CTLR LCTL_T(KC_R)
#define WC_SFTN LSFT_T(KC_N)
#define WC_ALTE LALT_T(KC_E)
#define WC_CTLI LCTL_T(KC_I)
#define WC_GUIS LGUI_T(KC_SPC)
#define WC_GUIE LGUI_T(KC_ENT)

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

bool skip_leds = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  CONF  |   1  |   2  |   3  |   4  |   5  |      |           | 1PWM |   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   F  |   P  |   B  | PRINT|           | 1PWD |   J  |   L  |   U  |   Y  |   ;  |  NUMP  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   TAB  |   A  |   R  |   S  |   T  |   G  |------|           |------|   K  |   N  |   E  |   I  |   O  |    '   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  SHIFT |   Z  |   X  |   C  |   D  |   V  | HYPER|           |  MEH |   M  |   H  |   ,  |   .  |   /  |  SHIFT |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | RMOUS| MMOUS| LMOUS|      | SYMB |                                       | NAVI |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MUTE | PLAY |       | VOLDN| VOLUP|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Space|  ESC |------|       |------| Back-|Enter |
 *                                 |      |      |      |       |      | space|      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
       TG(CONF),    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, _______,
        _______,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B, WC_PRNT,
         KC_TAB,    KC_A, WC_CTLR, WC_ALTS, WC_SFTT,    KC_G,
         OS_SFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, OS_HYPR,
        _______, _______, _______, _______, OS_SYMB,
                                                     KC_MUTE, KC_MPLY,
                                                              _______,
                                            WC_GUIS,  KC_ESC, _______,
        // right hand
             WC_1PWM,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
              WC_1PW,    KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, TG_NUMP,
                         KC_K, WC_SFTN, WC_ALTE, WC_CTLI,    KC_O, KC_QUOT,
              OS_MEH,    KC_M,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,  OS_SFT,
                               TG_NAVI, _______, _______, _______, TG_QWRT,
             KC_VOLD, KC_VOLU,
             _______,
             _______, KC_BSPC, WC_GUIE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      |   ^  |   @  |   +  |   /  |      |           |      |   \  |   -  |   _  |   #  |      |   F12  |
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
       _______, XXXXXXX, KC_CIRC,   KC_AT, KC_PLUS, KC_SLSH, _______,
       _______, KC_LBRC, KC_LCBR, KC_LABK, KC_LPRN, KC_EXLM,
       _______, XXXXXXX, KC_TILD, KC_PERC,  KC_DLR, KC_AMPR, _______,
       _______, _______, _______, _______, _______,
                                                    _______, _______,
                                                             _______,
                                           _______, _______, _______,
       // right hand
       _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
       _______, KC_BSLS, KC_MINS, KC_UNDS, KC_HASH, XXXXXXX,  KC_F12,
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
 * |        |      |      |      |      |      |      |           |      |      |      | UP   |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |  ALT | SHIFT|      |------|           |------|      | LEFT | DOWN | RIGHT|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
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
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______,   KC_UP, _______, _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 3: Numpad keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |   /  |   *  |   -  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   7  |   8  |   9  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|   #  |   4  |   5  |   6  |   =  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  | ENTER|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0  |   0  |   .  | ENTER|      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
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
       _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, _______,
       _______, _______,    KC_7,    KC_8,    KC_9, KC_PPLS, _______,
                KC_HASH,    KC_4,    KC_5,    KC_6, KC_PEQL, _______,
       _______, _______,    KC_1,    KC_2,    KC_3, KC_PENT, _______,
                            KC_0,    KC_0, KC_PDOT, KC_PENT, _______,
       _______, _______,
       _______,
       _______, _______, _______
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
          rgblight_mode_noeeprom(1);
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
  rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_0);
  rgblight_mode_noeeprom(1);
#endif
};

LEADER_EXTERNS();

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t modifiders = get_mods();
  uint8_t led_usb_state = host_keyboard_leds();
  uint8_t one_shot = get_oneshot_mods();

  if (!skip_leds) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    // Since we're not using the LEDs here for layer indication anymore,
    // then lets use them for modifier indicators.  Shame we don't have 4...
    // Also, no "else", since we want to know each, independently.
    if (modifiders & MODS_SHIFT_MASK || led_usb_state & (1<<USB_LED_CAPS_LOCK) || one_shot & MODS_SHIFT_MASK) {
      ergodox_right_led_2_on();
      ergodox_right_led_2_set( 50 );
    }
    if (modifiders & MODS_CTRL_MASK || one_shot & MODS_CTRL_MASK) {
      ergodox_right_led_1_on();
      ergodox_right_led_1_set( 10 );
    }
    if (modifiders & MODS_ALT_MASK || one_shot & MODS_ALT_MASK) {
      ergodox_right_led_3_on();
      ergodox_right_led_3_set( 10 );
    }

  }


  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_V) {
      register_code(KC_LCTL);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
      unregister_code(KC_LSFT);
    }

    SEQ_ONE_KEY(KC_H) {
      register_code(KC_LCTL);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_5);
      unregister_code(KC_5);
      unregister_code(KC_LSFT);
    }

  }
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  switch (layer) {
      case BASE:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case SYMB:
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case NAVI:
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case NUMP:
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case CONF:
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_sethsv_noeeprom(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      default:
        break;
    }

  return state;
};
