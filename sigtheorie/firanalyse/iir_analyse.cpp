#include <iostream>
#include <cmath>
#include <cstdlib>
#include "psplt/psplt.h"
#include "play.h"

#define TWOPI M_PI+M_PI

class complex{
public:
    complex(float t_re, float t_im) {
        re = t_re;
        im = t_im;
    } 

    float real() { return re; };
    float imag() { return im; };

    void add(complex* b) {
        re = re + (*b).real();
        im = im + (*b).imag();
    }

    float mag() { return std::sqrt(re*re + im*im); };
    float phs() { return std::atan2(im, re); };

private:
    float re;
    float im;

};


float* normalise(float* arr, unsigned long N) {
    float* out = new float[N];
    float val, max;
    for(unsigned long n=0; n<N; n++) {
        if((val = std::sqrt(arr[n]*arr[n])) > max) max = val;
    }   
    for(unsigned long n=0; n<N; n++) {
        out[n] = arr[n] / val;
    }   
    return out;
}

int abs(int a) {
    return std::sqrt(a*a);
}

double dabs(double x) {
    return std::sqrt(x*x);
}

complex* transf(int order, float coeff[], float omega) {
    complex* H = new complex(coeff[0], 0);
    complex* t_H;
    float re, im;
    for(int n=1; n<order; n++) {
        re = coeff[n]*std::cos(omega*n);
        im = coeff[n]*-std::sin(omega*n);
        t_H = new complex(re, im);
        (*H).add(t_H);
    }
    return H;
}




int main() {
    std::cout<<"N-th order system:\nN = ? ";
    int order = 0;
    std::cin>>order;
    std::cout<<order<<"-order system\n";
 
    float* coeff;
    float t_coeff = 0;
   
    if(order < 0) {
        std::cout << "creating random FIR system!\n";
        order = -order+1;
        coeff = new float[order];
        for(int n=0; n<order; n++) {
            coeff[n] = (float)(std::rand() % 100)/100 * std::pow(-1, std::rand() % 2);
            std::cout<<n<<"\t"<<coeff[n]<<std::endl;
        }
        double sum = 0;
        for(int n=0; n<order; n++) sum += dabs(coeff[n]);
        for(int n=0; n<order; n++) coeff[n] = coeff[n]/sum; 
    } else {
        order++;
        coeff = new float[order];

        
        std::cout<<"y[n] = ";
        for(int n=0; n<abs(order); n++) {
            std::cout << "+ c" << n << "x[n-"<<n<<"] ";
        }
        std::cout<<std::endl;
        for(int n=0; n<abs(order); n++) {
            std::cout<<"enter coefficient nr: "<<n<<"\n\t";
            std::cin >> t_coeff;
            coeff[n] = t_coeff;
        }
    }
    
    unsigned long res = 0;
    std::cout << "enter resolution: ";
    std::cin >> res;
    std::cout << "resolution: " << res << "\n\n-----starting analysis:-----\n";

    float omega = 0;
    double magresp[res+1];
    double phsresp[res+1];
    complex* H;
    double mag, phs;
    for(unsigned long i=0; i<res+1; i++) {
        omega = M_PI/(float)res * i;

        H = transf(order, coeff, omega);
        
        mag = (*H).mag();
        phs = (*H).phs();

        magresp[i] = mag;
        phsresp[i] = phs;
    }
    
    double x[res+1];
    for(unsigned long i=0; i<res; i++) x[i] = i;
    psplt pltm(x, magresp, res);
    psplt pltp(x, phsresp, res);
   

    char bool_play;
    std::cout << "play test? (y/n): ";
    std::cin >> bool_play;

    Player player;
    play:
    if(bool_play == 'y' || bool_play == 'Y') {
        int type = 0;
        std::cout << "type of input: \n \t(1: whitenoise;\n\t2: soundfile\n";
        std::cin >> type;
        if(type == 2) {
            player.play_file(order, coeff);
        } else {
            unsigned long N = 44100;
            float inbuf[N+order];
            for(unsigned long n=0; n<N; n++) inbuf[n] = (double)(rand() % 200 - 100)/100;
            
            for(unsigned long n=0; n<order; n++) inbuf[n+N] = 0;
            
            float outbuf[N+order];
            float out = 0;
            int maxorder = 0;
            for(unsigned long n=0; n<N+order; n++) {
                out = 0;

                for(int i=0; i<maxorder; i++) {
                    out += inbuf[n-i] * coeff[i];
                }
                if(maxorder < order) maxorder++;
                outbuf[n] = out; 
            }
            player.samples = outbuf;
            player.N = N+order;
        }
            


        player.play(normalise(player.samples, player.N), player.N);    
        std::cout << "replay? (y/n): ";
        std::cin >> bool_play;


        goto play;
    }
}

