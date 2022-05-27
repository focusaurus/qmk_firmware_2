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
  LP4, LR4, LM4, LI4, \
  LP3, LR3, LM3, LI3, \
  LP2, LR2, LM2, LI2, \
  LP1, LR1, LM1, LI1, \
  LT1, LT2, LT3, \
  RI4, RM4, RR4, RP4, \
  RI3, RM3, RR3, RP3, \
  RI2, RM2, RR2, RP2, \
  RI1, RM1, RR1, RP1, \
  RT3, RT2, RT1 \
) { \
  { LP4, LR4, LM4, LI4 }, \
  { LP3, LR3, LM3, LI3 }, \
  { LP2, LR2, LM2, LI2 }, \
  { LP1, LR1, LM1, LI1 }, \
  { LT1, LT2, LT3, LNO }, \
  { RI4, RM4, RR4, RP4 }, \
  { RB3, RB3, RB3, RB3 }, \
  { RC2, RC2, RC2, RC2 } \
  { RD1, RD1, RD1, RD1 } \
  { RT3, RT2, RT1, RNO } \
}
