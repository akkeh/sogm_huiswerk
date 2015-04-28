#include <iostream>
#include "scheduler.h"

int main() {
    unsigned long t1 = 4100;
    unsigned long t2 = 22050;
    unsigned long t3 = 22051;

    scheduler sced;
    event newev(t1);
    sced.add(&newev);
    
    event ev2(t2);
    event ev3(t3);

    sced.add(&ev2);
    sced.add(&ev3);
}

