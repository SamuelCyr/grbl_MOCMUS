/*
  safety.c - Interaction with security system such as E-stop and door sensors
  Added by MOCMUS to complement grbl implementation

  Grbl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  Grbl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with Grbl.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "grbl.h"

void safety_init()
{
  SAFETY_DDR  &= ~(SAFETY_MASK); // Configure as input pins
  SAFETY_PORT |= SAFETY_MASK;    // Enable internal pull-up resistors. Normal high operation.
}


// NOTE: For now, the system only check for the state of the safety sensors when asked by the user
// (with "?" command).
// TODO: Check for the safety_sate the same way "system_control_get_state()" is used.
// In other words, an alarm should be generated when one of the sensor is triggered for more security (in the
// MOCMUS machine, this is not needed since the security system in completely hardware. Therefore, the
// power to all the motors is simply cut-off when one of these sensors is triggered).
uint8_t safety_get_state()
{
  uint8_t safety_state = 0;
  uint8_t pin = (SAFETY_PIN & SAFETY_MASK);
  #ifdef INVERT_SAFETY_PIN_MASK
    pin ^= INVERT_SAFETY_PIN_MASK;
  #endif
  if (pin) {
    if (bit_isfalse(pin,(1<<SAFETY_DOOR_PANEL_BIT))) { safety_state |= SAFETY_PIN_INDEX_DOOR_PANEL; }
    if (bit_isfalse(pin,(1<<SAFETY_DOOR_FRONT_L_BIT))) { safety_state |= SAFETY_PIN_INDEX_DOOR_FRONT_L; }
    if (bit_isfalse(pin,(1<<SAFETY_DOOR_FRONT_R_BIT))) { safety_state |= SAFETY_PIN_INDEX_DOOR_FRONT_R; }
    if (bit_isfalse(pin,(1<<SAFETY_ESTOP_BIT))) { safety_state |= SAFETY_PIN_INDEX_ESTOP; }
  }
  return(safety_state);
}
