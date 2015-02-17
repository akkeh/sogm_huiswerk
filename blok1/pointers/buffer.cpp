#include <iostream>
#include <cmath>


#define BUFSIZE 10

void process(float *buffer) {               // verwacht een pointer 
                                            // (geheugen adres)
    for(int i=0; i<BUFSIZE; i++) {
        *(buffer + i) = float(int(rand() % 100)/100);
        std::cout << *(buffer+i) << std::endl;  //  incrementeerd met byte 
                                                //      afstand van float
    }

}   //process()

int main() {
    float* buffer;
    buffer  = new float[BUFSIZE];
    process(buffer);                        //  address wordt doorgegeven
    return 0;
}   //main()
