
#ifndef _PLAY_H_
#define _PLAY_H_
#include <iostream>

#include <alsa/asoundlib.h>
class Player
{
public:
	Player();
    int process(int order, float* coeff);
	void play(float* data, long N);
    void play_file(int order, float* coeff);
    int load_file();
    int read(const char* filename, int print=0);
    int write_file();
    int write(const char* filename, float* data, unsigned long N, unsigned short bps=16, int print=0);
    float* samples;
    unsigned long N;
private:
	long buf_size;
	snd_pcm_t *pcm_handle;
};

#endif
