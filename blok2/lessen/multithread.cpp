#include <iostream>
#include <pthread.h>    // threads
#include <cstdlib>
#include <unistd.h>     // sleep

typedef struct th_arg {
    int id;
    int sleep_time;
};

void* first(void* arg) {
    int id = (*(th_arg*)arg).id;
    int sleep_time = (*(th_arg*)arg).sleep_time;
    for(int i=0; i<10; i++) {
        std::cout << "thread " << id << " time: " << i << std::endl;
        sleep(sleep_time);
    }
    pthread_exit((void*)0);
}


int main() {
    pthread_t thr[10];
    th_arg args[10];
    for(int i=0; i<2; i++) {
        args[i].sleep_time = std::rand() % 10 + 1;
        args[i].id = i + 1;
        if(pthread_create(&thr[i], NULL, first, (void*)&args[i]) != 0) {
            std::cout << "\nerror creating thread!\n";
        }   
    }

    pthread_exit((void*)0);     // wacht tot andere threads zijn afgelopen
                                //  door main-thread netjes wordt afgesloten
                                //  als thread van het programma
}
