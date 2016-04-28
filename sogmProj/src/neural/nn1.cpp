#include <iostream>
#include <cmath>

class neuron {
/*
    a_t = -decay * (a_t - rest) + (max - a_t)*f_E(E) - (a_t - min)f_I(I) (nn.pdf blz.12)
        f_* = y
        y = f(sum( x_i * w_i - bias) )
*/
    double a_t(
    double sigmoid(double x) {
        return 1.0 / (1 + std::exp(-x));
    }
    
};



int main(int argc, char** argv) {

}
