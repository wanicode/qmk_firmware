#pragma once
#include "quantum.h"
#include "version.h"

enum userspace_layers {
  _BASE = 0,
  _NUMP,
  _SYMB,
  _NAVI,
  _FUNC,
  _MCRO,
  _CONF,
  _GAME
};

#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MODS_ALT_MASK  (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))
#define MODS_GUI_MASK  (MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI))

// more pronounced empty keys
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Key aliases
// One Shot
#define OS_SFT  OSM(MOD_LSFT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_ALT  OSM(MOD_LALT)
#define OS_GUI  OSM(MOD_LGUI)
#define OS_MEH  OSM(MOD_MEH)
#define OS_HYPR OSM(MOD_HYPR)

// Macros
#define WC_PRNT LSFT(LGUI(KC_4))
#define WC_1PW  LGUI(KC_BSLS)
#define WC_1PWM LALT(LGUI(KC_BSLS))
#define WC_LOCK LGUI(LCTL(KC_Q))

// ModTap Shift
#define WC_SFTT LSFT_T(KC_T)
#define WC_SFTN RSFT_T(KC_N)
#define WC_SFT4 RSFT_T(KC_4)
#define WC_SFF4 RSFT_T(KC_F4)

// ModTap Alt
#define WC_ALTS LALT_T(KC_S)
#define WC_ALTE RALT_T(KC_E)
#define WC_ALT5 RALT_T(KC_5)
#define WC_ALF5 RALT_T(KC_F5)

// ModTap Ctrl
#define WC_CTLR LCTL_T(KC_R)
#define WC_CTLI RCTL_T(KC_I)
#define WC_CTL6 RCTL_T(KC_6)
#define WC_CTF6 RCTL_T(KC_F6)

// ModTap GUI
#define WC_MGEN LGUI_T(KC_ENT)
#define WC_MGES RGUI_T(KC_ESC)
#define WC_MGA  LGUI_T(KC_A)
#define WC_MGO  RGUI_T(KC_O)
#define WC_MGF1 RGUI_T(KC_F11)

// ModTap Hyper
#define WC_HYPF ALL_T(KC_F)
#define WC_HYPU ALL_T(KC_U)

// ModTap Meh
#define WC_MEHP MEH_T(KC_P)
#define WC_MEHL MEH_T(KC_L)

// LayerTap
#define WC_FUND LT(_FUNC, KC_DEL)
#define WC_MCRS LT(_MCRO, KC_SPC)
#define WC_NUMD LT(_NUMP, KC_DEL)
#define WC_NAVS LT(_NAVI, KC_SPC)
#define WC_NAVT LT(_NAVI, KC_TAB)
#define WC_NUMS LT(_NUMP, KC_SPC)
#define WC_NUME LT(_NUMP, KC_ESC)
#define WC_SYMD LT(_SYMB, KC_DEL)
#define WC_SYMB LT(_SYMB, KC_BSPC)
#define WC_SYME LT(_SYMB, KC_ENT)

#define WC_BASE DF(_BASE)
#define WC_GAME DF(_GAME)

#define LAYOUT_ortho_4x12_wrapper(...)       LAYOUT_ortho_4x12(__VA_ARGS__)

// Transparent Multikeys
#define ___________________________________________ _______, _______, _______, _______, _______
#define ________________________________________________________________________________________ ___________________________________________, ___________________________________________

// Colemak Multikeys
#define _____________COLEMAK_MOD_DH_L1_____________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _____________COLEMAK_MOD_DH_L2_____________ WC_MGA,  WC_CTLR, WC_ALTS, WC_SFTT, KC_G
#define _____________COLEMAK_MOD_DH_L3_____________ KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define _____________COLEMAK_MOD_DH_L4_____________ KC_MEH,  _______, WC_MCRS, WC_NUMS, WC_MGEN
#define _____________COLEMAK_MOD_DH_R1_____________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _____________COLEMAK_MOD_DH_R2_____________ KC_K,    WC_SFTN, WC_ALTE, WC_CTLI, WC_MGO
#define _____________COLEMAK_MOD_DH_R3_____________ KC_M,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH
#define _____________COLEMAK_MOD_DH_R4_____________ WC_MGES, WC_SYMB, WC_FUND, _______, KC_MEH
#define _________________________________COLEMAK_MOD_DH_1_______________________________________ _____________COLEMAK_MOD_DH_L1_____________, _____________COLEMAK_MOD_DH_R1_____________
#define _________________________________COLEMAK_MOD_DH_2_______________________________________ _____________COLEMAK_MOD_DH_L2_____________, _____________COLEMAK_MOD_DH_R2_____________
#define _________________________________COLEMAK_MOD_DH_3_______________________________________ _____________COLEMAK_MOD_DH_L3_____________, _____________COLEMAK_MOD_DH_R3_____________

// Symbol Multikeys
#define _________________SYMBOLS_L1________________ _______, KC_EXLM, KC_AT,   KC_PLUS, KC_QUOT
#define _________________SYMBOLS_L2________________ KC_DQUO, KC_MINS, KC_UNDS, KC_BSLS, _______
#define _________________SYMBOLS_L3________________ KC_LBRC, KC_LCBR, KC_LABK, KC_LPRN, KC_CIRC
#define _________________SYMBOLS_R1________________ KC_HASH, KC_RPRN, KC_RABK, KC_RCBR, KC_RBRC
#define _________________SYMBOLS_R2________________ _______, KC_TILD, KC_PERC, KC_DLR,  KC_AMPR
#define _________________SYMBOLS_R3________________ KC_PIPE, KC_EQL,  KC_GRV,  KC_ASTR, _______
#define _______________________________________SYMBOLS_1________________________________________ _________________SYMBOLS_L1________________, _________________SYMBOLS_R1________________
#define _______________________________________SYMBOLS_2________________________________________ _________________SYMBOLS_L2________________, _________________SYMBOLS_R2________________
#define _______________________________________SYMBOLS_3________________________________________ _________________SYMBOLS_L3________________, _________________SYMBOLS_R3________________

// Number Multikeys
#define _________________NUMBERS_LEFT______________ KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBERS_RIGHT_____________ KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________NUMPAD_ROW2_______________ KC_HASH, WC_SFT4, WC_ALT5, WC_CTL6, _______
#define _________________NUMPAD_ROW3_______________ _______, KC_1,    KC_2,    KC_3,    _______
#define _________________NUMPAD_ROW4_______________ _______, KC_0,    KC_0,    KC_PDOT, _______
#define ________________________________________NUMBERS_________________________________________ _________________NUMBERS_LEFT______________, _________________NUMBERS_RIGHT_____________

// Function Multikeys
#define _________________FUNCTIONS_LEFT____________ KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNCTIONS_RIGHT___________ KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define _________________FUNCPAD_ROW2______________ _______, WC_SFF4, WC_ALF5, WC_CTF6, WC_MGF1
#define _________________FUNCPAD_ROW3______________ _______, KC_F1,   KC_F2,   KC_F3,   KC_F12
#define ________________________________________FUNCTIONS_______________________________________ _________________FUNCTIONS_LEFT____________, _________________FUNCTIONS_RIGHT___________

// Macro Multikeys
#define _________________MACROS_L1_________________ WC_LOCK, _______, WC_PRNT, WC_1PW,  _______
#define _________________MACROS_L2_________________ _______, _______, KC_MPLY, WC_1PWM, _______
#define _________________MACROS_L3_________________ _______, _______, _______, _______, _______
#define _________________MACROS_R1_________________ _______, _______, _______, _______, _______
#define _________________MACROS_R2_________________ _______, _______, _______, _______, _______
#define _________________MACROS_R3_________________ _______, _______, _______, _______, _______
#define ________________________________________MACROS_1________________________________________ _________________MACROS_L1_________________, _________________MACROS_R1_________________
#define ________________________________________MACROS_2________________________________________ _________________MACROS_L2_________________, _________________MACROS_R2_________________
#define ________________________________________MACROS_3________________________________________ _________________MACROS_L3_________________, _________________MACROS_R3_________________

// Config Multikeys
#define _________________CONFIG_L1_________________ _______, MU_MOD,  CK_UP,   CK_RST,  _______
#define _________________CONFIG_L2_________________ _______, MU_TOG,  CK_TOGG, AU_TOG,  _______
#define _________________CONFIG_L3_________________ _______, _______, CK_DOWN, _______, _______
#define _________________CONFIG_L4_________________ _______, _______, _______, _______, _______
#define _________________CONFIG_R1_________________ _______, RGB_HUI, RGB_SAI, RGB_VAI, _______
#define _________________CONFIG_R2_________________ _______, RGB_HUD, RGB_SAD, RGB_VAD, RGB_MOD
#define _________________CONFIG_R3_________________ _______, _______, _______, _______, _______
#define _________________CONFIG_R4_________________ _______, RGB_TOG, _______, _______, _______
#define ________________________________________CONFIG_1________________________________________ _________________CONFIG_L1_________________, _________________CONFIG_R1_________________
#define ________________________________________CONFIG_2________________________________________ _________________CONFIG_L2_________________, _________________CONFIG_R2_________________
#define ________________________________________CONFIG_3________________________________________ _________________CONFIG_L3_________________, _________________CONFIG_R3_________________
#define ________________________________________CONFIG_4________________________________________ _________________CONFIG_L4_________________, _________________CONFIG_R4_________________
