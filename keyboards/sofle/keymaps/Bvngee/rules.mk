CONVERT_TO = rp2040_ce
# Turns out I dont think any of these are needed (?)
#BOARD = GENERIC_PROMICRO_RP2040
#BOOTLOADER = rp2040
#MCU = RP2040

SPLIT_KEYBOARD = yes

# Imma stick with two layers for now
#TRI_LAYER_ENABLE = yes

# Enable Key Overrides
#KEY_OVERRIDE_ENABLE = yes # currently unused

# I think this fixes the on-wake/boot problem?? Ref:
# https://docs.qmk.fm/faq_misc#problem-in-bios-uefi-setup-resume-sleep-wake-power-cycles
CONSOLE_ENABLE = no
NKRO_ENABLE = no
SLEEP_LED_ENABLE = no
