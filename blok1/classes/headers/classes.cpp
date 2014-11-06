#include <fstream>
#include <string>

class Song {
// INTERFACE VAN CLASS:
private:
	std::string title;
	unsinged short year;
public:
	void set_title(std::string t_title);
	int set_year(unsinged short t_year);
	std::string get_title();
	unsigned short get_year();
};


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



