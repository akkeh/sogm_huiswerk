#include "song.h"

void Song::set_title(std::string t_title) {
	title = t_title;
}
	
int Song::set_year(unsigned short t_year) {
	if(t_year < 1990) return -1;		
	year = t_year;
	return 0;
}

std::string Song::get_title() {
	return title;
}
unsigned short Song::get_year() {
	return year;
}
