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
#include <cstdlib>
#include <cmath>
#include "amp.h"
#include "del.h"
#include "play.h"

#define BUFFERSIZE 10

int main()
{
	Player player;
	Amplifier amp;
	amp.set_level(100);
  	amp.show_level();

	Delay del;
	del.set_delt(1004);
	std::cout<<del.get_delt()<<std::endl;
	long N = 44100;
	float dat[44100];
	for(long n=0; n<N; n++) {
		dat[n] = std::sin(2.0*M_PI * n * 200 / N);
	}
	float* test = amp.process(dat, N);
	for(long n=0; n<N; n++) {
		std::cout<<"sample "<<dat[n]<<" ampl: "<<test[n]<<std::endl;
	}
	del.set_delt(10000);

	float* deltest = del.process(dat, N);
	for(long n=0; n<N+del.get_delt(); n++) {
		std::cout<<deltest[n]<<std::endl;
	}

	player.play(deltest, N+del.get_delt());

} // main()

