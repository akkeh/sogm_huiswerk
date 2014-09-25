#include <iostream>
#include <cmath>
#include <fstream>

/*	programma dat 1 periode van een sinus met f=480Hz
||	bij fs = 48000Hz
||	schrijf elke sample weg in .txt file
||		in cmd-line: sinus > output.txt
*/
//#define pi 22/7
float pi = M_PI;

int main() {
	float freq = 480;
	float samplerate = 48000;
	for(int i=0; i<100; i++) {
		float sample = std::sin(2*pi*((i*freq)/samplerate));
		if(i>500) break;
		std::cout<<i<<"\t"<<sample<<std::endl; 
	}
}
