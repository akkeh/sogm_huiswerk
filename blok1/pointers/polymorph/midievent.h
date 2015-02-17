#include <iostream>

class midi_event {
public:
    midi_event() {};
    void set_timestamp(long int ts) {timestamp = ts;};   //  setter
    long int get_timestamp() {return timestamp;};        //  getter
    // virtual maakt dat de functie in child classes aangepast kan worden
    virtual void play() { std::cout<<"now: "<<timestamp<<std::endl;};   
    virtual void play() = 0;    // als er een virual void functie is die '0' is
                                //  kan er GEEN object van de main 
                                //  class gemaakt worden

private:
    long int timestamp;
};

class note_event : public midi_event {
public:
    note_event() {};
    void set_note(unsigned char p) { note_nr = p; };
    void play() {
        midi_event::play();     //use play funct. van main class
        std::cout<<"playing note: "<<(int)note_nr<<std::endl;
    };
private:
    bool on_off;
    unsigned char note_nr;  // bytes zonder teken
};
