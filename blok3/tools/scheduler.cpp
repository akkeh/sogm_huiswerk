#include <iostream>
#include "scheduler.h"

unsigned long event::event_count = 0; //als event_count onderdeel is een class, declare met deze 

scheduler::scheduler() {
    first = last = NULL;
    event_count = 0;
    t0 = tN = 0;
}   // scheduler

void scheduler::add(event_ptr new_event) {
    if(!first) {    // queue empty?
        first = new_event;
        t0 = first->get_time();
    } else if(!last) { // no last 
        first->append(new_event);
        last = new_event;
        tN = last->get_time();
    } else {    // queue > 2 events
        // must new_event be first or last?:
        if(new_event < first) { // set new_event to be first
            new_event->append(first);
            first = new_event;
            t0 = first->get_time();
        } else if(new_event > last ) { // set new_event to be last
            last->append(new_event);
            last = new_event;
            tN = last->get_time();
        } else {    // run trough list and insert new_event at appropriate place
            unsigned long t1, t2;
            long t3;
            t1 = new_event->get_time() - t0;    //  dist. to first;
            t2 = tN - new_event->get_time();    //  dist. to last;
            t3 = new_event->get_time() - prev->get_time(); //  dist. to prev. added event

            // signed unsigned probleem!


            if((t1 < t2) && (t1 < (unsigned)abs(t3))) {
                // start from first
                first->add(new_event, 0);
            } else if(t2 < (unsigned)abs(t3)) {
                // start from lasta
                last->add(new_event, 1);
            } else {
                // start from prev.
                if(t3 >= 0) prev->add(new_event, 0);
                else prev->add(new_event, 1);
            }
        }
    }
    prev = new_event;
    event_count++;
}   // scheduler::add
