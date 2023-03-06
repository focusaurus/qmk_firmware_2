#pragma once

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
*
* The first section contains all of the arguments representing the physical
* layout of the board and position of the keys.
*
* The second converts the arguments into a two-dimensional array which
* represents the switch matrix.
*/

#define LAYOUT( \
            LM4, LI4, \
       LR3, LM3, LI3, \
  LP2, LR2, LM2, LI2, \
  LP1, LR1, LM1, LI1, \
  LT1, LT2, LT3, \
  RI4, RM4, \
  RI3, RM3, RR3, \
  RI2, RM2, RR2, RP2, \
  RI1, RM1, RR1, RP1, \
  RT3, RT2, RT1 \
) { \
  { KC_NO, LI4, LM4, KC_NO, KC_NO }, \
  {   LT3, LI3, LM3, LR3, KC_NO }, \
  {   LT2, LI2, LM2, LR2, LP2 }, \
  {   LT1, LI1, LM1, LR1, LP1 }, \
  { KC_NO, KC_NO, RM4, RI4, KC_NO }, \
  { KC_NO,   RR3, RM3, RI3, RT3 }, \
  {   RP2,   RR2, RM2, RI2, RT2 }, \
  {   RP1,   RR1, RM1, RI1, RT1 } \
}
