/*
  safety.h - Interaction with security system such as E-stop and door sensors
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

#ifndef safety_h
#define safety_h

// Initialize the safety module
void safety_init();

// Get safety sensors state
uint8_t safety_get_state();

#endif
