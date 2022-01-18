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
  LA1, LA2, LA3, LA4, LA5, LA6, \
  LB1, LB2, LB3, LB4, LB5, LB6, \
  LC1, LC2, LC3, LC4, LC5, LC6, \
  LD1, LD2, LD3, \
  RA6, RA5, RA4, RA3, RA2, RA1, \
  RB6, RB5, RB4, RB3, RB2, RB1, \
  RC6, RC5, RC4, RC3, RC2, RC1, \
  RD3, RD2, RD1 \
) { \
  { LA1, LA2, LA3, LA4, LA5, LA6, LD3 }, \
  { LB1, LB2, LB3, LB4, LB5, LB6, LD2 }, \
  { LC1, LC2, LC3, LC4, LC5, LC6, LD1 }, \
  { RA1, RA2, RA3, RA4, RA5, RA6, RD3 }, \
  { RB1, RB2, RB3, RB4, RB5, RB6, RD2 }, \
  { RC1, RC2, RC3, RC4, RC5, RC6, RD1 } \
}
