#include <iostream>

#include "axiom.h"


// class memsl ----------|
mem::mem(unsigned long memN) {
    N = memN;
    time = new unsigned long[N];
    val = new double[N];
    for(unsigned long n=0; n<N; n++) {
        time[n] = 0;
        val[n] = 0;
    }
    wrptr = 0;
}

bool mem::exist(unsigned long timestamp) {
    rdptr = wrptr - 1;
    while(rdptr != wrptr) {
        if(time[rdptr] == timestamp) return 1;
        if(rdptr == 0) rdptr = N;
        else rdptr--;
        
    }
    rdptr = 0;
    return 0;
}

double mem::get(unsigned long timestamp) {
    if(time[rdptr] == timestamp) return val[rdptr];
    for(unsigned long n=0; n<N; n++) {
        if(time[n] == timestamp) return val[n];
    }
    // is function gets here timestamp is not yet calculated, so an error must be returned
    return -9999;
}

void mem::add(unsigned long timestamp, double new_val) {
    time[wrptr] = timestamp;
    val[wrptr] = new_val;
    wrptr = (wrptr + 1) % N;
}

// -----------------------|

// class neuron ----------|
neuron::neuron() {
    con = 0;
    membuf = new mem(10);
} //neuron();

void neuron::add_inp(neuron* t_inp, double t_w, double t_bias) {
    inp.push_back(t_inp);
    w.push_back(t_w);
    bias.push_back(t_bias);
    con++;
} //neuron::add_inp();

double neuron::evaluate(unsigned long timestamp) { 
    /*
        evaluation of neuron
            1: check if output of timestamp already exists
            2:   returns output of neuron:
                y = f( sum(x_i * w_i - bias_i ) );
            (3:   stores output in memory (timestamp))
    */
    double y = 0;
    if(!membuf->exist(timestamp)) {  // output already calculated?
        double x;
        for(unsigned long i=0; i<con; i++) {
            x = inp[i]->evaluate(timestamp);
            y += x * w[i] - bias[i];    // OPT: cache aware??
        }
        y = f(y);
        membuf->add(timestamp, y); // add output to memory
    } else y = membuf->get(timestamp);      // get output from memory
    return y; 
} //neuron::evaluate()

double neuron::f(double x) {
    double y;
    y = 1 + std::exp(-x);
    return 1/y;
};// neuron::f();

// -----------------------|



int main() {
}
