import numpy as np
from numpy.fft import fft, ifft
import matplotlib.pyplot as plt
   
def STRFplt(x, up):
    om_res = len(x)
    OM_res = len(x[0])
    M = len(x[0][0])
    N = len(x[0][0][0])

    y = np.ndarray(shape=(om_res, OM_res), dtype='float')
    
    for om in range(om_res):
        for OM in range(OM_res):
            y[om][OM] = 0
            for m in range(M):
                y[om][OM] += np.sum(abs(x[om, OM, up, m]))

    ndplt(y)
    return y

def STRF(x, om_res, OM_res, oms = [1, 300], OMs = [0.25, 8]):
    '''
    - x: input array (2d)
    - om_res: temporal resolution
    - OM_res: spectral resolution
    - oms: temporal bounds
    - OMs: spectral bounds
    '''
    M = len(x)
    N = len(x[0])
    y = np.ndarray(shape=(om_res, OM_res, 2, M, N), dtype='complex')

    for om in range(om_res):
        print "temporal: ", om+1, "/", om_res
        omega = (oms[1]-oms[0]) / om_res * om + oms[0]
        for OM in range(OM_res):
            print "\tspectral: ", OM+1, "/", OM_res
            OMEGA = (OMs[1]-OMs[0]) / OM_res * OM + OMs[0]
            y[om, OM, 0] = STRW(x, omega, OMEGA, 0)
            y[om, OM, 1] = STRW(x, omega, OMEGA, 1)

    return y

def D2dWT(x, seeds, seedt, OM, om):
    '''
    Discrete two-dimenstional Wavelet Transform
    -   x: input signal (one-dimensional)
    -   ws: spectral wavelet
    -   wt: temporal wavelet
    '''
    N = len(x)
    ws_t = seeds(np.arange(-100, 100)/100.0, OM)
    ws = np.zeros(200)
    '''
    ws[100:] = ws_t[:100]
    ws[:100] = ws_t[100:]
    '''
    ws = ws_t
    T = int(3.0 / om * 44100)
    wt = seedt(np.arange(T)/44100.0, om)
    WS = fft(ws)
    plt.plot(WS); plt.show()
    w = np.ndarray(shape=(T, 200), dtype='complex')
    for t in range(T):
        w[t] = WS * wt[t]
    y = np.zeros(N-T) 
    for tau in range(N-T):
        y[tau] = sum(fft(x[tau:tau+200]) * w[tau])
    return y

def STRW(x, om, OM, up):
    M = len(x)
    N = len(x[0])
   
    # 2d convolution:
    y = np.ndarray(shape=(M, N), dtype='complex')
    h = get_wavelet(om, OM, up, M, N)
    
    # temporal convolution:
    for m in range(M):
        X = fft(x[m])
        H = fft(h[m])
        Z = X*H

        z = ifft(Z)
        y[m] = z

    # spectral convolution
    x = y.transpose()
    h = h.transpose()
    y = y.transpose()
    for n in range(N):
        X = fft(x[n])
        H = fft(h[n])
        Z = X*H
        
        z = ifft(Z)
        y[n] = z

    y = y.transpose()

    return y
         
def get_wavelet(om, OM, up, M, N, debug=0):
    s = (10000-1000) * np.log2(1 + np.arange(M)/float(M)) + 1000
    t = np.arange(N) / 44100.0
    
    # calc. responses:
    h = np.ndarray(shape=(N, M), dtype='complex')
    
    # spectral responses:
    if debug:
        print "spectral responses"
    for n in range(N):
        hSW = hs(s, OM)
        h[n] = hSW + 1j*hilbert(hSW)
     
    # temporal responses:
    if debug:
        print "temporal responses"
    h = h.transpose()
    for m in range(M):
        hTW  = ht(t, om)
        if up == 1:
            hTW = hTW.conjugate()
        
        h[m] *= (hTW + 1j*hilbert(hTW))
    
    return h
            

def hs(s, OM):  # spectral seed function, where:
                # - OM: spectral density
    sOM = s * OM
    y = (1 - sOM*sOM) * np.exp(-(sOM*sOM) / 2.0)
    return y * OM

def ht(t, om):  # temporal seed function, where:
                # - om: spectral velocity
    tom = t * om
    y = tom*tom * np.exp(-3.5 * tom) * np.sin(2.0 * np.pi * tom)
    return y * om

def hilbert(x):     #approximates hilbert transform
    N = len(x)
    pos = int(np.ceil(N / 2.0))
    neg = int(np.floor(N / 2.0))
    
    X = fft(x)

    h = np.zeros(N)
    h[pos:] = 2.0 / (np.pi * np.arange(-neg, 0))
    h[1:pos] = 2.0 / (np.pi * np.arange(1, pos))
    h[::2] = 0
    H = fft(h)
    
    Y = X*H
    y = ifft(Y)
    
    return y 

def ndplt(x):
    tx = np.copy(x)
    M = len(x)
    max_a = 0 
    for m in range(M):
        if max(abs(tx[m])) > max_a:
            max_a = max(abs(tx[m]))
    normf = 1.0 / max_a
    for m in range(M):
        tx[m] = tx[m] * normf + m 
    plt.plot(tx.transpose())
    plt.show()


