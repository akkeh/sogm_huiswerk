#include <iostream>
#include "scheduler.h"

int main() {
    unsigned long t1 = 4100;
    unsigned long t2 = 22050;
    unsigned long t3 = 22051;
    event event1(t1);
    event event2(t2);
    event event3(t3);

    event1.append(&event2);
    event2.append(&event3);        

    event1.print();
    event2.print();
    event3.print();
}

