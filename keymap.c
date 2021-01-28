/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"


// Shortcuts
#define NextTab   LCTL(KC_TAB)
#define Prevtab   LCTL(LSFT(KC_TAB))
#define LastOpen  LCTL(LSFT(KC_T))
#define AltF4     LALT(KC_F4)

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Enter|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Caps | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  | Right|
 * `-----------------------------------------------------------------------------------'
 */

[_QWERTY] = LAYOUT_preonic_grid(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,
  KC_ENT,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  KC_LCTL, KC_CAPS, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |ALt+F4| DM1P | DM2P |KeyLoc|      |      |      |      |  F1  |  F2  |  F3  |Insert|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Vol+ |PreTab|NexTab|LOpen |      |      |      |M1Rec |  F4  |  F5  |  F6  |PrtScr|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Vol- |PTrack| PLay |NTrack|      |      |      |M2Rec |  F7  |  F8  |  F9  |Pause |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Mute | Comp | CALC | Mail |      |      |      |DMStop|  F10 |  F11 |  F12 |ScrLoc|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Home |PgDown| PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */

[_LOWER] = LAYOUT_preonic_grid(
  AltF4,    DM_PLY1, DM_PLY2,  KC_LOCK, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_INS,
  KC_VOLU,  Prevtab,  NextTab, LastOpen, _______, _______, _______, DM_REC1, KC_F4, KC_F5, KC_F6, KC_PSCR,
  KC_VOLD,  KC_MPRV,  KC_MPLY, KC_MNXT,  _______, _______, _______, DM_REC2, KC_F7, KC_F8, KC_F9, KC_PAUSE,
  KC_MUTE,  KC_MYCM,  KC_CALC, KC_MAIL,  _______, _______, _______, DM_RSTP, KC_F10, KC_F11, KC_F12, KC_SCROLLLOCK,
  _______,  _______,    _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN, KC_END
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |      |      |      |      |      |      |      | NumL |   /  |   *  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   `  |   (  |   )  |   +  |   -  |      |      |      |  k7  |  k8  |  k9  |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |   {  |   }  |   _  |   =  |      |      |      |  k4  |  k5  |  k6  |  +   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   [  |   ]  |   |  |   \  |      |      |      |  k1  |  k2  |  k3  |Kenter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |K0/Del|      |K./Del|      |
 * `-----------------------------------------------------------------------------------'
 */

[_RAISE] = LAYOUT_preonic_grid(
  KC_TILDE, _______, _______, _______, _______, _______, _______, _______, KC_NLCK, KC_PSLS, KC_PAST, KC_BSPC,
  KC_GRV,  KC_LPRN, KC_RPRN, KC_PLUS, KC_MINS, _______, _______, _______,  KC_KP_7, KC_KP_8, KC_KP_9, KC_PMNS,
  _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_EQL, _______, _______,  _______,  KC_KP_4, KC_KP_5, KC_KP_6, KC_PPLS,
  _______, KC_LBRC, KC_RBRC, KC_PIPE, KC_BSLS, _______, _______, _______,  KC_KP_1, KC_KP_2, KC_KP_3, KC_PENT,
  _______, _______, _______, _______, _______, _______, _______, _______,  KC_KP_0, _______, KC_PDOT, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      | F13  | F14  | F15  |Power |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Reset |Debug |CReset|      |      |      |      | F16  | F17  | F18  |Sleep |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Aud On|AudOff|AudTog|      |      |      |      | F19  | F20  | F21  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |MusOn |MusOff|MusTog|MusMod|      |      |      | F22  | F23  | F24  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[_ADJUST] = LAYOUT_preonic_grid(
  _______, _______, _______, _______, _______, _______, _______, _______, KC_F13, KC_F14, KC_F15, KC_PWR,
  _______, RESET, DEBUG, EEPROM_RESET, _______, _______, _______, _______, KC_F16, KC_F17, KC_F18, KC_SLEP,
  _______, AU_ON, AU_OFF, AU_TOG, _______, _______, _______, _______, KC_F19, KC_F20, KC_F21, _______,
  _______, MU_ON, MU_OFF, MU_TOG, MU_MOD, _______, _______, _______, KC_F22, KC_F23, KC_F24, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
