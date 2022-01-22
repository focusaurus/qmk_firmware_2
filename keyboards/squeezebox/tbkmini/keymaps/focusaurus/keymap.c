#include QMK_KEYBOARD_H

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

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

  /* COMBO_COLON, */
  /* COMBO_ENTER, */
  /* COMBO_EXCLAMATION, */
  /* COMBO_MINUS, */
  /* COMBO_MINUS2, */
  /* COMBO_PIPE, */
  /* COMBO_QUESTION, */
  COMBO_SEMICOLON,
  COMBO_FUZZBALL,
  /* COMBO_SLASH, */
  /* COMBO_SPACE, */
  /* COMBO_TAB, */
  /* COMBO_TILDE, */
  COMBO_BACKSPACE,
  COMBO_BACKSPACE2,
  /* COMBO_BRACKETS, */
  COMBO_ESCAPE,
  /* COMBO_PARENS, */

};

const uint16_t PROGMEM combo_semicolon[] = {KC_COLON, KC_Q, COMBO_END};
const uint16_t PROGMEM combo_fuzzball[] = {KC_U, KC_H, COMBO_END};
// const uint16_t PROGMEM combo_enter[] = {KC_E, KC_J, COMBO_END};
// const uint16_t PROGMEM combo_exclamation[] = {KC_Z, KC_DOT, COMBO_END};
// const uint16_t PROGMEM combo_minus2[] = {KC_S, KC_Z, COMBO_END};
// const uint16_t PROGMEM combo_minus[] = {KC_N, KC_S, COMBO_END};
// const uint16_t PROGMEM combo_pipe[] = {KC_Z, KC_P, COMBO_END};
// const uint16_t PROGMEM combo_question[] = {KC_Z, KC_COMMA, COMBO_END};
// const uint16_t PROGMEM combo_reset[] = {KC_F, KC_L, COMBO_END};
// const uint16_t PROGMEM combo_slash[] = {KC_T, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_space[] = {KC_U, KC_K, COMBO_END};
/* const uint16_t PROGMEM combo_tab[] = {KC_O, KC_Q, COMBO_END}; */
// const uint16_t PROGMEM combo_tilde[] = {KC_H, KC_M, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_Q, KC_J, COMBO_END};
const uint16_t PROGMEM combo_backspace2[] = {KC_U, KC_K, COMBO_END};
// const uint16_t PROGMEM combo_brackets[] = {KC_J, KC_E, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM combo_parens[] = {KC_U, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  [COMBO_SEMICOLON] = COMBO(combo_semicolon, KC_SCLN),
  [COMBO_FUZZBALL] = COMBO(combo_fuzzball, FUZZBALL),
  // [COMBO_ENTER] = COMBO(combo_enter, KC_ENT),
  // [COMBO_EXCLAMATION] = COMBO(combo_exclamation, KC_EXCLAIM),
  // [COMBO_MINUS2] = COMBO(combo_minus2, KC_MINUS),
  // [COMBO_MINUS] = COMBO(combo_minus, KC_MINUS),
  // [COMBO_PIPE] = COMBO(combo_pipe, KC_PIPE),
  // [COMBO_QUESTION] = COMBO(combo_question, KC_QUES),
  // [COMBO_SLASH] = COMBO(combo_slash, KC_SLSH),
  // [COMBO_SPACE] = COMBO(combo_space, KC_SPC),
  // [COMBO_TAB] = COMBO(combo_tab, KC_TAB),
  // [COMBO_TILDE] = COMBO(combo_tilde, KC_TILDE),
  [COMBO_BACKSPACE] = COMBO(combo_backspace, KC_BSPC),
  [COMBO_BACKSPACE2] = COMBO(combo_backspace2, KC_BSPC),
  // [COMBO_BRACKETS] = COMBO_ACTION(combo_brackets),
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  // [COMBO_PARENS] = COMBO_ACTION(combo_parens),

};
/*
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_BRACKETS:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
        tap_code16(KC_LEFT);
      }
      break;
    case COMBO_PARENS:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
        tap_code16(KC_LEFT);
      }
      break;
  }
}
*/
// Defines names for use in layer keycodes and the keymap
enum layer_names {

    DVORAK,
    MACOS,
    EDIT,
    NUMBERS,
    BANG,
    KBFN,
    VIEW

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO make a dedicated LAYOUT_fingers that leaves thumb clusters transparent
/* Base */
[DVORAK] = LAYOUT(

// TODO 1-finger combos for uk, ej, oq
// TODO 1-finger combo for semicolon
// left hand
KC_TAB, KC_QUOTE, TD(TD_COMMA), LALT_T(KC_DOT), LCTL_T(KC_P), KC_Y,
MT(MOD_LCTL, KC_ESC), MT(MOD_LGUI | MOD_LALT, KC_A), KC_O, KC_E, KC_U, KC_I,
KC_SCLN, KC_COLON /*TD(TD_SEMI)*/, KC_Q, KC_J, KC_K, KC_X,
LT(KBFN, KC_BSPC), LT(EDIT, LEADER), OSM(MOD_LSFT),

// TODO 1-finger combos for hm, tw, nv, sz
// right hand
KC_F, RCTL_T(KC_G), LALT_T(KC_C), KC_R, KC_L, KC_SLSH,
KC_D, KC_H, KC_T, KC_N, KC_S, KC_MINUS,
KC_B, KC_M, KC_W, KC_V, KC_Z, OSM(MOD_LALT),
LT(BANG, KC_ENT), LT(NUMBERS, KC_SPC), OSM(MOD_RCTL)

), [MACOS] = LAYOUT(

KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, OSM(MOD_RGUI)

), [EDIT] = LAYOUT(

// left hand
KC_NO, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
LSFT(KC_TAB), KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
RSFT(KC_EQL), KC_LCBR, KC_RCBR, LSFT(KC_GRV), KC_PIPE, KC_NO,
KC_EQL, KC_LPRN, KC_RPRN, KC_SLSH, KC_GRV, KC_NO,
KC_BSLS, KC_LBRC /*TD(TD_LBRC)*/, KC_RBRC /*TD(TD_RBRC)*/, KC_NO, KC_MINUS, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS

), [NUMBERS] = LAYOUT(

// HEADS UP: This is a copy of the left hand from the EDIT
// layer because QMK layers are dumb and don't really
// work in any kind of reasonable way.
// Without this copying, the default layer of DVORAK would fire
// which is not what I want
// left hand
KC_NO, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
LSFT(KC_TAB), KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_COMMA, KC_7, KC_8, KC_9, LSFT(KC_MINUS), KC_TRNS,
KC_DOT, KC_4, KC_5, KC_6, KC_0, KC_TRNS,
KC_COLON, KC_1, KC_2, KC_3, KC_MINUS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS

), [BANG] = LAYOUT(

// HEADS UP: This is a copy of the left hand from the EDIT
// layer because QMK layers are dumb and don't really
// work in any kind of reasonable way.
// Without this copying, the default layer of DVORAK would fire
// which is not what I want
// left hand
KC_NO, LGUI(KC_TAB), KC_BSPC, KC_SPC, KC_DEL, KC_PGUP,
LSFT(KC_TAB), KC_TAB, KC_LEFT, KC_UP, KC_RIGHT, KC_ENT,
LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_HOME, KC_DOWN, KC_END, KC_PGDN,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
LSFT(KC_EQL), LSFT(KC_7), LSFT(KC_8), KC_SLSH, KC_PIPE, KC_NO,
KC_EQL, LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), KC_MINUS, KC_NO,
// TODO maybe combo for a pair of curly braces for bash vars?
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
