#include <iostream>
#include <pthread.h>    // threads
#include <cstdlib>
#include <unistd.h>     // sleep
// mutex

pthread_mutex_t testmutex = PTHREAD_MUTEX_INITIALIZER;  // mutex

typedef struct th_arg {
    int id;
    int sleep_time;
};

void* first(void* arg) {
    int id = (*(th_arg*)arg).id;
    int sleep_time = (*(th_arg*)arg).sleep_time;
    for(int i=0; i<10; i++) {
        pthread_mutex_lock(&testmutex);     // testmutex gets locked
            std::cout << "thread " << id << " time: " << i << std::endl;
        pthread_mutex_unlock(&testmutex);   // testmutex gets unlocked
        sleep(sleep_time);
    }
    pthread_exit((void*)0);
}


int main() {
    pthread_t thr[10];
    th_arg args[10];
    for(int i=0; i<10; i++) {
        args[i].sleep_time = std::rand() % 10 + 1;
        args[i].id = i;
        if(pthread_create(&thr[i], NULL, first, (void*)&args[i]) != 0) {
            std::cout << "\nerror creating thread!\n";
        }   
    }

    pthread_exit((void*)0);     // wacht tot andere threads zijn afgelopen
                                //  door main-thread netjes wordt afgesloten
                                //  als thread van het programma
}
