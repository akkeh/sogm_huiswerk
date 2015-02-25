import numpy as np
import matplotlib.pyplot as plt
import math
from scipy import fft, ifft



def g(x, gain):
    return 1.0 / (1 + np.exp(-gain * x)) - 0.5


last_x = 0

def diff(x):
    last_x = 0 

    N = len(x)
    y = np.zeros(N)    
    for n in range(N):
        y[n] = x[n] - last_x
        last_x = x[n]
    return y

def normalise(x):
    N = len(x)
    max_val = max(abs(x))

    y = np.zeros(N)
    for n in range(N):
        y[n] = x[n] * 1.0/max_val
    return y

def blackman(N):
    w = np.zeros(N)

    a0 = 7938 / 18608.0
    a1 = 9240 / 18608.0
    a2 = 1430 / 18608.0
    for n in range(N):
        w[n] = a0 - a1*np.cos(2.0*np.pi * n / (N-1)) + a2*np.cos(4.0*np.pi * n / (N-1))
    return w

def sinc_f(cf, N):
    h = np.zeros(N)

    for n in np.arange(N):
        t = (n - N/2)  / 44100.0
        h[n] = (np.sin(2.0*np.pi * cf * t) / (2.0*np.pi * cf * t))

    h[N/2 ] = 1 

    w = blackman(N)

    h = w * h

    '''
    thanks to: 
    http://tomroelandts.com/articles/how-to-create-a-simple-low-pass-filter
    unity gain is implemented:
    '''
    return h / np.sum(h) #normalise(h * w)

def lop(x, cf):
    Nx = len(x)

    w = sinc_f(cf, Nx)
    ''' 
    test_K = 10 
    y = np.zeros(Nx + test_K + 1)
    for n in range(Nx):
        for k in range(test_K):
            y[n+k] += x[n] * w[k]
    '''
    X = fft(x)
    W = fft(w)
    Y = X*W

    y = ifft(Y)
     
    return y


def saw(f, N, K):
    y = np.zeros(N)

    for k in range(K):
        for n in range(N):
            y[n] += np.sin(2.0*np.pi * n * (f * (k+1)) / 44100.0) * 1.0 / (k+1)
    
    return y
