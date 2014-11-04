#include "playable_song.h"
#include <fstream>


void Playable_song::set_url(std::string url) {
    printf("url: %s\n", url.c_str());
    this->url = url;    //'this.url' = url variabele uit class
                        // 'url' = url argument van functie
    
};
void Playable_song::play(long dur) {
    printf("play %lims\n", dur);
};
void Playable_song::play(){
    printf("play all\n");
};

void Playable_song::add_notation(Notation notation) {
    this->notation = notation;
}

