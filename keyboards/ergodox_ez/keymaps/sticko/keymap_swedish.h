/*
 * keymap_swedish.h
 *
 *  Created on: May 24, 2016
 *      Author: simon
 */

#ifndef KEYBOARD_ERGODOX_EZ_KEYMAPS_STICKO_KEYMAP_SWEDISH_H_
#define KEYBOARD_ERGODOX_EZ_KEYMAPS_STICKO_KEYMAP_SWEDISH_H_


#include "keymap_nordic.h"

// There are slight differrences in the keyboards in the nordic contries
#define SE_ACUT	ALGR(NO_BSLS)  // ´
#define SE_AE	KC_QUOT  // æ
#define SE_OSLH	KC_SCLN  // ø
#define SE_PIPE KC_GRV  // |

// Additional norwegian keys not defined in the nordic keyset
#define SE_AA	KC_LBRC  // å
#define SE_ASTR LSFT(KC_BSLS)  // *

#endif /* KEYBOARD_ERGODOX_EZ_KEYMAPS_STICKO_KEYMAP_SWEDISH_H_ */
