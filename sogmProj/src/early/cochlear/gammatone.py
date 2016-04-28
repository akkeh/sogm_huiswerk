from scipy.io.wavfile import read, write
from numpy.fft import fft, ifft
import numpy as np
import matplotlib.pyplot as plt
import math
import random as rd
import nerve as nv
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

    return h / np.sum(h)

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

def ERB(cf):
    return 24.7 + (0.108 * cf )

# 4th order:
def gammatone(cf, N, fs=44100):
    n = np.arange(N) / float(fs)	# 'time'
    b = 1.019						# (taken from Strahl, 2009)
    v = 4   						# filter-order (taken from Strahl, 2009) 
    q = 2.0 * np.pi * b * ERB(cf)	
    
    a = 1							# amplitude
    y = a*n**(v-1) * np.exp(-q * n) * np.exp(1j * 2.0*np.pi * cf * n)

    return y / np.sum(y)		    # unity gain

def g_filter(x, cf):
    Nx = len(x)

    g = gammatone(cf, Nx)

    
    X = np.fft.fft(x)
    G = np.fft.fft(g)
    Y = X*G
    
    return np.fft.ifft(Y)


def cochlea(x, M, f_low, f_hi):
    N = len(x)
    y = np.ndarray(shape=(M, N), dtype=float)
   
    f_d = np.log10(f_low)
    f_u = np.log10(f_hi) - f_d 
    for m in range(M):
        cf = 10**(f_d + (f_u * m / float(M)))
        print "[cr] m: ", m+1, "/", M, " cf: ", cf
        y[m] = (g_filter(x, cf)).real  # cut freq below cf?
        #x = x - lop(x, cf)
 
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
