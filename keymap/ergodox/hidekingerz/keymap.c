#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | Ent    |   1  |   2  |   3  |   4  |   5  | Left |           |Right |   6  |   7  |   8  |   9  |   0  |   ~    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  Up  |           |  Up  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| Down |           | Down |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |  L1  |  L2  |  L3  | LAlt | LGui |                                       |   -  |   =  |   [  |   ]  | ESC    |
 *   `----------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | LAlt | Cut  |       | Win< | Win> |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Copy |       |  MC  |      |      |
 *                                 | BSpc | Del  |------|       |------| SPC  | Ent  |
 *                                 |      |      | Paste|       |CtSftL|      |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
         // left hand
	KC_ENT,   KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_LEFT,
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_UP,
        KC_LCTRL, KC_A,     KC_S,     KC_D,    KC_F,    KC_G,
        KC_LSFT,  KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,    KC_DOWN,
        TO(0),    TO(1),    TO(2),    KC_LALT, KC_LGUI,
                                                        KC_LALT, ACTION_MODS_KEY(MOD_LGUI, KC_X),
                                                                 ACTION_MODS_KEY(MOD_LGUI, KC_C),
                                               KC_BSPC, KC_DELT, ACTION_MODS_KEY(MOD_LGUI, KC_V),
        // right hand
        KC_RIGHT, KC_6,   KC_7,     KC_8,     KC_9,     KC_0,      KC_GRV,
        KC_UP,    KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,      KC_BSLS,
                  KC_H,   KC_J,     KC_K,     KC_L,     KC_SCLN,   KC_QUOT,
        KC_DOWN,  KC_N,   KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,   KC_RSFT,
                          KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_ESC,
        ACTION_MODS_KEY(MOD_LCTL, KC_LEFT),   ACTION_MODS_KEY(MOD_LCTL, KC_RIGHT),
        ACTION_MODS_KEY(MOD_LCTL, KC_UP),
        LCTL(LSFT(KC_L)),  KC_SPC, KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  | TRNS |           | TRNS |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      | TRNS |           | TRNS |      |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       |   0  |      |   .  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 `--------------------'       `----------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
      // left hand
       KC_NO,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
       KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,
                                                  KC_TRNS, KC_TRNS,
                                                           KC_TRNS,
                                         KC_TRNS, KC_TRNS, KC_TRNS,
       // right hand
       KC_TRNS, KC_F6,  KC_F7, KC_F8, KC_F9,  KC_F10,  KC_F11,
       KC_TRNS, KC_NO,  KC_7,  KC_8,  KC_9,   KC_ASTR, KC_F12,
                KC_NO,  KC_4,  KC_5,  KC_6,   KC_PLUS, KC_NO,
       KC_TRNS, KC_NO,  KC_1,  KC_2,  KC_3,   KC_BSLS, KC_NO,
                        KC_0,  KC_NO, KC_DOT, KC_EQL,  KC_NO,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS,KC_TRNS
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |      |      |      |      |      | TRNS |           | TRNS |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      | TRNS |           | TRNS |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      | Lclk | Rclk |whl dn|whl up|        |
 * |--------+------+------+------+------+------| TRNS |           | TRNS |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |  Play  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | TRNS | TRNS | TRNS | TRNS | TRNS |                                       | Mute |VolDwn|VolUp | Prev | Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | TRNS | TRNS |       | TRNS | TRNS |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 | TRNS | TRNS |------|       |------| TRNS | TRNS |
 *                                 |      |      | TRNS |       | TRNS |      |      |
 *                                 `--------------------'       `----------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       RESET,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_TRNS,
       KC_NO,  KC_NO,   KC_NO,   KC_MS_U,  KC_NO,   KC_NO,  KC_TRNS,
       KC_NO,  KC_NO,   KC_MS_L, KC_MS_D,  KC_MS_R, KC_NO,
       KC_NO,  KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_TRNS,
       KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                                    KC_NO,  KC_NO,
                                                            KC_NO,
                                            KC_NO,  KC_NO,  KC_NO,
    // right hand
       KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
       KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,
                 KC_NO,  KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_U,KC_NO,
       KC_TRNS,  KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_MPLY,
                         KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV,KC_MNXT,
       KC_NO,  KC_NO,
       KC_NO,
       KC_NO,  KC_NO,  KC_NO
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    // TODO: Make this relevant to the ErgoDox EZ.
    case SYMB:
      ergodox_right_led_1_on();
      break;
    case MDIA:
      ergodox_right_led_2_on();
      break;
    default:
      // none
      break;
  }

};