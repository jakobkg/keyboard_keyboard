/* Copyright 2020 Jakob
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
#include "analog.h"
#include "qmk_midi.h"


enum control_change_keycodes {
    MI_CC_1 = SAFE_RANGE,
    MI_CC_2
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [0] = LAYOUT(

    MI_OCTD, MI_OCTU, MI_CC_1, MI_CC_2, \
    MI_Db, MI_Eb, MI_Gb, MI_Ab, MI_Bb, MI_Db_1, MI_Eb_1, MI_Gb_1, MI_Ab_1, MI_Bb_1, \
    MI_C, MI_D, MI_E, MI_F, MI_G, MI_A, MI_B, MI_C_1, MI_D_1, MI_E_1, MI_F_1, MI_G_1, MI_A_1, MI_B_1, MI_C_2

    )
};


uint8_t prevKnob1 = 0;
uint8_t prevKnob2 = 0;
uint8_t prevKnob3 = 0;
uint8_t currKnob1 = 0;
uint8_t currKnob2 = 0;
uint8_t currKnob3 = 0;


void knobs(void) {
    currKnob1 = analogReadPin(B5) >> 3;
    currKnob2 = analogReadPin(B4) >> 3;
    currKnob3 = analogReadPin(D7) >> 3;

    if (currKnob1 != prevKnob1) {
        prevKnob1 = currKnob1;
        midi_send_cc(&midi_device, 0, 0x0C, currKnob1);
    }

    if (currKnob2 != prevKnob2) {
        prevKnob2 = currKnob2;
        midi_send_cc(&midi_device, 0, 0x0D, currKnob2);
    }

    if (currKnob3 != prevKnob3) {
        prevKnob3 = currKnob3;
        midi_config.velocity = currKnob3;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MI_CC_1:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 0x0E, 127);
      } else {
        midi_send_cc(&midi_device, 0, 0x0E, 0);
      }
      return false;
    case MI_CC_2:
      if (record->event.pressed) {
        midi_send_cc(&midi_device, 0, 0x10, 127);
      } else {
        midi_send_cc(&midi_device, 0, 0x10, 0);
      }
      return false;
    default:
      return true;
  }
}


void matrix_scan_user(void) {
    knobs();
}
