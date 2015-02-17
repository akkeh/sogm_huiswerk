
#ifndef _PLAY_H_
#define _PLAY_H_
#include <iostream>
#include <alsa/asoundlib.h>
class Player
{
public:
	Player();
	void play(float* data, long N);
private:
	long buf_size;
	snd_pcm_t *pcm_handle;
};

#endif
