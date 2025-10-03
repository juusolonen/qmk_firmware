 /* Copyright 2021 Dane Evans
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
  // juubo rev 1.0
#include <stdio.h>
#include "action.h"
#include "dip_switch.h"
#include "keycodes.h"
#include "print.h"
#include "quantum_keycodes.h"

#include QMK_KEYBOARD_H
#include "keymap_finnish.h"

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)
#define TAPPING_TERM 200

enum juubo_layers {
    _BASE = 0,
    _SYM,
    _NUM
};

 enum combos {
  // CB_ADIA,
//   CB_TAB,
//   CB_BSPC,
   CB_ENT,
//   CB_DEL,
    LAST
 };

 enum TAPDANCE{
    PIPE_BLSH,
    TLD_CRT,
    LALT_EQL,
    PAR_BRK,
    PAR_BRK_R,
    CMD_LFT,
    CMD_RGT,
    ODIA_ADIA
};

 const uint16_t PROGMEM combo_adia[]  = {KC_A, KC_R, COMBO_END};
// const uint16_t PROGMEM combo_tab[]  = {KC_X, KC_C, COMBO_END};
// const uint16_t PROGMEM combo_bspc[] = {KC_I, FI_O, COMBO_END};
 const uint16_t PROGMEM combo_ent[]  = {KC_Q, KC_BSPC, COMBO_END};
// const uint16_t PROGMEM combo_del[]  = {FI_DOT, FI_ADIA, COMBO_END};

 combo_t key_combos[LAST] = {
  // [CB_ADIA]  = COMBO(combo_adia, FI_ADIA),
//   [CB_TAB]  = COMBO(combo_tab, KC_TAB),
//   [CB_BSPC] = COMBO(combo_bspc, KC_BSPC),
   [CB_ENT]  = COMBO(combo_ent, KC_ENT),
//   [CB_DEL]  = COMBO(combo_del, KC_DEL),
 };

#define MO_SYM  MO(_SYM)
#define MO_NAV  MO(_NAV)
#define TG_CLMK TG(JOKU)
#define PIPE RALT(KC_7) // |   
#define FIEQL S(KC_0) // |
#define LBRACE RALT(RSFT(KC_8))
#define RBRACE RALT(RSFT(KC_9))


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // -----------------------------------------------------------------------------------------
// |  Q  |  W  |  F  |  P  |  B  |                            |  J  |  L   |  U  |  Y  |  Ö/Ä  |
// |  A  |  R  |  S  |  T  |  G  |                            |  M  |  N   |  E  |  I  |  O    |
// |  Z  |  X  |  C  |  D  |  V  |                            |  K  |  H   |  ,  |  .  |  -    | 
//    | DEL/NUM | SPC/SYM | BSPC |                            | TAB | ENT/NUM | ESC/SYM |

[_BASE] = LAYOUT(
   KC_Q,           KC_W,           KC_F,             KC_P,             KC_B,                    KC_J,    KC_L,              KC_U,            KC_Y,            TD(ODIA_ADIA),  
   GUI_T(KC_A),    CTL_T(KC_R),    SFT_T(KC_S),      ALT_T(KC_T),      KC_G,                    KC_M,    LALT_T(KC_N),      RSFT_T(KC_E),    CTL_T(KC_I),    GUI_T(KC_O),
   KC_Z,           KC_X,           KC_C,             KC_D,             KC_V,                    KC_K,    KC_H,              FI_COMM,         FI_DOT,          FI_MINS, 
                                           LT(_NUM, KC_DEL), LT(_SYM, KC_SPC), KC_BSPC,                 KC_TAB,  LT(_NUM, KC_ENT),  LT(_SYM, KC_ESC)
),
// -----------------------------------------------------------------------------------------
// | ~^ | ? | ! | @ | "|"\ |                                 |  ´  |   {   |  [( |  )] |  } |
// | #  | - | + | = |  &   |                                 |PG_UP|LFTHOME| UP  | DWN |RGTEND| 
// | €  | % | / | ' |  "   |                                 |PG_DN|   <   |  ;  |  :  | >   | 
//          | $ |___|      |                                 |     |       |LSFT |
[_SYM] = LAYOUT(
   TD(TLD_CRT),     FI_QUES,        FI_EXLM,        FI_AT,         TD(PIPE_BLSH),                 FI_ACUT,    RALT(KC_7),      TD(PAR_BRK), TD(PAR_BRK_R), RALT(KC_0),  
   FI_HASH,         GUI_T(FI_MINS), SFT_T(FI_PLUS), TD(LALT_EQL),  FI_AMPR,                       KC_PGUP,    TD(CMD_LFT), KC_UP,       KC_DOWN,       TD(CMD_RGT),
   RALT(KC_E),      S(KC_5),        FI_SLSH,        KC_BACKSLASH,  FI_DQUO,                       KC_PGDN,    KC_NUBS,     FI_SCLN,     FI_COLN,        S(KC_NUBS), 
                                            FI_DLR,         _______,       _______,                       C(KC_C),    KC_LSFT,     C(KC_V)
),
// -----------------------------------------------------------------------------------------
// |  F1 | F2 |  F3  | F4  |  F5 |                           |     |  7  |  8  |  9  |      |
// |  F6 | F7 |  F8  | F9  | F10 |                           |  0  |  4  |  5  |  6  | CTRL |
// |     |    |  F11 | F12 |     |                           |     |  1  |  2  |  3  |      | 
//            |  GUI |     |     |                           | ENT |     | ALT |
[_NUM] = LAYOUT(
   KC_F1,    KC_F2,     KC_F3,         KC_F4,       KC_F5,                         _______,    KC_7,    KC_8,  KC_9, _______,  
   KC_F6,    KC_F7,     KC_F8,         KC_F9,       KC_F10,                        KC_0,       KC_4,    KC_5,  KC_6, KC_LEFT_GUI,
   _______,   _______,  KC_F11,        KC_F12,      _______,                       _______,    KC_1,    KC_2,  KC_3, _______, 
                                KC_LEFT_CTRL,  _______, _______,                       _______,    _______, _______
),
};
//layer_state_t layer_state_set_user(layer_state_t state) {
  // return update_tri_layer_state(state, _SYM, _NAV, _FUN);
//}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(C(KC_F4), C(KC_F4)),       ENCODER_CCW_CW(A(C(KC_LEFT)),  A(C(KC_RIGHT))) },
    [_SYM] = {  ENCODER_CCW_CW(C(KC_TAB),  C(S(KC_TAB))),      ENCODER_CCW_CW(_______, _______) },
    [_NUM]  = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),       ENCODER_CCW_CW(S(KC_TAB), KC_TAB) },
   //[_NAV]  = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)),  ENCODER_CCW_CW(RGB_SPD,  RGB_SPI) },
  // [_FUN]  = { ENCODER_CCW_CW(RGB_HUD,  RGB_HUI),       ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif

#if defined(DIP_SWITCH_MAP_ENABLE)
const uint16_t PROGMEM dip_switch_map[NUM_DIP_SWITCHES][2] = {
    DIP_SWITCH_OFF_ON(dip_switch_update_user(0, false), dip_switch_update_user(0, true)),
    DIP_SWITCH_OFF_ON(dip_switch_update_user(1, false), dip_switch_update_user(1, true)),   
    };
#endif


bool dip_switch_update_user(uint8_t index, bool active) { 
    switch (index) {
        case 0:
            if(active) { tap_code16(G(S(KC_TILD))); } 
            break;
        case 1:
            if(active) { tap_code(KC_K); }
            break;
    }                     
    return true;
}         



typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(LALT_EQL):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[2];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(CMD_LFT): 
            action = &tap_dance_actions[5];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        case TD(CMD_RGT):  
            action = &tap_dance_actions[6];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }



// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [PIPE_BLSH] = ACTION_TAP_DANCE_DOUBLE(RALT(KC_NUBS), RALT(KC_MINUS)),
    [TLD_CRT] = ACTION_TAP_DANCE_DOUBLE(FI_TILD, S(FI_DIAE)),
    [LALT_EQL] = ACTION_TAP_DANCE_TAP_HOLD(FI_EQL, KC_LALT),
    [PAR_BRK] = ACTION_TAP_DANCE_DOUBLE(FI_LPRN, FI_LBRC),
    [PAR_BRK_R] = ACTION_TAP_DANCE_DOUBLE(FI_RPRN, FI_RBRC),
    [CMD_LFT] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT, KC_HOME),
    [CMD_RGT] = ACTION_TAP_DANCE_TAP_HOLD(KC_RIGHT, KC_END),
    [ODIA_ADIA] = ACTION_TAP_DANCE_DOUBLE(FI_ODIA, FI_ADIA),
};
