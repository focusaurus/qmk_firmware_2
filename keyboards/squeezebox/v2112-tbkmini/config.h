#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// P"e"t"e" 16 Wheeler
#define VENDOR_ID 0xEE16
#define PRODUCT_ID 0x0001
// v2112 decimal in hex
#define DEVICE_VER 0x0840
#define MANUFACTURER Peter Lyons
#define PRODUCT squeezebox-v2112-tbkmini

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 7

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
// Left side is B5, B4, E6, D7, C6, D4, D0, D1, GND, GND, D2, D3
// right side is B6, B2, B3, B1, F7, F6, F5, F4, VCC, RST, GND, B0
// For squeezebox v2112
// #define MATRIX_ROW_PINS { B5, B4, E6 }
// #define MATRIX_COL_PINS { B6, B2, B3, B1, F7, F6, F5 }
// For bastardkb/tbkmini
#define MATRIX_ROW_PINS { B6, B2, B3 }
#define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4, D0 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D1  // or D1, D2, D3, E6
#define SPLIT_USB_DETECT

#define UNUSED_PINS

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
