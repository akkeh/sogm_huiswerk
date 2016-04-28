import numpy as np
from numpy.fft import fft as fft
from numpy.fft import ifft as ifft

import scipy as sp
from scipy.io.wavfile import read, write
import matplotlib.pyplot as plt
import random as rd
import math

def normalise(x):
	return x / max(abs(x))

def wavread(filename):
    fs, x = read(filename)
    N = len(x)
    y = np.zeros(N, dtype='float')
    for n in range(N):
        if x[n] >= 0:
            y[n] =  x[n] / float(2**16 / 2 - 1)
        else:
            y[n] = x[n] / float(2**16 / 2)
    return y

def wavwrite(filename, x):
    N = len(x)
    y = np.zeros(N, dtype='int16')
    for n in range(N):
        if x[n] >= 0:
            y[n] = x[n] * float(2**16 / 2 - 1)
        else:
            y[n] = x[n] * float(2**16 / 2)
    write(filename, 44100, y)
    return y

#wavwrite('kraak_hoog.wav', normalise(np.convolve(grain(x, 44100*2, 2, 20), filterbankN(clip(x*10, -1, 1), 400, 0.1, 5))))

#wavwrite('kraak2_tail3.wav', normalise(np.convolve(extend(speed(x, 0.8), 2), x)))  
