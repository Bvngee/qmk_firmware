// Copyright 2024 Santosh Kumar (@santosh)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Time in ms for which a dual-role key's press regisiters as a tap before becoming the hold
#define TAPPING_TERM 200

// https://docs.qmk.fm/tap_hold
// If a dual-role key (such as enter + upper layer) is pressed, another key is tapped, and
// the dual-role key is released ALL within the TAPPING_TERM, the dual-role key will act as
// the layer. This way you dont have to hold the dual-role key for at least TAPPING_TERM.
//#define PERMISSIVE_HOLD
// If a dual-role key (such as enter + upper layer) is pressed and another key is pressed,
// the dual-role key will immediately act as the layer.
#define HOLD_ON_OTHER_KEY_PRESS

// Tapping this number of times holds the key until tapped once again.
#define ONESHOT_TAP_TOGGLE 4
// Time (in ms) before the one shot key is released
#define ONESHOT_TIMEOUT 2000

// Uses Handedness by EEPROM
// https://docs.qmk.fm/features/split_keyboard#handedness-by-eeprom
// REMEMBER: whenever the bootloader/EEPROM gets reset, `-bl uf2-split-left` must
// be used to reinitialize bootloader with the correct sides!
#define EE_HANDS

// This is just to make LSP happy; its truly enabled in rules.mk
#undef KEY_OVERRIDE_ENABLE
#define KEY_OVERRIDE_ENABLE

// Make rotary encoders only send their respective keycodes once per notch
#define ENCODER_RESOLUTIONS { 4 }

// Self explanatory
#define OLED_TIMEOUT 30000 // milliseconds
#define OLED_FADE_OUT 1 // not sure this is working?
#define OLED_FADE_OUT_INTERVAL 15 // 0-15 where larger is slower fadeout
#define OLED_BRIGHTNESS 90

// Syncs the on/off state of the OLED between the halves.
#define SPLIT_OLED_ENABLE
// Syncs the activity timestamps between the halves
#define SPLIT_ACTIVITY_ENABLE
// Ensures current layer state is available on both halves
#define SPLIT_LAYER_STATE_ENABLE
// Ensures caps/numlock/etc state is available on both halves
#define SPLIT_LED_STATE_ENABLE
//#define SPLIT_MODS_ENABLE
//#define SPLIT_WPM_ENABLE

// Set which layer indexes correspond with lower/upper/adjust
// Ima stick with two layers for now
//#define TRI_LAYER_LOWER_LAYER 1
//#define TRI_LAYER_UPPER_LAYER 2
//#define TRI_LAYER_ADJUST_LAYER 3


// Not working; maybe needs other bootloader?? not sure
/* #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior */
/* #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur. */
/* #define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17 // Optional status led which blinks when entering the bootloader (GPIO number) */
