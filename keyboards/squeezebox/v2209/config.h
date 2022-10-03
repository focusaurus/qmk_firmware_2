#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
// P"e"t"e" 16 Wheeler
#define VENDOR_ID 0xEE16
#define PRODUCT_ID 0x0001
// v2209 decimal in hex
#define DEVICE_VER 0x0001
#define MANUFACTURER Peter Lyons
#define PRODUCT squeezebox-v2209

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

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
// For squeezebox v2209 (PCB side A)
#define MATRIX_ROW_PINS { B5, B4, E6, D7 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3 }
// For squeezebox v2209 (PCB side B)
// #define MATRIX_ROW_PINS { B1, B3, B2, B6 }
// #define MATRIX_COL_PINS { D0, D4, C6, D7, E6 }
// For bastardkb/tbkmini
// #define MATRIX_ROW_PINS { B6, B2, B3 }
// #define MATRIX_COL_PINS { B5, B4, E6, D7, C6, D4, D0 }
/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW
/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D1  // or D1, D2, D3, E6
#define SPLIT_USB_DETECT

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5
