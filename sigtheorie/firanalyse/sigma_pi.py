import numpy as np

def sigma(a, b, operation):
    y = 0
    for n in range(b-a):
        y += operation(n + a)
    return y

def c_pi(a, b, operation):
    y = 1
    for n in range(b-a):
        y *= operation(n + a)
    return y
    
