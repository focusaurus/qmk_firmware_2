#include QMK_KEYBOARD_H

#define LEADER KC_F10
#define FUZZBALL KC_F11
#define SNIPPETS KC_F12

// const key_override_t coln_key_override =
//     ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN); // Shift : is ;

// const key_override_t** key_overrides = (const key_override_t*[]){
//     &coln_key_override,
//     NULL
// };

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

  COMBO_BASH_VAR,
  COMBO_ESCAPE,
  COMBO_ESCAPE_CORNER,
  COMBO_FUZZBALL,
  COMBO_QUOTE_VAR,
  COMBO_SPACE,

};

const uint16_t PROGMEM combo_bash_var[] = {KC_B, KC_V, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_E, KC_U, COMBO_END};
const uint16_t PROGMEM combo_escape_corner[] = {KC_U, KC_K, COMBO_END};
const uint16_t PROGMEM combo_fuzzball[] = {KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM combo_quote_var[] = {KC_Q, KC_V, COMBO_END};
const uint16_t PROGMEM combo_space[] = {KC_LCBR, KC_RCBR, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {

  [COMBO_BASH_VAR] = COMBO_ACTION(combo_bash_var),
  [COMBO_ESCAPE] = COMBO(combo_escape, KC_ESC),
  [COMBO_ESCAPE_CORNER] = COMBO(combo_escape_corner, KC_ESC),
  [COMBO_FUZZBALL] = COMBO(combo_fuzzball, FUZZBALL),
  [COMBO_QUOTE_VAR] = COMBO_ACTION(combo_quote_var),
  [COMBO_SPACE] = COMBO(combo_space, KC_SPC),

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
    VIEW,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// TODO make a dedicated LAYOUT_fingers that leaves thumb clusters transparent
/* Base */
[DVORAK] = LAYOUT(

// left hand
                    KC_Y, KC_P,
              KC_F, KC_L, KC_I,
        KC_A, KC_O, KC_E, KC_U,
        GUI_T(KC_X), ALT_T(KC_Q), CTL_T(KC_J), SFT_T(KC_K),
LT(KBFN, KC_BSPC), LT(NAVNUM, LEADER), OSM(MOD_LSFT),
// right hand

        KC_D, KC_B,
        KC_G, KC_C, KC_R,
        KC_H, KC_T, KC_N, KC_S,
        SFT_T(KC_M), CTL_T(KC_W), ALT_T(KC_V), GUI_T(KC_Z),
        KC_ENT, LT(BANG, KC_SPC), OSM(MOD_RCTL)

), [MACOS] = LAYOUT(

// This layer exists only to toggle GUI vs CTL
// for primary modifier (copy/paste/etc)
// between linux (default) and macos (layer toggle on)
KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,

KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
KC_TRNS, KC_TRNS, OSM(MOD_RGUI)

), [NAVNUM] = LAYOUT(
// This is my current daily driver secondary layer.
// I activate by holding left thumb on home key
// It gives me most edit and nav ability with just left hand
// and right gives me both a numpad and home row mods
// which pair nicely with arrow keys and backspace

// left hand
                  KC_PGUP, KC_PGDN,
         KC_BSPC, KC_SPC, KC_DEL,
KC_HOME, KC_LEFT, KC_UP, KC_RIGHT,
ALT_T(KC_END), KC_NO, KC_DOWN, SFT_T(KC_TAB),
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_COMMA, KC_DOT,
KC_7, KC_8, KC_9,
KC_4, KC_5, KC_6, KC_0,
SFT_T(KC_1), CTL_T(KC_2), ALT_T(KC_3), GUI_T(KC_MINUS),
KC_TRNS, KC_TRNS, KC_TRNS

), [BANG] = LAYOUT(

// This is my both-hands symbol layer.
// I used to have symbols distributed across 3 layers
// and currently I'm liking having almost everything
// on a single layer.
// The current bummer about this is I need a secondary 
// key for space since I'm holding my normal space key with right
// thumb to activate this layer.

// punctuation: . , : ; ! ? - _
// pairs: () {} [] <>
// quotes: ' " `
// unix: ~ / |
// numpad symbols: ! @ # $ % ^ & *
// math: + - * % / =
// all for reference: ! @ # $ % ^ & * ( ) { } [ ] < > . , / \ | ~ ` ' " - _ ; : + =

// left hand
                         KC_LT,   KC_GT,
               KC_MINUS, KC_LBRC, KC_RBRC,
KC_QUOTE, LSFT(KC_QUOTE), KC_LPRN, KC_RPRN,
KC_SCLN,  KC_GRV,        KC_LCBR, KC_RCBR,
KC_TRNS, KC_SPC, KC_ENT,

// right hand
KC_NO,      KC_NO,
LSFT(KC_EQL), KC_PIPE,          LSFT(KC_GRV),
KC_EQL,       KC_DOT,          KC_SLSH,      KC_NO,
KC_MINUS,     LSFT(KC_MINUS), KC_BSLS,        KC_QUES,
KC_TRNS, KC_TRNS, KC_TRNS

), [KBFN] = LAYOUT(
// This has function keys on the right hand which 
// I don't use often but are sometimes necessary
// and the left hand has some assorted keeb stuff.

// left hand
              KC_NO, KC_NO,
       KC_NO, KC_VOLU, KC_NO,
KC_NO, KC_NO, KC_MUTE, TG(VIEW),
KC_NO, KC_NO, KC_VOLD, KC_NO,
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_F10, KC_F11,
KC_F7, KC_F8, KC_F9,
KC_F4, KC_F5, KC_F6, KC_NO,
KC_F1, KC_F2, KC_F3, KC_F12,
KC_TRNS, KC_TRNS, TG(MACOS)

), [VIEW] = LAYOUT(

// This is a layer I can switch into from the KBFN layer
// if I want to leave navigation available in both hands
// without holding a key down

// left hand
                  KC_PGUP, KC_PGDN,
         KC_BSPC, KC_SPC, KC_DEL,
KC_HOME, KC_LEFT, KC_UP, KC_RIGHT,
ALT_T(KC_END), KC_NO, KC_DOWN, SFT_T(KC_TAB),
KC_TRNS, KC_TRNS, KC_TRNS,

// right hand
KC_PGDN, KC_PGUP,
KC_BSPC, KC_SPC, KC_DEL,
KC_LEFT, KC_UP, KC_RIGHT, KC_HOME,
SFT_T(KC_TAB), KC_DOWN, KC_NO, GUI_T(KC_END),
KC_TRNS, KC_TRNS, TG(VIEW)
)
};
