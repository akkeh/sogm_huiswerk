from scipy.io.wavfile import read, write
import matplotlib.pyplot as plt
import numpy as np

import cochlear.cochlear as cr
import nerve.nerve as nv
import lin.lin as ln


def analyse(filename, M, gain, plt_x=0, plt_c=0, plt_n=0, plt_l=0):
    '''
    - filename: path to sound file (.wav)
    - M: amount of filters on cochlear 'filterbank'
    - gain: gain used in the compression in the Auditory Nerves processing
    - plt_*: plot output of said (*) stage
    '''
    x = wavread(filename)	# read input file
    x = nv.normalise(x)		# normalise input file

    if plt_x == 1:
        plt.plot(x); plt.show()

    y_c = cr.cochlea(x, M, 1000, 10000)    # cochlear analysis
    # plt_coch?
    if plt_c == 1:
        ndplt(y_c)						# 2-d plotting function

    y_n = nv.audnerves(y_c, gain)		# auditory nerves processing
    # plot aun?
    if plt_n == 1:
        ndplt(y_n)
   
    y_l = ln.lin(y_n)					# LIN processing
    # plot lin?
    if plt_l == 1:
        ndplt(y_l)     
    
    return y_l


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
'''
def wavwrite(filename, x):
    N = len(x)
    y = np.zeros(N, dtype='int16')
    for n in range(N):
        if x[n] >= 0:
            y[n] = x[n] * float(2**16 / 2 - 1)
        else:
            y[n] = x[n] * float(2**16 / 2)
    write(filename, 44100, y)
    return y(2**16 / 2 - 1)
        else:
            y[n] = x[n] / float(2**16 / 2)
    return y
'''
