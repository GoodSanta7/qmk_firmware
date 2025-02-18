/* Copyright 2021
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

#include QMK_KEYBOARD_H
#include "keymap_user.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

bool caps_lock_light_tab = false;
bool caps_lock_light_alphas = true;
bool fn_layer_transparent_keys_off = false;
bool fn_layer_color_enable = true;

enum custom_keycodes {
    KC_MISSION_CONTROL = SAFE_RANGE,
    KC_LAUNCHPAD,
    KC_LIGHT_TAB_TOGGLE,
    KC_LIGHT_ALPHAS_TOGGLE,
    KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE,
    KC_FN_LAYER_COLOR_TOGGLE
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_LTTOG KC_LIGHT_TAB_TOGGLE
#define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
#define KC_TKTOG KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
#define KC_FCTOG KC_FN_LAYER_COLOR_TOGGLE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,        KC_GRV,
        KC_CAPS, KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,         KC_HOME,
        KC_LSFT,          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                        KC_RCMD, MO(_FN1), MO(_FN3), KC_LEFT,  KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,     KC_3,     KC_4,     KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,        KC_VOLD, KC_MUTE, KC_VOLU,
        KC_TAB,  KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,        KC_GRV,
        KC_CAPS, KC_A,    KC_S,     KC_D,     KC_F,     KC_G,     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,         KC_HOME,
        KC_LSFT,          KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                        KC_RALT, MO(_FN2), MO(_FN3), KC_LEFT,  KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_all(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,          RGB_RMOD, RGB_TOG, RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,           KC_LTTOG, KC_LATOG, KC_TKTOG, KC_FCTOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN2] = LAYOUT_all(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS,          RGB_RMOD, RGB_TOG, RGB_MOD,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN3] = LAYOUT_all(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS,
        RGB_TOG, RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,
        KC_TRNS, RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,           KC_LTTOG, KC_LATOG, KC_TKTOG, KC_FCTOG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS,  KC_TRNS,                            KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#if defined(ENCODER_ENABLE)

#define ENCODERS 1
static uint8_t  encoder_state[ENCODERS] = {0};
static keypos_t encoder_cw[ENCODERS]  = {{ 8, 4 }};
static keypos_t encoder_ccw[ENCODERS]  = {{ 7, 4 }};

void encoder_action_register(uint8_t index, bool clockwise) {
    keyevent_t encoder_event = (keyevent_t) {
        .key = clockwise ? encoder_cw[index] : encoder_ccw[index],
        .pressed = true,
        .time = (timer_read() | 1)
    };
    encoder_state[index] = (clockwise ^ 1) | (clockwise << 1);
    action_exec(encoder_event);
}

void encoder_action_unregister(void) {
    for (int index = 0; index < ENCODERS; ++index) {
        if (encoder_state[index]) {
            keyevent_t encoder_event = (keyevent_t) {
                .key = encoder_state[index] >> 1 ? encoder_cw[index] : encoder_ccw[index],
                .pressed = false,
                .time = (timer_read() | 1)
            };
            encoder_state[index] = 0;
            action_exec(encoder_event);
        }
    }
}

void matrix_scan_user(void) {
    encoder_action_unregister();
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    encoder_action_register(index, clockwise);
    return false;
};

#endif

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_TAB_TOGGLE:
            if (record->event.pressed) {
                caps_lock_light_tab = !caps_lock_light_tab;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_ALPHAS_TOGGLE:
            if (record->event.pressed) {
                caps_lock_light_alphas = !caps_lock_light_alphas;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
            if (record->event.pressed) {
                fn_layer_transparent_keys_off = !fn_layer_transparent_keys_off;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                fn_layer_color_enable = !fn_layer_color_enable;
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}
