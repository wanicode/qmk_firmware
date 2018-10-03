BOOTMAGIC_ENABLE  = no
MOUSEKEY_ENABLE   = no
EXTRAKEY_ENABLE   = yes
CONSOLE_ENABLE    = no
COMMAND_ENABLE    = no 
TAP_DANCE_ENABLE  = no

ifeq (,$(findstring planck/rev6,$(KEYBOARD)))
  AUDIO_ENABLE      = yes
  RGBLIGHT_ENABLE   = no
  INDICATOR_LIGHTS  = no
  RGBLIGHT_TWINKLE  = no
endif

ifeq (,$(findstring niu_mini,$(KEYBOARD)))
  AUDIO_ENABLE      = no
  RGBLIGHT_ENABLE   = yes
  INDICATOR_LIGHTS  = no
  RGBLIGHT_TWINKLE  = yes
endif

NKRO_ENABLE       = no

MACROS_ENABLED    = no
