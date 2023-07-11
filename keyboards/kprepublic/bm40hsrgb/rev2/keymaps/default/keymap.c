/* Copyright 2022 bdtc123
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
#include "features/caps_word.h"

enum my_keycodes {
    RMT = SAFE_RANGE,
    RMS,
    RMIH,
    RMDH,
    RMIS,
    RMDS,
    RMIV,
    RMDV,
    MyM3,
    MySafeReset = 0,
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 5) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [MySafeReset] = ACTION_TAP_DANCE_FN(safe_reset)
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_caps_word(keycode, record)) { return false; }

    switch (keycode) {
        case RMT:
            if (record->event.pressed){
                rgb_matrix_toggle();
            }
            return false;

        case RMS:
            if (record->event.pressed){
                rgb_matrix_step();
            }
            return false;

        case RMIH:
            if (record->event.pressed){
                rgb_matrix_increase_hue();
            }
            return false;

        case RMDH:
            if (record->event.pressed){
                rgb_matrix_decrease_hue();
            }
            return false;

        case RMIS:
            if (record->event.pressed){
                rgb_matrix_increase_sat();
            }
            return false;

        case RMDS:
            if (record->event.pressed){
                rgb_matrix_decrease_sat();
            }
            return false;

        case RMIV:
            if (record->event.pressed){
                rgb_matrix_increase_val();
            }
            return false;

        case RMDV:
            if (record->event.pressed){
                rgb_matrix_decrease_val();
            }
            return true;

        //my custom code
        static uint16_t fnx_layer_timer;
        case MyM3:
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                layer_on(3);
            } else {
                layer_off(3);
                if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM) {
                    set_oneshot_layer(3, ONESHOT_START);
                }
            }
            return false;
            break;


        default:
            //clear_oneshot_mods();
            clear_oneshot_layer_state(ONESHOT_PRESSED);
            return true;
    }

    // Detect the activation of both Shifts
    if ((get_mods() & MOD_MASK_SHIFT) == MOD_MASK_SHIFT)
    {
        // Toggle Caps_lock value
        tap_code(KC_CAPS);
    }

    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_planck_mit(
    KC_ESC, KC_J, KC_D, KC_U, KC_A, KC_Q, KC_P, KC_H, KC_L, KC_M, KC_W, KC_BSPC,
    KC_TAB, KC_C, KC_T, KC_I, KC_E, KC_O, KC_B, KC_N, KC_R, KC_S, KC_G, KC_ENT,
    KC_LSFT, KC_F, KC_V, KC_Y, KC_X, OSL(4), OSL(4), KC_Z, KC_COMM, KC_DOT, KC_K, KC_RSFT,
    KC_LGUI, KC_LALT, KC_LCTL, MO(3), MO(2), LT(1,KC_SPC), KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_RGUI
    ),

[1] = LAYOUT_planck_mit(
    KC_NO, KC_NO, KC_UNDS, KC_LBRC, KC_RBRC, KC_CIRC, KC_EXLM, KC_LT, KC_GT, KC_EQL, KC_AMPR, KC_BSPC,
    KC_NO, KC_BSLS, KC_SLSH, KC_LCBR, KC_RCBR, KC_PAST, KC_QUES, KC_LPRN, KC_RPRN, KC_PMNS, KC_COLN, KC_AT,
    KC_NO, KC_HASH, KC_DLR, KC_PIPE, KC_TILD, KC_GRV, KC_PPLS, KC_PERC, KC_DQUO, KC_QUOT, KC_SCLN, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, LAG(KC_LBRC), LAG(KC_LCBR), LAG(KC_RCBR), LAG(KC_RBRC), KC_NO
   ),

[2] = LAYOUT_planck_mit(
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSLS, KC_PMNS, KC_7, KC_8, KC_9, KC_NO, KC_BSPC,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PAST, KC_PPLS, KC_4, KC_5, KC_6, KC_COLN, KC_ENT,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_1, KC_2, KC_3, KC_SCLN, KC_NO,
    KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_SPC, KC_0, KC_COMM, KC_DOT, KC_NO, KC_NO
   ),

[3] = LAYOUT_planck_mit(
KC_NO, RMT, RMS, RMIH, RMDH, KC_NO, KC_NO, KC_F7, KC_F8, KC_F9, KC_F10, /*LSFT(LAG(KC_ESC))*/KC_DEL,
KC_NO, RMIS, RMDS, RMIV, RMDV, KC_NO, KC_NO, KC_F4, KC_F5, KC_F6, KC_F11, RSG(KC_5),
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_F1, KC_F2, KC_F3, KC_F12, KC_RSFT,
KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO, TD(MySafeReset), RSG(KC_GRV), RCTL(KC_4),  RCS(KC_4),  RGUI(KC_GRV), KC_RGUI),

[4] = LAYOUT_planck_mit(
KC_NO, KC_NO, KC_NO, RALT(KC_U), RALT(KC_A), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RALT(KC_O), KC_NO, KC_NO, KC_NO, RALT(KC_S), KC_NO, KC_NO, 
KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_RSFT, 
KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO),


};
