#ifndef EVENT_H_
#define EVENT_H_

#include <cstdlib>

class event;
typedef event* event_ptr;

class event {

private:
    static unsigned long event_count;   //  int welke bij class hoort, niet instance
    unsigned long id;
    unsigned long t;    //  timestamp
    event_ptr prev;
    event_ptr next;


public: // door methods hier de definiëeren zijn 'inline'

    int add(event_ptr new_event, int rev) {
        /*
            adds new_event to linked list
            -   rev: 0 normal; 1 reversed
        */
        if(rev == 0) {  // normal
            if(new_event > this) {
                if(next) next->add(new_event, rev);
                else return -1; // should not happen
            } else prepend(new_event);
        } else {    // reversed
            if(new_event < this) {
                if(prev) prev->add(new_event, rev);
                else return -1; // should not happen

            } else append(new_event);
        }
        return 0;
    }

    int prepend(event_ptr new_event) {  // 'prepend' event
        new_event->prev = this->prev;
        new_event->next = this;
        this->next = new_event;
        return 0;
    }

    int append(event_ptr new_event) {   // 'append' event na zichzelf
        new_event->prev = this;
        new_event->next = this->next;
        this->next = new_event;
        return 0;   
    }


    int print() {
        std::cout << "event: " << this->id << " timestamp: " << this->t << std::endl;
        if(this->prev) std::cout << "\tprev id: " << this->prev->id << std::endl;
        else std::cout << "\tno prev\n";
        if(this->next) std::cout << "\tnext id: " << this->next->id << std::endl;
        else std::cout << "\tno next\n";
        return 0;
    }
    unsigned long get_time() { return this->t; };

    bool operator< (event_ptr b) {
        return this->t < b->get_time();
    }
    
    bool operator> (event_ptr b) {
        return this->t > b->get_time();
    }

    event(unsigned long t_t) {    //  inline zet codeblock op caller plek
        id = event_count++;
        this->t = t_t;
        prev = next = NULL;
    }
    ~event() {
        if(next) next->prev = NULL;
    }       

};  // event

class scheduler {
public:
    void add(event_ptr new_event);
    scheduler();
private:
    unsigned long event_count;
    event_ptr first;
    event_ptr last;
    event_ptr prev; // previously added event
    unsigned long t0, tN;

};  // scheduler


#endif
