#include "midievent.h"
#include <iostream>

int main() {
    midi_event* eventqueue[10]; // eq: midi_event** eventqueue;
    
    midi_event me;
    me.set_timestamp(100);
    std::cout<<"me timestamp: "<<me.get_timestamp()<<std::endl;

    note_event ne;
    ne.set_timestamp(200);
    std::cout<<"ne timestamp: "<<ne.get_timestamp()<<std::endl;
   
    midi_event* me_ptr;
    note_event* ne_ptr;
/* 
    me_ptr = &me;
    (*me_ptr).set_timestamp(10);    // eq: me_ptr->set_timestamp(10);
 
    std::cout<<"me timestamp: "<<me.get_timestamp()<<std::endl;
*/
     
    me_ptr = new midi_event;
    //ne_ptr = new note_event;
        
    eventqueue[0] = new midi_event;
    eventqueue[1] = new note_event;
    // (*eventqueue[1]).set_note(60);   ken-niet...
    /* maar kan op de volgende wijze:
    ne_ptr = new note_event;
    (*ne_ptr).set_note(60);
    eventqueue[1] = ne_ptr;
    */
    // of via een typecast:
    (*(note_event*)eventqueue[1]).set_note(60);
    eventqueue[2] = new midi_event;
    eventqueue[3] = new midi_event;
    eventqueue[4] = new midi_event;
    eventqueue[5] = new note_event;
    (*(note_event*)eventqueue[5]).set_note(60);
    eventqueue[6] = new midi_event;
    eventqueue[7] = new midi_event;
    eventqueue[8] = new note_event;
    (*(note_event*)eventqueue[8]).set_note(60);
    eventqueue[9] = new midi_event;
    
    for(int i=0; i<10; i++) {
        (*eventqueue[i]).set_timestamp(i*10);
        std::cout<<"timestamp: "<<i<<" "<<(*eventqueue[i]).get_timestamp()<<std::endl;
    }
    for(int i=0; i<10; i++) {
        (*eventqueue[i]).play();
    }
    //delete:
    for(int i=0; i<10; i++) {
        delete eventqueue[i];
    }
    return 0;
}
