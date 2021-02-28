#include QMK_KEYBOARD_H
#include "version.h"

#include "keymap_swedish.h"

enum Layers {
    BASE,   // default layer
    SYMB,   // symbols
    MDIA,   // media keys
    MOUSE,  // mouse layer
    XOURNAL,  // shortcuts for xournal
};

enum CustomKeycodes {
  VRSN = SAFE_RANGE,
  // Shortcuts in xournal
  XOUR_ERASE, // Eraser
  XOUR_PEN, // Pen
  XOUR_SEL_OBJ, // Select object
  XOUR_SEL_REC, // Select rectangle
  XOUR_VSPACE, // Vertical space
  XOUR_TXT, // Add text
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  esc   |   1  |   2  |   3  |   4  |   5  | MDIA |           | MDIA |   6  |   7  |   8  |   9  |   0  |   +    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   Å    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | caps   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   Ö  |   Ä    |
 * |--------+------+------+------+------+------| MDIA |           | MDIA |------+------+------+------+------+--------|
 * | Shift  |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |-/Crtl|  Shift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | PgUp | Home | PgDn | End  |  Alt |                                       | Alt  | Left | Down | Right|  Up    |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LGui | Home |       | PgUp |  App   |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | End  |       | PgDn |        |      |
 *                                 |Space | Del  |------|       |------| BSpace |Enter |
 *                                 |      |      | Symb |       | Symb |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*

//Use that Swedish and norwegian keyboards are the same.
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_ESC,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   MO(MDIA),
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   TG(XOURNAL),
        KC_CAPS,        KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        CTL_T(KC_Z),  KC_X,   KC_C,   KC_V,   KC_B,   MO(MDIA),
        KC_PGUP,        KC_HOME,      KC_PGDN,KC_END, KC_LALT,
		                                                      KC_LGUI,KC_HOME,
                                                                      KC_END,
                                                      KC_SPC, KC_DEL, MO(SYMB),
        // right hand
             MO(MDIA),    KC_6,   KC_7,   KC_8,   KC_9,   KC_0,             NO_PLUS,
             TG(MOUSE),   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             SE_AA,
                          KC_H,   KC_J,   KC_K,   KC_L,   SE_OSLH,          SE_AE,
             MO(MDIA),    KC_N,   KC_M,   KC_COMM,KC_DOT, CTL_T(NO_MINS),   KC_LSFT,
                                  KC_LALT,KC_LEFT,KC_DOWN,KC_RIGHT,         KC_UP,
             KC_PGUP, ALT_T(KC_APP),
             KC_PGDN,
			 MO(SYMB),KC_BSPC, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |   @  |   £  |  $   |   €  |      |           |      |      |      |   (  |   )  |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |   ~  |      |           |      |      |      |   [  |   ]  |   ^  |   ~    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   ´  |  $   |      |      |   `  |------|           |------|      |      |   {  |   }  |   *  |   '    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   |  |      |  ^   |      |      |      |           |      |      |      |   <  |   >  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS,KC_TRNS,NO_AT,  NO_PND, NO_DLR, SE_EU,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,NO_TILD,KC_TRNS,
       KC_TRNS,NO_ACUT,NO_DLR, KC_TRNS,KC_TRNS,NO_GRV,
       KC_TRNS,NO_PIPE,KC_TRNS,NO_CIRC,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, NO_LPRN, NO_RPRN, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, NO_LBRC, NO_RBRC, NO_CIRC, NO_TILD,
                KC_TRNS, KC_TRNS, NO_LCBR, NO_RCBR, SE_ASTR, NO_APOS,
       KC_TRNS, KC_TRNS, KC_TRNS, NO_LESS, NO_GRTR, NO_BSLS, KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and function keys.
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F11 |  F12 |      |      |      |      |           |      |      |      | Prev |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Stop | Next | Play |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |VolDwn|      | VolUp  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function keys
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_TRNS, KC_F11,  KC_F12,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MSTP, KC_MNXT, KC_MPLY, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_VOLD, KC_TRNS, KC_VOLU,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* MOUSE Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
// MOUSE
[MOUSE] = LAYOUT_ergodox(
       RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_MS_U,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN2
),
/* XOURNAL Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[XOURNAL] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,      XOUR_ERASE,  XOUR_SEL_REC, XOUR_TXT,     KC_TRNS,
       KC_TRNS, KC_TRNS,    XOUR_SEL_OBJ, KC_TRNS,     XOUR_PEN,     KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS,     XOUR_VSPACE,  KC_TRNS,      KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,      KC_TRNS,     KC_TRNS,
                                                                     KC_TRNS,      KC_TRNS,
                                                                                   KC_TRNS,
                                                       KC_TRNS,      KC_TRNS,      KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

// A macro for sending ctrl+shift+character
#define SEND_CTRL_SHIFT(character) SEND_STRING(SS_DOWN(X_LCTL) SS_LSFT(character) SS_UP(X_LCTL))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case XOUR_ERASE:
                SEND_CTRL_SHIFT("e");
                return false;
            case XOUR_PEN:
                SEND_CTRL_SHIFT("p");
                return false;
            case XOUR_SEL_REC:
                SEND_CTRL_SHIFT("r");
                return false;
            case XOUR_SEL_OBJ:
                SEND_CTRL_SHIFT("o");
                return false;
            case XOUR_TXT:
                SEND_CTRL_SHIFT("t");
                return false;
            case XOUR_VSPACE:
                SEND_CTRL_SHIFT("v");
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case SYMB:
          ergodox_right_led_1_on();
          break;
      case MDIA:
          ergodox_right_led_2_on();
          break;
      case MOUSE:
          ergodox_right_led_3_on();
          break;
      case XOURNAL:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
          break;
      default:
          // none
          break;
  }

  return state;
};
