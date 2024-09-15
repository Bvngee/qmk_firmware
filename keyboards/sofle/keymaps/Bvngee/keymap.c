// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include "action.h"
#include "action_layer.h"
#include "keyboard.h"
#include "keycodes.h"
#include "keymap_us.h"
#include "oled_driver.h"
#include "quantum.h"
#include "quantum_keycodes.h"
#include QMK_KEYBOARD_H

enum sofle_layers {
    _BASE,
    _LOWER,
    _UPPER,
    // _ADJUST,
};

const char *layer_to_display_name(enum sofle_layers layer) {
    switch (layer) {
        case _BASE:
            return PSTR("Base ");
        case _LOWER:
            return PSTR("Lower");
        case _UPPER:
            return PSTR("Upper");
        // case _ADJUST:
        //     return PSTR("Adjst");
        default:
            return PSTR("Unkwn");
    }
}

// enum custom_keycodes {
// KC_PRVWD = SAFE_RANGE, // previous/next word (which elumate C-left/C-right)
// KC_NXTWD,
// KC_LSTRT,
// KC_LEND
// };

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_BASE] = LAYOUT(
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                              KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_GRV,
  KC_ESC,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,            KC_MUTE, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_DEL,
               KC_LALT, KC_LGUI, KC_LCTL, LT(_LOWER,KC_SPC),KC_ENT, LT(_UPPER, KC_BSPC),OSM(MOD_LSFT), KC_TAB, KC_RGUI, KC_RALT // ?? maybe try space as a MT so _lower and shift are on opposite hands?
),
// [_LOWER] = LAYOUT( // keep numbers on top row on lower layer
//   _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
//   _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
//   _______, KC_EQL,  KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR,                     KC_LPRN, KC_RPRN, KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE,
//   _______, KC_UNDS, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,   _______, KC_LBRC, KC_RBRC, KC_EXLM, KC_QUES, KC_BSLS, _______,
//                   _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
// ),
[_LOWER] = LAYOUT(
//   _______,
//   _______, KC_AT
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, KC_PLUS, KC_7,    KC_8,    KC_9,    KC_0,                        KC_EXLM, KC_LCBR, KC_RCBR, KC_QUES, KC_AMPR, KC_GRV,
  _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_EQL,                      KC_CIRC, KC_LPRN, KC_RPRN, KC_DLR,  KC_ASTR, KC_PIPE,
  _______, KC_UNDS, KC_1,    KC_2,    KC_3,    KC_HASH, _______,   _______, KC_AT,   KC_LBRC, KC_RBRC, KC_PERC, KC_BSLS, _______,
                  _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______
),
[_UPPER] = LAYOUT( // F-keys go on upper layer
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    C(KC_LEFT),KC_PGDN,KC_PGUP,C(KC_RIGHT),XXXXXXX,KC_F12,
  QK_REBOOT,XXXXXXX,XXXXXXX, KC_INS,  KC_PSCR, XXXXXXX,                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_HOME, _______,
  _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  KC_END, _______,
                  _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
)
};
// clang-format off

// Key Overrides
// const key_override_t *key_overrides[] = {
    // Shift + Space => Tab
    // &ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_TAB) // currently unused; see base layer
// };

// Process keylogs
#define OLED_WIDTH_CHARS 5
char keylog_str[OLED_WIDTH_CHARS + 1] = {0};
void add_keylog(uint16_t keycode, keyrecord_t *record) {
    // memset(, &, 5);
}

// Process keycodes (custom keycodes go here)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //const uint8_t mods = get_mods() | get_oneshot_mods();

    // Keylog
    if (record->event.pressed) {
        add_keylog(keycode, record);
    }

    // Handle keycodes
    switch (keycode) {
        default: return true;
    }
}

// Rotary encoders
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) { // Right encoder
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 0) { // Right encoder
        if (IS_LAYER_ON(_UPPER)) {
            if (clockwise) {
                tap_code(KC_PGUP);
            } else {
                tap_code(KC_PGDN);
            }
        } else {
            if (clockwise) {
                tap_code(MS_WHLU);
            } else {
                tap_code(MS_WHLD);
            }
        }
    }
    return false;
}

// OLED
bool oled_task_user(void) {
    oled_write_P(
        layer_to_display_name(get_highest_layer(layer_state)),
        false
    );

    oled_write_P(PSTR("\n\n"), false);

    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUMLK") : PSTR("     "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CPSLK") : PSTR("     "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCRLK") : PSTR("     "), false);
    // oled_write_P(PSTR("\n"), false);

    oled_set_cursor(0, oled_max_lines()-1);
    oled_write_P(PSTR("sofle"), false);

    return false;
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}



void oled_render_boot(bool bootloader) {
    oled_clear();
    if (bootloader) {
        oled_write_ln_P(PSTR("Firm "), false);
        oled_write_ln_P(PSTR("..."), false);
    } else {
        oled_write_ln_P(PSTR("Rbt.."), false);
    }

    oled_render_dirty(true);
}

// Shutdown tasks
bool shutdown_user(bool jump_to_bootloader) {
    oled_render_boot(jump_to_bootloader);
    return false;
}
