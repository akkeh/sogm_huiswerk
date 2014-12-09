/**********************************************************************
*          Copyright (c) 2013, Hogeschool voor de Kunsten Utrecht
*                      Hilversum, the Netherlands
*                          All rights reserved
***********************************************************************
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation, either version 3 of the License, or
*  (at your option) any later version.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with this program.
*  If not, see <http://www.gnu.org/licenses/>.
***********************************************************************
*
*  File name     : guitarfx.cpp
*  System name   : guitarfx
* 
*  Description   : main file for guitarfx
*
*  Author        : Marc_G
*  E-mail        : marcg@dinkum.nl
*
**********************************************************************/

#include <iostream>
#include "play.h"
#include <alsa/asoundlib.h>
#define BUFFERSIZE 10

void Player::play(float* data, long N) {
	long len = buf_size;
	while (len < N) {
		len+=buf_size;
	}
	float* dat = new float[len];
	for(long n=0; n<N; n++) {
		dat[n] = data[n];
	}
	for(long n=N; n<len; n++) {
		dat[n] = 0;
	}
	unsigned short* out_data = new unsigned short[buf_size];
	long read_p = 0;
	while(read_p < len) {
		for(long n=0; n<buf_size; n++) {
			out_data[n] = (unsigned short)(dat[n+read_p] + 1) * 255;
		}
		read_p+=buf_size;
		int pcmreturn;
		while((pcmreturn = snd_pcm_writei(pcm_handle, out_data, buf_size/2)) < 0) {
        	snd_pcm_prepare(pcm_handle);
        	printf("buffer underrun!");
        }
	}
	
}


Player::Player() {

    snd_pcm_stream_t stream = SND_PCM_STREAM_PLAYBACK;   //set pcm to playback

    snd_pcm_hw_params_t *hwparams;  //hardware params

    sel_crd:
    char *pcm_name;     //name of sndcard;
    std::string t_name;
    std::cout<<"\nselect card:\n";
    std::string dev_nr;
    std::cin>>dev_nr;
    t_name = "plughw:"+dev_nr+",0";

    pcm_name = strdup(t_name.c_str());    //set sndcard namespace

    snd_pcm_hw_params_alloca(&hwparams);    //allocate hw params on stack

    int err;

    if((err = snd_pcm_open(&pcm_handle, pcm_name, stream, 0)) < 0) {
        printf("Error opening %s: %s\n", pcm_name, snd_strerror(err));

        goto sel_crd;
    }

    if (snd_pcm_hw_params_any(pcm_handle, hwparams) < 0) {
        printf("can not configure: %s\n", t_name.c_str());
        goto sel_crd;
    }

    //define samplerate; now: 44100kHz, 16bit Little edian
    unsigned int rate = 44100;
    unsigned int exact_rate;
    int dir;
    int periods = 2;
    snd_pcm_uframes_t periodsize = 8192;

    //set configuration
    //set interleaved
    if(snd_pcm_hw_params_set_access(pcm_handle, hwparams, SND_PCM_ACCESS_RW_INTERLEAVED) < 0) {
        printf("Error setting interleaved: %s\n", t_name.c_str());
        goto sel_crd;
    }

    //set samplerate
    if(snd_pcm_hw_params_set_format(pcm_handle, hwparams, SND_PCM_FORMAT_S16_LE) < 0) {
        printf("Error setting sample format: %s\n", t_name.c_str());
        goto sel_crd;
    }

    //set sample rate
    exact_rate = rate;
    if(snd_pcm_hw_params_set_rate_near(pcm_handle, hwparams, &exact_rate, 0) < 0) {
        printf("Error setting sample rate: %s\n", t_name.c_str());
        goto sel_crd;
    }
    if(rate != exact_rate) {
        printf("rate %i not supported. \n using %i instead", rate, exact_rate);
    }

    //set nr of channels
    if(snd_pcm_hw_params_set_channels(pcm_handle, hwparams, 2) < 0) {
        printf("error setting channels");
        goto sel_crd;
    }

    //set nr of periods
    if(snd_pcm_hw_params_set_periods(pcm_handle, hwparams, periods, 0) < 0) {
        printf("error setting periods");
        goto sel_crd;
    }

    //set buffer size:
    if(snd_pcm_hw_params_set_buffer_size(pcm_handle, hwparams, (periodsize * periods)>>2) < 0) {
        printf("Error setting buffersize\n");
        goto sel_crd;
    }

    //apply configuration:
    if((err = snd_pcm_hw_params(pcm_handle, hwparams)) < 0 ) {
        printf("Error applying configuration on device: %s", snd_strerror(err));
        goto sel_crd;
    }
	buf_size = periodsize;
	
};

