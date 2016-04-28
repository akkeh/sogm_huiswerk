

def DWT(x, wavelet, N, M, dt, ds):
    y = np.ndarray(type=(m, n),     
 
    TAU = int(N / dn)
    for s in range(M):
        for tau in range(TAU): 
        # dilate & shift wavelet:
        psi = wavelet(tau * dt, s, N)
    
        # convolve wavelet and signal:
        PSI = fft(psi)
        X = fft(x)
        Y = X * PSI
        y[s][tau] = ifft(Y)      
    
