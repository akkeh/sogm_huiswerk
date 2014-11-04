#include "song.h"

typedef std::string Notation;

class Playable_song : public Song {
public:
    void set_url(std::string url);
    void play(long dur);
    void play();
    void add_notation(std::string notation);
private:
    std::string url;
    Notation notation;
};
