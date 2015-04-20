#ifndef EVENT_H_
#define EVENT_H_

class event;
typedef event* event_ptr;

class event {
public: // door methods hier de definiëeren zijn 'inline'
    int append(event_ptr new_event) {   // 'append' event na zichzelf
        new_event->last = this;
        new_event->next = this->next;
        this->next = new_event;
        return 0;   
    }

    int print() {
        std::cout << "event: " << this->id << " timestamp: " << this->t << std::endl;
        if(this->last) std::cout << "\tlast id: " << this->last->id << std::endl;
        else std::cout << "\tno last\n";
        if(this->next) std::cout << "\tnext id: " << this->next->id << std::endl;
        else std::cout << "\tno next\n";
        return 0;
    }
    unsigned long get_time() { return this->t; };

    bool operator< (event_ptr b) {
        return this->t < b->get_time();
    }

    event(unsigned long t_t, unsigned long t_id) {    //  inline zet codeblock op caller plek
        id = t_id;
        this->t = t_t;
        this->id = t_id;
        last = next = NULL;
    }

private:
    //static unsigned long event_count;   //  int welke bij class hoort, niet instance
    unsigned long id;
    unsigned long t;    //  timestamp
    event_ptr last;
    event_ptr next;
};

class scheduler {

private:
    unsigned long event_count = 0;
    event_ptr first;

    int insert(unsigned long t) {
        event_ptr last_event = first;
        event new_event (t, event_count++);
        // zoek plek.
        unsigned long id;
        while(last_event < new_event) last_event = last_event->next;
        // insert event
        last_event->append(&event(t, event_count++));
        
    }
};


#endif
