#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names { TEST };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [TEST] = LAYOUT(
                    KC_H, KC_D,
              KC_K, KC_G, KC_C,
        KC_M, KC_J, KC_F, KC_B,
        KC_L, KC_I, KC_E, KC_A,
        KC_1, KC_2, KC_3,

        LSFT(KC_D), LSFT(KC_H),
        LSFT(KC_C), LSFT(KC_G), LSFT(KC_K),
        LSFT(KC_B), LSFT(KC_F), LSFT(KC_J), LSFT(KC_M),
        LSFT(KC_A), LSFT(KC_E), LSFT(KC_I), LSFT(KC_L),
        LSFT(KC_3), LSFT(KC_2), LSFT(KC_1)
  ),
};
