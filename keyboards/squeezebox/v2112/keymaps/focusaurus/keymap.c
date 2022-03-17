#include QMK_KEYBOARD_H

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

const key_override_t coln_key_override =
    ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN); // Shift : is ;

const key_override_t** key_overrides = (const key_override_t*[]){
    &coln_key_override,
    NULL
};

enum {

  TD_COMMA,
  /* TD_DOT, */
  /* TD_LBRC, */
  /* TD_RBRC, */
  /* TD_SEMI */

};

qk_tap_dance_action_t tap_dance_actions[] = {

  [TD_COMMA] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_F12),
  /* [TD_DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_QUES), */
  /* [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, LSFT(KC_COMMA)), */
  /* [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, LSFT(KC_DOT)), */
  /* [TD_SEMI] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SCLN) */

};

enum combos {

  /* COMBO_BRACKETS, */
  /* COMBO_PARENS, */
  COMBO_BASH_VAR,
  COMBO_ESCAPE,
  COMBO_ESCAPE_CORNER,
  COMBO_FUZZBALL,
  COMBO_QUOTE_VAR,
  COMBO_SEMI,

};

// const uint16_t PROGMEM combo_brackets[] = {KC_J, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_parens[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_bash_var[] = {KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_escape_corner[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_fuzzball[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM combo_quote_var[] = {KC_Q, KC_V, COMBO_END};
const uint16_t PROGMEM combo_semi[] = {KC_Q, KC_COLON, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  // [COMBO_BRACKETS] = COMBO_ACTION(combo_brackets),
  // [COMBO_PARENS] = COMBO_ACTION(combo_parens),
  [COMBO_BASH_VAR] = COMBO_ACTION(combo_bash_var),
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  [COMBO_ESCAPE_CORNER] = COMBO(combo_escape_corner, KC_ESC),
  [COMBO_FUZZBALL] = COMBO(combo_fuzzball, FUZZBALL),
  [COMBO_SEMI] = COMBO(combo_semi, KC_SCLN),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_QUOTE_VAR:
      if (pressed) {
        tap_code16(LSFT(KC_QUOTE));
        tap_code16(LSFT(KC_4));
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
        tap_code16(LSFT(KC_QUOTE));
        tap_code16(KC_LEFT);
        tap_code16(KC_LEFT);
      }
      break;
    case COMBO_BASH_VAR:
      if (pressed) {
        tap_code16(LSFT(KC_4));
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
        tap_code16(KC_LEFT);
      }
      break;
  }
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK,
    MACOS,
    NAVNUM,
    BANG,
    KBFN,
    VIEW

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO make a dedicated LAYOUT_fingers that leaves thumb clusters transparent
/* Base */
[DVORAK] = LAYOUT(

// left hand
KC_NO, KC_QUOTE, TD(TD_COMMA), LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y,
KC_NO, MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
KC_NO, KC_COLON /*TD(TD_SEMI)*/, KC_Q, KC_J, KC_K, KC_X,
LT(KBFN, KC_BSPC), LT(NAVNUM, LEADER), OSM(MOD_LSFT),

// right hand
KC_F, RCTL_T(KC_G), KC_C, KC_R, KC_L, KC_NO,
KC_D, KC_H, KC_T, KC_N, KC_S, KC_NO,
KC_B, KC_M, LALT_T(KC_W), KC_V, KC_Z, KC_NO,
KC_ENT, LT(BANG, KC_SPC), OSM(MOD_RCTL)

), [MACOS] = LAYOUT(

KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, OSM(MOD_RGUI)

), [NAVNUM] = LAYOUT(

// left hand
KC_NO, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
LSFT(KC_TAB), KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_COMMA, KC_7, KC_8, KC_9, LSFT(KC_MINUS), KC_NO,
KC_DOT, MT(MOD_LSFT, KC_4), MT(MOD_LCTL, KC_5), MT(MOD_LALT, KC_6), MT(MOD_LGUI, KC_0), KC_NO,
KC_COLON, KC_1, KC_2, KC_3, KC_MINUS, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS

), [BANG] = LAYOUT(

// punctuation: . , : ; ! - ? _
// pairs: () {} [] <>
// quotes: ' " `
/*// unix: ~ / | \ */
// numpad symbols: ! @ # $ % ^ & *
// math: + =
// left hand
KC_NO, LSFT(KC_MINUS), KC_MINUS, KC_LBRC, KC_RBRC, KC_GT,
KC_NO, KC_QUOTE, LSFT(KC_QUOTE), KC_LPRN, KC_RPRN, KC_ENT,
KC_NO, KC_COLON, KC_GRV, KC_LCBR, KC_RCBR, KC_LT,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_PIPE, LSFT(KC_GRV), KC_NO,
KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_SLSH, KC_NO,
KC_BSLS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), KC_QUES, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS

), [KBFN] = LAYOUT(

// left hand
TG(VIEW), RESET, KC_NO, KC_VOLU, KC_NO, KC_NO,
KC_CAPSLOCK, KC_NO, KC_NO, KC_MUTE, KC_NO, KC_NO,
TG(MACOS), KC_NO, KC_NO, KC_VOLD, KC_NO, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_NO, KC_F7, KC_F8, KC_F9, KC_F12, KC_NO,
KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, KC_NO,
KC_NO, KC_F1, KC_F2, KC_F3, KC_F10, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS

), [VIEW] = LAYOUT(

// left hand
TG(VIEW), KC_NO, LCTL(LSFT(KC_TAB)), KC_NO, LCTL(KC_TAB), KC_NO,
KC_NO, KC_NO, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
KC_NO, KC_NO, KC_Q, KC_DOWN, LALT(LGUI(KC_X)), KC_NO,
TG(VIEW), KC_TRNS, KC_TRNS,

// right hand
KC_NO, KC_NO, LCTL(LSFT(KC_TAB)), KC_NO, LCTL(KC_TAB), KC_NO,
KC_ENT, KC_LEFT, KC_UP, KC_RIGHT, KC_NO, KC_NO,
KC_NO, LALT(RGUI(KC_X)), KC_DOWN, KC_Q, KC_NO, KC_NO,
KC_TRNS, KC_TRNS, TG(VIEW)
),
};
