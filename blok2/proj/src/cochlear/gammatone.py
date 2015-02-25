import numpy as np
import matplotlib.pyplot as plt
import math
import random as rd

def ERB(cf):
    return 24.7 + (0.108 * cf )

# 4th order:
def gammatone(cf, N, fs=44100):
    n = np.arange(N) / float(fs)
    b = 1.019
    v = 4   # order
    q = 2.0 * np.pi * b * ERB(cf)
    
    a = 1
    y = a*n**(v-1) * np.exp(-q * n) * np.exp(1j * 2.0*np.pi * cf * n)
    y_max = max(abs(y))
    for n in range(N):
        y[n] *= 1.0 / y_max
    return y

def g_filter(x, cf):
    Nx = len(x)

    g = gammatone(cf, Nx)
    Ng = len(g)

    X = np.fft.fft(x)
    G = np.fft.fft(g)
    Y = X*G
    
    return np.fft.ifft(Y)


def filter_bank(x, M, f_low, f_hi):
    N = len(x)
    y = np.ndarray(shape=(M, N), dtype=float)
   
    f_d = np.log10(f_low)
    f_u = np.log10(f_hi) - f_d 
    for m in range(M):
        cf = 10**(f_d + (f_u * m / float(M)))
        print "m: ", m, " cf: ", cf
        y[m] = g_filter(x, cf)
 
    return y

def plot_auditory_spec(x, M, f_low, f_hi):
    y = filter_bank(x, M, f_low, f_hi)
    
    max_amp = 0
    for m in range(M):
        if max(abs(y[m])) > max_amp:
            max_amp = max(abs(y[m]))
    
    for m in range(M):
        y[m] = y[m] + max_amp*m
    plt.plot(y.transpose())
  
    plt.show()


def noise(N):
    y = np.zeros(N)
    for n in range(N):
        y[n] = rd.random()
    return y

def test(f, N, fs=44100):
    n = np.arange(N) / float(fs)
    x = np.sin(2.0*np.pi * f * n)
    return x
    

def u(N, n0, n1):
    y = np.zeros(N)
    
    for n in range(n1-n0):
        y[n+n0] = 1
    return y
