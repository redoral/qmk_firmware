 /* Copyright 2020 Naoki Katahira
  *
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 2 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <http://www.gnu.org/licenses/>.
  */

#include QMK_KEYBOARD_H
#include <stdio.h>

//extern uint8_t is_master;

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  _   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '"  |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |  +=  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGui | LAlt |MO(1) | /Space  /       \Enter \  |MO(1) |  ~`  |      |
 *            |      |      |      |/       /         \      \ |      |      |      |
 *            ----------------------------'           '------''----------------------
 */
[0] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                    KC_6,    KC_7,    KC_8,     KC_9,   KC_0,     KC_MINS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                    KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,     KC_BSPC,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                    KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,   KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,   KC_RBRC,KC_N,    KC_M,    KC_COMM,  KC_DOT, KC_SLSH,  KC_EQL,
                              KC_LGUI, KC_LALT, MO(1), KC_SPC,      KC_ENT,  MO(1), KC_GRV, XXXXXXX
),

/*
 * MO(1)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  |  F11 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Home |  Up  | End  |      |      |                    |  Ins |  Del |  MsU |   [  |   ]  |  F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  Lf  |  Dn  |  Rt  |      |      |-------.    ,-------|  Ms1 |  MsL |  MsD |  MsR |  Ms2 |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------| SclU | SclD |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      | /       /       \      \  |      |      |      |
 *            |      |      |      |/       /         \      \ |      |      |      |
 *            -----------------------------'           '------''----------------------
 */

[1] = LAYOUT(
  KC_TRNS, KC_F1,   KC_F2,    KC_F3,    KC_F4,   KC_F5,                       KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_TRNS, KC_HOME, KC_UP,    KC_END,   KC_TRNS, KC_TRNS,                     KC_INS,   KC_DEL,   KC_MS_U,  KC_LBRC,  KC_RBRC,  KC_F12,
  KC_TRNS, KC_LEFT, KC_DOWN,  KC_RGHT,  KC_TRNS, KC_TRNS,                     KC_BTN1,  KC_MS_L,  KC_MS_D,  KC_MS_R,  KC_BTN2,  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_WH_U,  KC_WH_D,  KC_BTN3,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* MO(2)
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      | /       /       \      \  |      |      |      |
 *            |      |      |      |/       /         \      \ |      |      |      |
 *            -----------------------------'           '------''----------------------
 */
[2] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

/* MO(3)
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|        |   |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |--------|   |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      | /       /       \      \  |      |      |      |
 *            |      |      |      |/       /         \      \ |      |      |      |
 *            -----------------------------'           '------''----------------------
 */
[3] = LAYOUT(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
)
};

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_270;  // flips the display 270 degrees if offhand
  return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

static void render_logo(void) {
    static const char PROGMEM junji_ito[] = {
      0x00, 0x42, 0x00, 0x00, 0x27, 0x13, 0x13, 0x51, 0x11, 0x10, 0x08, 0x01, 0x04, 0x04, 0x08, 0x00, 
      0x10, 0x09, 0x09, 0x01, 0x03, 0x03, 0x00, 0x01, 0x07, 0x07, 0x06, 0x03, 0x02, 0x00, 0x80, 0xc1, 
      0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x02, 0x03, 0x03, 0xc1, 0xc1, 
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 
      0x80, 0x80, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0xe0, 0x62, 0x62, 0x61, 0x21, 0x20, 0x20, 
      0xff, 0xff, 0xfe, 0xfe, 0xfe, 0x3e, 0x3e, 0x9e, 0xde, 0xce, 0x46, 0x47, 0x47, 0x4f, 0x1f, 0x03, 
      0xdf, 0x3f, 0xff, 0xfb, 0xf1, 0x03, 0xcf, 0xff, 0xff, 0xfc, 0xf8, 0xd8, 0xc0, 0xc0, 0x40, 0x60, 
      0xff, 0xff, 0xff, 0x67, 0x00, 0x7e, 0xc3, 0x01, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0xc0, 0x1f, 
      0xe0, 0xff, 0xff, 0xff, 0xc8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xb7, 0xc3, 0xc1, 0x60, 0x70, 
      0xff, 0xff, 0xff, 0xf8, 0xc0, 0xe0, 0x82, 0x86, 0x00, 0x50, 0xd0, 0xc0, 0xc0, 0xe3, 0xf8, 0xfc, 
      0xff, 0xff, 0xff, 0x7f, 0x3f, 0x9f, 0xcf, 0x67, 0x37, 0x97, 0xc9, 0xc9, 0x64, 0x24, 0x26, 0xb2, 
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
      0x1f, 0x43, 0x19, 0x84, 0x22, 0x0b, 0x06, 0x32, 0xdb, 0x69, 0xb4, 0x96, 0x6a, 0x6b, 0x35, 0x95, 
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x01, 
      0x06, 0xf8, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0xcb, 0x75, 0x8a, 0x6d, 0xad, 0xb6, 
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 
      0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x11, 0x0c, 0x23, 0xe4, 0x1b, 0xdb, 
      0x7f, 0x3f, 0x7f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1f, 
      0x1f, 0xdc, 0xf8, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x02, 0x01, 
      0x20, 0x0c, 0x86, 0xe0, 0x71, 0x38, 0x18, 0x18, 0x0c, 0x00, 0x01, 0x81, 0x06, 0x09, 0x73, 0xcc, 
      0x00, 0x80, 0x1f, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfc, 0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 
      0xc0, 0x00, 0x0f, 0xf1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
      0xff, 0x00, 0xff, 0xfe, 0xe1, 0x83, 0x1f, 0x3f, 0xff, 0xff, 0xff, 0xb3, 0x33, 0x1c, 0x08, 0x08, 
      0xff, 0xfc, 0xe0, 0xc3, 0x0c, 0x1c, 0x7c, 0xf8, 0xf8, 0xf8, 0xf0, 0xf0, 0x30, 0x80, 0xc0, 0xf8, 
      0x1f, 0x00, 0xff, 0xff, 0xff, 0xff, 0x80, 0x80, 0xff, 0xff, 0xff, 0xff, 0x7e, 0xf8, 0xf8, 0xf1, 
      0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf8, 0xf0, 0xe0, 0xe0, 0xfc, 0xf8, 0xfe, 0xff, 0xfd, 0xf8, 
      0xf8, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfd, 0x78, 0x60, 0x01, 0x00, 
      0xff, 0x7f, 0x7f, 0xbf, 0xbf, 0x3f, 0x3f, 0xbf, 0xbf, 0x3f, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0x0f, 0x1e, 0x30, 0x20, 0x20, 
      0x00, 0x01, 0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
      0x01, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x0f, 0x0f, 0x0c, 0x08, 0x00, 0x00
    };

    oled_write_raw_P(junji_ito, sizeof(junji_ito));
}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
    case _QWERTY:
        oled_write_ln_P(PSTR("Default"), false);
        break;
    case _RAISE:
        oled_write_ln_P(PSTR("Raise"), false);
        break;
    case _LOWER:
        oled_write_ln_P(PSTR("Lower"), false);
        break;
    case _ADJUST:
        oled_write_ln_P(PSTR("Adjust"), false);
        break;
    default:
        oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);

  } else {
      render_logo();
  }
    return false;
}
#endif // OLED_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}
