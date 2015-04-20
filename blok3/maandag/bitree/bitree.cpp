#include <iostream>
#include <cstdlib>
#include "bitree.h"


// class note --------------------------|a
note::note(unsigned long t_timestamp, int t_notenr) {
    timestamp = t_timestamp;
    notenr = t_notenr;
}
unsigned long note::get_time() {
    return this->timestamp;
}

void note::print() {
    std::cout << "time: " << timestamp << " note: " << notenr << std::endl;
}
// -------------------------------------|

// class node --------------------------|
node::node(note* new_cont) {
    cont = new_cont;
    left = NULL;
    right = NULL;
}

void node::insert(note* new_note) {
    if( *new_note > *cont) {
        if(right) right->insert(new_note);
        else {
            right = new node(new_note);
        }
    } else if( *new_note < *cont) {
        if(left) left->insert(new_note);
        else left = new node(new_note);
    } else {
        std::cout << "double timestamp not supported yet!\n";
    }
}

void node::print() {
    if(left) left->print();
    cont->print();
    if(right) right->print();
}
// -------------------------------------|





int main() {
    note note1(10, 60);
    node noot1(&note1);
    note note2(1000, 10);
    noot1.insert(&note2);
    for(int i=0; i<10; i++) {
        noot1.insert(new note(rand() % 10000, rand() % 128));
    }
    noot1.print();
}
