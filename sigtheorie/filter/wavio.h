#include <string.h>
#include <fstream>
#include <iostream>
#include <cmath>

#define FS 44100

/*
||  functions to read/write .wav files
||      read(const char* filename, int print = 0)
            read a *.wav file and put data in struct sig file
            return: struct sig
||      write(const char* filename, sig const& in_data, unsigned short bps = 16, int print = 0)
            writes data from struct sig to .wav file
            return: int

||  TO DO:
        -   multi-channel
||
*/
class wavio{
public:
    int read(const char* filename, int print); 
    int write(const char* filename, unsigned short bps, int print);

    double* data;
    unsigned long N;
};
