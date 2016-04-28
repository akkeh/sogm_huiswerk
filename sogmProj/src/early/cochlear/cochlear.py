# includes:
from scipy.io.wavfile import read, write
from numpy.fft import fft, ifft
import numpy as np
import matplotlib.pyplot as plt
import math
import random as rd
import nerve as nv
# --------:

def blackman(N):
    '''
    Calculate blackman window
    - N: length of window
    '''
    w = np.zeros(N)

    a0 = 7938 / 18608.0
    a1 = 9240 / 18608.0
    a2 = 1430 / 18608.0
    for n in range(N):
        w[n] = a0 - a1*np.cos(2.0*np.pi * n / (N-1)) + a2*np.cos(4.0*np.pi * n / (N-1))
    return w    # blackman()

def ERB(cf):
    '''
    Calculate ERB
    - cf: center frequency
    '''
    return 24.7 + (0.108 * cf )

def gammatone(cf, N, fs=44100):
    '''
    Calclulate gammatone impulse response
    - cf: center frequency
    - N: length of impulse response
    - fs: samplerate
    '''
    n = np.arange(N) / float(fs)	# 'time'
    b = 1.019						# (taken from Strahl, 2009)
    v = 4   						# filter-order (taken from Strahl, 2009) 
    q = 2.0 * np.pi * b * ERB(cf)	
    
    a = 1							# amplitude
    y = a*n**(v-1) * np.exp(-q * n) * np.exp(1j * 2.0*np.pi * cf * n)
    y = y / np.sum(y)    		    # unity gain
    return y    # gammatone()

def g_filter(x, cf):
    '''
    Perform gammatone filter
    - x: input signal
    - cf: centerfrequency
    '''
    N = len(x)				# length of input

    g = gammatone(cf, N)	# get impulse response

    
    X = fft(x)
    G = fft(g)
    Y = X*G					# convolve

    y = ifft(Y)

    return y

def cochlea(x, M, f_low, f_hi):
    '''
    Perform cochlear filterbank
    - x: input signal
    - M: amount of frequency bands
    - f_low: lower frequency
    - f_up: upper frequency
    '''
    N = len(x)
    y = np.ndarray(shape=(M, N), dtype=float)
   
    for m in range(M):
        cf = float(f_hi - f_low) / M * np.log10(m+1) + f_low	# calulate center frequency
        print "[cr] m: ", m+1, "/", M, " cf: ", cf
        y[m] = (g_filter(x, cf)).real

    return y
