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

class Playable_song : public Song {
public:
    void set_url(std::string url);
    void play();
private:
    std::string url;
};

class Notated_song : public Song {
public:
    void set_url
