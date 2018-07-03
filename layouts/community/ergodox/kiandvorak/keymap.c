#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define APP 2 // app layer
#define CNTL 3 // control layer
#define DQWRTY 4 // dvorak qwerty layer

bool lgui_pressed = false;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  L2/`  |   1  |   2  |   3  |   4  |   5  |CmdSpc|           | -    |   6  |   7  |   8  |   9  |   0  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | MEH/Tab|   '  |   <  |   >  |   P  |   Y  | MEH/\|           | ]    |   F  |   G  |   C  |   R  |   L  |    /   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Hyp/Esc |   A  |   O  |   E  |   U  |   I  |------|           |------|   D  |   H  |   T  |   N  |    S | Hyp/''  |
 * |--------+------+------+------+------+------| Tab  |           | STab |------+------+------+------+------+--------|
 * | LShift |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |L1/Lft|L3/Rht| LCtl | LAlt | LGui |                                       | Rgui |  Up  |  Dn  |  L3  |  L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.       ,-------------.
 *                                         | LCtl | LGui |       |AltGui|ShfGui|
 *                                 ,-------|------|------|       |------+--------+------.
 *                                 |       |      |L1/Hom|       |L2/PUp|       |       |
 *                                 | Backsp|Delete|------|       |------| Enter | Space |
 *                                 |       |      |L3/End|       |L1/PDn|       |       |
 *                                 `--------------------'       `-----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        LT(APP,KC_GRV),   KC_1,                KC_2,    KC_3,    KC_4,    KC_5,   LGUI(KC_SPC),
        KC_TAB,    KC_QUOT,             KC_COMM, KC_DOT,  KC_P,    KC_Y,   MEH_T(KC_BSLS),
        ALL_T(KC_ESC),    KC_A,                KC_O,    KC_E,    KC_U,    KC_I,
        KC_LSFT,          KC_SCLN,             KC_Q,    KC_J,    KC_K,    KC_X,   KC_TAB,
        LT(SYMB,KC_LEFT), LT(CNTL,KC_RIGHT),   KC_LCTL, KC_LALT, KC_LGUI, //MO(DQWRTY),
                                                                    KC_LCTL,   LT(DQWRTY,KC_A),
                                                                               LT(SYMB,KC_HOME),
                                                           KC_BSPC, KC_DELETE, LT(CNTL,KC_END),
        // right hand
       KC_MINS,          KC_6,    KC_7,    KC_8,     KC_9,      KC_0,             KC_EQL,
       KC_RBRC,          KC_F,    KC_G,    KC_C,     KC_R,      KC_L,             KC_SLSH,
                         KC_D,    KC_H,    KC_T,     KC_N,      KC_S,             ALL_T(KC_MINS),
       S(KC_TAB),        KC_B,    KC_M,    KC_W,     KC_V,      KC_Z,             KC_RSFT,
                                  KC_RGUI, KC_UP,    KC_DOWN,   KC_FN3,           KC_FN1,
       LALT(KC_LGUI),    S(KC_LGUI),
       LT(APP,KC_PGUP),
       LT(SYMB,KC_PGDN), KC_ENT, KC_SPC
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           | Tab  |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |  <   |           |  >   |   :  |   7  |   8  |   9  |   /  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------|   ;  |   4  |   5  |   6  |   *  |        |
 * |--------+------+------+------+------+------|  F14 |           | F15  |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   -  |  Entr  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |   0   |   . |  =   |   +  |       |
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
       KC_TRNS,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,S(KC_COMM),
       KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_F14,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TAB,    KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       S(KC_DOT), KC_COLN, KC_7,   KC_8,    KC_9,    KC_BSLS, KC_F12,
                  KC_SCLN, KC_4,   KC_5,    KC_6,    KC_ASTR, KC_TRNS,
       KC_F15,    KC_AMPR, KC_1,   KC_2,    KC_3,    KC_MINS, KC_ENT,
                           KC_0,   KC_DOT,  KC_EQL,  KC_PLUS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: App Layer
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * | BL Tog | BLDN | BLUP |      |      |      |Gradient|           | Plain|Brthe |Rainbw|Swirl |Snake |Knight|  Xmas  |
 * |--------+------+------+------+------+---------------|           |------+------+------+------+------+------+--------|
 * |        | CmdQ | CmdW |      |      |      | Stab   |           | Play | Prev | Next |      |      |PrtSc |        |
 * |--------+------+------+------+------+------|        |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |--------|           |------| VolDn|VolUp |      |      |      |        |
 * |--------+------+------+------+------+------|        |           | Mute |------+------+------+------+------+--------|
 * |        | CmdZ | CmdX | CmdC | CmdY | CtrlC|        |           |      | CmdN |      |      |      |      |        |
 * `--------+------+------+------+------+---------------'           `-------------+------+------+------+------+--------'
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
// Control
[APP] = LAYOUT_ergodox(
       KC_TRNS, RGB_MOD,    RGB_HUI,  RGB_HUD,    RGB_VAI,    RGB_VAD,    RGB_MODE_GRADIENT,
       RGB_TOG, LGUI(KC_Q), LGUI(KC_W), KC_TRNS,    KC_TRNS,    KC_TRNS,    S(KC_TAB),
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
       KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), LCTL(KC_C), KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,
                                              KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       RGB_MODE_PLAIN,  RGB_MODE_BREATHE, RGB_MODE_RAINBOW, RGB_MODE_SWIRL, RGB_MODE_SNAKE, RGB_MODE_KNIGHT, RGB_MODE_XMAS,
       KC_MPLY,  KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS,
                 KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_MUTE,  LGUI(KC_N), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),


/* Keymap 3: Control Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Pwr   |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght| Lclk |------|           |------|  Lft | Down | Up   | Right|      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | Rclk |      |           |      |      |      | Up   |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  Lft | Down | Right|      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Shift|      |       | Home | End  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | LAtl |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Control
[CNTL] = LAYOUT_ergodox(
       KC_PWR,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_LSFT, KC_TRNS,
                                                    KC_LALT,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_LEFT, KC_DOWN, KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_HOME, KC_END,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Dvorak-Qwerty Layer
 *
 * ,----------------------------------------------------.           ,--------------------------------------------------.
 * |        | Cmd1 | Cmd2 | Cmd3 |Cmd4  |Cmd5  |        |           |      |Cmd6  |Cmd7  |Cmd8  |Cmd9  |Cmd0  |        |
 * |--------+------+------+------+------+---------------|           |------+------+------+------+------+------+--------|
 * | CmdTab | CmdQ | CmdW |CmdE  | CmdR | CmdT | Stab   |           | Play | CmdY | CmdU | CmdI | CmdO | CmdP |        |
 * |--------+------+------+------+------+------|        |           |      |------+------+------+------+------+--------|
 * |        | CmdA | CmdS | CmdD | CmdF | CmdG |--------|           |------| CmdH | CmdJ | CmdK | CmdL |      |        |
 * |--------+------+------+------+------+------|        |           | Mute |------+------+------+------+------+--------|
 * |        | CmdZ | CmdX | CmdC | CmdY | CtrlC|        |           |      | CmdN | CmdM |      |      |      |        |
 * `--------+------+------+------+------+---------------'           `-------------+------+------+------+------+--------'
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
// Controlaaaa
[DQWRTY] = LAYOUT_ergodox(
       KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3),    LGUI(KC_4),    LGUI(KC_5),    KC_TRNS,
       KC_TRNS, LGUI(KC_Q), LGUI(KC_W), LGUI(KC_E),    LGUI(KC_R),    LGUI(KC_T),    S(KC_TAB),
       KC_TRNS, LGUI(KC_A), LGUI(KC_S), LGUI(KC_D),    LGUI(KC_F),    LGUI(KC_G),
       KC_TRNS, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C),    LGUI(KC_V),    LGUI(KC_B),    KC_TRNS,
       KC_TRNS, KC_TRNS,    KC_TRNS,    KC_LGUI,    KC_LGUI,
                                              KC_TRNS,  KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8),    LGUI(KC_9),    LGUI(KC_0),    KC_TRNS,
       KC_MPLY, LGUI(KC_Y), LGUI(KC_U), LGUI(KC_I),    LGUI(KC_O),    LGUI(KC_P),    S(KC_TAB),
                LGUI(KC_H), LGUI(KC_J), LGUI(KC_K),    LGUI(KC_L),    KC_TRNS,       KC_TRNS,
       KC_MUTE, LGUI(KC_N), LGUI(KC_M), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,

                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB),
    [2] = ACTION_LAYER_TAP_TOGGLE(APP),
    [3] = ACTION_LAYER_TAP_TOGGLE(CNTL),
    [4] = ACTION_LAYER_TAP_TOGGLE(DQWRTY)           // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
            break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

bool isDQ(keyrecord_t *record) {
   return record->event.pressed && lgui_pressed;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
      case KC_LGUI:
        if (record->event.pressed) {
          lgui_pressed = true;
          return true;
        } else {
          lgui_pressed = false;
          return true;
        }
  }
  if(isDQ(record)) {
      switch(keycode) {
          case KC_QUOT:
              SEND_STRING(SS_DOWN(X_Q));
              return false;
              break;
          case KC_COMM:
              SEND_STRING(SS_DOWN(X_W));
              return false;
              break;
          case KC_DOT:
              SEND_STRING(SS_DOWN(X_E));
              return false;
              break;
          case KC_P:
              SEND_STRING(SS_DOWN(X_R));
              return false;
              break;
          case KC_Y:
              SEND_STRING(SS_DOWN(X_T));
              return false;
              break;
          case KC_O:
              SEND_STRING(SS_DOWN(X_S));
              return false;
              break;
          case KC_E:
              SEND_STRING(SS_DOWN(X_D));
              return false;
              break;
          case KC_U:
              SEND_STRING(SS_DOWN(X_F));
              return false;
              break;
          case KC_I:
              SEND_STRING(SS_DOWN(X_G));
              return false;
              break;
          case KC_SCLN:
              SEND_STRING(SS_DOWN(X_Z));
              return false;
              break;
          case KC_Q:
              SEND_STRING(SS_DOWN(X_X));
              return false;
              break;
          case KC_J:
              SEND_STRING(SS_DOWN(X_C));
              return false;
              break;
          case KC_K:
              SEND_STRING(SS_DOWN(X_V));
              return false;
              break;
          case KC_X:
              SEND_STRING(SS_DOWN(X_B));
              return false;
              break;
          case KC_F:
              SEND_STRING(SS_DOWN(X_Y));
              return false;
              break;
          case KC_G:
              SEND_STRING(SS_DOWN(X_U));
              return false;
              break;
          case KC_C:
              SEND_STRING(SS_DOWN(X_I));
              return false;
              break;
          case KC_R:
              SEND_STRING(SS_DOWN(X_O));
              return false;
              break;
          case KC_L:
              SEND_STRING(SS_DOWN(X_P));
              return false;
              break;
          case KC_D:
              SEND_STRING(SS_DOWN(X_H));
              return false;
              break;
          case KC_H:
              SEND_STRING(SS_DOWN(X_J));
              return false;
              break;
          case KC_T:
              SEND_STRING(SS_DOWN(X_K));
              return false;
              break;
          case KC_N:
              SEND_STRING(SS_DOWN(X_L));
              return false;
              break;
          case KC_S:
              SEND_STRING(SS_DOWN(X_SCOLON));
              return false;
              break;
          case KC_B:
              SEND_STRING(SS_DOWN(X_N));
              return false;
              break;
          case KC_W:
              SEND_STRING(SS_DOWN(X_COMMA));
              return false;
              break;
          case KC_V:
              SEND_STRING(SS_DOWN(X_DOT));
              return false;
              break;
          case KC_Z:
              SEND_STRING(SS_DOWN(X_SLASH));
              return false;
              break;
      }
    } else {
        switch(keycode) {
          case KC_QUOT:
              SEND_STRING(SS_UP(X_Q));
              break;
          case KC_COMM:
              SEND_STRING(SS_UP(X_W));
              break;
          case KC_DOT:
              SEND_STRING(SS_UP(X_E));
              break;
          case KC_P:
              SEND_STRING(SS_UP(X_R));
              break;
          case KC_Y:
              SEND_STRING(SS_UP(X_T));
              break;
          case KC_O:
              SEND_STRING(SS_UP(X_S));
              break;
          case KC_E:
              SEND_STRING(SS_UP(X_D));
              break;
          case KC_U:
              SEND_STRING(SS_UP(X_F));
              break;
          case KC_I:
              SEND_STRING(SS_UP(X_G));
              break;
          case KC_SCLN:
              SEND_STRING(SS_UP(X_Z));
              break;
          case KC_Q:
              SEND_STRING(SS_UP(X_X));
              break;
          case KC_J:
              SEND_STRING(SS_UP(X_C));
              break;
          case KC_K:
              SEND_STRING(SS_UP(X_V));
              break;
          case KC_X:
              SEND_STRING(SS_UP(X_B));
              break;
          case KC_F:
              SEND_STRING(SS_UP(X_Y));
              break;
          case KC_G:
              SEND_STRING(SS_UP(X_U));
              break;
          case KC_C:
              SEND_STRING(SS_UP(X_I));
              break;
          case KC_R:
              SEND_STRING(SS_UP(X_O));
              break;
          case KC_L:
              SEND_STRING(SS_UP(X_P));
              break;
          case KC_D:
              SEND_STRING(SS_UP(X_H));
              break;
          case KC_H:
              SEND_STRING(SS_UP(X_J));
              break;
          case KC_T:
              SEND_STRING(SS_UP(X_K));
              break;
          case KC_N:
              SEND_STRING(SS_UP(X_L));
              break;
          case KC_S:
              SEND_STRING(SS_UP(X_SCOLON));
              break;
          case KC_B:
              SEND_STRING(SS_UP(X_N));
              break;
          case KC_W:
              SEND_STRING(SS_UP(X_COMMA));
              break;
          case KC_V:
              SEND_STRING(SS_UP(X_DOT));
              break;
          case KC_Z:
              SEND_STRING(SS_UP(X_SLASH));
              break;
      }
  }
return true;
}



// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      // TODO: Make this relevant to the ErgoDox EZ.
        case 1:
            ergodox_right_led_1_on();
                break;
        case 2:
            ergodox_right_led_2_on();
                break;
        case 3:
          ergodox_right_led_3_on();
              break;
        case 4:
          ergodox_right_led_1_on();
          ergodox_right_led_2_on();
              break;
        default:
            // none
                break;
    }

};
