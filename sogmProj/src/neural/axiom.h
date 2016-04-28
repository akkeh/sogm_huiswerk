#ifndef AXIOM_H_
#define AXIOM_H_

#include <vector>


// complex -------|
typedef struct {
    double r;
    double i;
} cmplx;
// ---------------|

// signal --------|
typedef struct {
    cmplx* data;
    unsigned long N;
} sig;
// ---------------|

// memslot -------|
class mem {
public:
    bool exist(unsigned long timestamp);
    double get(unsigned long timestamp);
    void add(unsigned long timestamp, double new_val); 
    mem(unsigned long memN);
private:
    unsigned long* time;
    double* val;
    unsigned long N;
    unsigned long rdptr;
    unsigned long wrptr;
}; //memsl
// ---------------|



// neuron --------|
class neuron {
public:
    neuron();
    void add_inp(neuron* t_inp, double t_w, double t_bias);
    double evaluate(unsigned long timestamp);
    
private:
    unsigned long con;  // number of connections
    std::vector<neuron*> inp;    // array of neurons with input connection to current neuron
    std::vector<double> w;       // weights
    std::vector<double> bias;       // biases
    mem* membuf;                // memory buffer
    unsigned long memN;         // length of memory
    unsigned long memptr;       // mem write pointer

    double f(double x);     // transferfunction



}; //neuron
// ---------------|


#endif

#include <cmath>

