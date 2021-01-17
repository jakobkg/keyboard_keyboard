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

#pragma once

#include "quantum.h"

#define xxx KC_NO
#define LAYOUT( \
         k01, k02,   k03, k04, \
      k11, k12,      k14, k15, k16,      k31, k32,     k34, k35, k36, \
	k21, k22, k23, k24, k25, k26, k27, k41, k42, k43, k44, k45, k46, k47, k48 \
) \
{ \
    { k01, k02, k03, k04, xxx, xxx, xxx, xxx }, \
    { k11, k12, xxx, k14, k15, k16, xxx, xxx }, \
    { k21, k22, k23, k24, k25, k26, k27, xxx }, \
    { k31, k32, xxx, k34, k35, k36, xxx, xxx }, \
    { k41, k42, k43, k44, k45, k46, k47, k48 }  \
}
