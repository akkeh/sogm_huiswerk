import numpy as np
import matplotlib.pyplot as plt
import math
from scipy import fft, ifft

def audnerves(x, gain):
    '''
    Auditory Nerve processing
    '''
    M = len(x)
    N = len(x[0])
    y = np.ndarray(shape=(M, N), dtype='float')

    for m in range(M):
        y_hip = hip(x[m])
        y_g = g(y_hip, gain)   
        y_lop = smooth(y_g, 0.08, wu)
        y[m] = y_lop
        print "[nv]:", m+1, "/", M
    return y

def hip(x, fs=44100.0):
    '''
    First order differentiator
    '''
    N = len(x)
    y = np.zeros(N)
    last = 0
    for n in range(N):
        y[n] = x[n] - last
        last = x[n]
    return y

def g(x, gain):
    '''
    non-linear compression
    - x: input signal
    - gain: compression gain
    '''
    N = len(x)
    y = np.zeros(N)
    y = 1.0 / (1 + np.exp(-gain * x)) - 0.5
    return y

def normalise(x):
    max_val = max(abs(x))
    y = x / max_val
    return y

def blackman(N):
    w = np.zeros(N)

    a0 = 7938 / 18608.0
    a1 = 9240 / 18608.0
    a2 = 1430 / 18608.0
    for n in range(N):
        w[n] = a0 - a1*np.cos(2.0*np.pi * n / (N-1)) + a2*np.cos(4.0*np.pi * n / (N-1))
    return w

def smooth(x, time, winf):
    '''
    Temporal smoothing
    - x: input signal
    - time: length of window in seconds
    - winf: windowing function
    '''
    K = int(44100 * time)
    N = len(x)

    h = winf(N, 0, K)
    X = fft(x)
    H = fft(h)
    Y = H*X
    y = ifft(Y)

    return y


def u(N, n0, n1):
    y = np.zeros(N)
    
    for n in range(n1-n0):
        y[n+n0] = 1
    return y

def wu(N, n0, n1):
    y = u(N, n0, n1)
    K = n1-n0
    w = blackman(K)
    y[n0:n1] = w
    return y

