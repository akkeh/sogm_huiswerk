import numpy as np
import matplotlib.pyplot as plt

def morlet(a, sig, N):
    n = (np.arange(int(N))-N)/N * np.pi   
    w = np.exp(1j*a*n) * np.exp(-(n**2)/(2.0*sig))
    return w

def DWT(x,w_funct, a, s, N):
    N = len(x)
    w = w_funct(a, s, N)
    Nw = len(w)
    y = np.zeros(N+Nw)
    for n0 in np.arange(N):
        if n0-Nw/2.0 > 0:
            k = 0
        else:
            k = abs(n0-Nw/2.0)
        for n in range(int(Nw-k)):
           print Nw, k, n0, len(y), len(x), len(w), n
           y[n0] += x[n+n0]*w[n+k] 
        
    return y

def gammatone(cf, phi, a, n, b, N):
    t = (np.arange(N) - N/2.0) / N
    g = (a*t**(n-1) * np.cos(2.0*np.pi * cf * t + phi)) / np.exp(2.0*np.pi * b * t)
    return g

'''
def gammatone(f, phs, a, order, b, N):
    n = (np.arange(N) - N/2.0)/N
    g = a*n**(order-1) * np.exp(-2.0*np.pi * b * n) * np.cos( 2.0*np.pi * f * n + phs);
    return g
'''
