import numpy as np
import math
from numpy.fft import fft, ifft

def lin(x):
    '''
    Lateral Inhibitory Network
    '''
    y_der = dM(x)
    print "dy/dM done"
    y_hwr = hw_rect(y_der)
    print "half-wave rectifier done"
    return y_der

def dM(x):
    '''
    First order derivative with respect to tonotopic axis
    '''
    M = len(x)
    N = len(x[0])

    y = np.ndarray(shape=(M, N), dtype='float')
    y[0] = np.zeros(N)
     
    print "[ln] dy/dM: ", 1, "/", M
    for m in np.arange(M - 1) + 1:
        print "[ln] dy/dM: ", m+1, "/", M
        for n in range(N):
            y[m][n] = (x[m][n] - x[m-1][n])/2
    return y

def hw_rect(x):
    '''
    Half-wave rectifier
    '''
    M = len(x)
    N = len(x[0])
    y = np.copy(x)
        
    for m in range(M):
        print "[ln] half-wave rectifier: ", m+1, "/", M
        for n in range(N):
            y[m][n] = x[m][n] * (x[m][n] > 0)
    return y

