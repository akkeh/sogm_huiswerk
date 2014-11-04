#include <fstream>
#include <string>
#include "song.h"
#include "playable_song.h"

int main() {
	int aantal = 3;
	std::string titels[3] = {"titel 1", "titel 2", "titel 3"};

	unsigned short jaren[3] = {1800, 1994, 2010};
	Song liedjes[3];

	for (int i=0; i<3; i++) {
		liedjes[i].set_title(titels[i]);
		liedjes[i].set_year(jaren[i]);
	}
	for (int i=0; i<3; i++) {
		printf("titel: %s, jaar: %i\n", liedjes[i].get_title().c_str(), liedjes[i].get_year());		
	}
    Playable_song speel_liedje;
    speel_liedje.set_url("/home/akke/test/");
}


