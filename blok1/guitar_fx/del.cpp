/**********************************************************************
*          Copyright (c) 2013, Hogeschool voor de Kunsten Utrecht
*                      Hilversum, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : guitarfx.cpp
*  System name   : guitarfx
* 
*  Description   : main file for guitarfx
*
*  Author        : Marc_G
*  E-mail        : marcg@dinkum.nl
*
**********************************************************************/

#include <iostream>
#include "del.h"

Delay::Delay()
{
	delt = 1; // default
}

void Delay::set_delt(long new_delt) {
	delt = new_delt;
}

long Delay::get_delt() {
	return delt;
}

float* Delay::process(float* data, long N) {

	float* output = new float[N+delt];
	for(long n=0; n<delt; n++) {
		output[n] = 0;
	}
	for(long n=0; n<N; n++) {
		output[delt+n] = data[n];
	}

	return output;
}
