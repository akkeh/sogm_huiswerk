#include <iostream>
#include <cmath>

#define fs 44100
#define BUFSIZE 10

void process(long *sample) {            //pointer komt binnen
    *sample+=2;              //  * zorgt dat het over de inhoud gaat
}   //process()

int main() {
    long sample=42;
    std::cout << "sample: " << sample << std::endl;

    process(&sample);               //  door & wijst het naar het adress!!

    std::cout << "sample: " << sample << std::endl;
    return 0;
}   //main()
