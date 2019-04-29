BOOTMAGIC_ENABLE  = no
MOUSEKEY_ENABLE   = no
EXTRAKEY_ENABLE   = yes
CONSOLE_ENABLE    = no
COMMAND_ENABLE    = no
TAP_DANCE_ENABLE  = no
RGBLIGHT_ENABLE   = no

ifneq (,$(findstring planck/rev6,$(KEYBOARD)))
  AUDIO_ENABLE      = yes
  INDICATOR_LIGHTS  = no
  RGBLIGHT_TWINKLE  = no
endif
ifneq (,$(findstring niu_mini,$(KEYBOARD)))
  RGBLIGHT_ENABLE  = yes
endif
NKRO_ENABLE       = no

MACROS_ENABLED    = no
