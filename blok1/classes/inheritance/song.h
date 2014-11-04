#ifndef _SONG_H_    //als _SONG_H_ niet is gedefinieerd, voer het navolgende uit
#define _SONG_H_    // definieer _SONG_H_ 
                    //  (volgende keer komt 'false' uit #ifndef _SONG_H_)

// #pragma once //zorgt dat deze maar een keer per .cpp programma geladen wordt NIET STANDAARD C++ ANSI

#include <string>

class Song {
public: // inferface van class:
	void set_title(std::string t_title);
	int set_year(unsigned short t_year);
	std::string get_title();
	unsigned short get_year();

private:
	std::string title;
	unsigned short year;
};

#endif          // einde van #ifndef _SONG_H_
