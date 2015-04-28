#include <cmath>
#include <iostream>
#include <cstdlib>
#include <string>
#include "wavio.h"
/*

*/
class iir{
public:
    iir(int t_forder, int t_iorder, double* t_fcoef, double* t_icoef);
    double calc(double x);
private:
    int forder, iorder;

    double* mem_x;  // length = f_order
    double* mem_y;  // length = i_order

    double* fcoef;
    double* icoef;
};


iir::iir(int t_forder, int t_iorder, double* t_fcoef, double* t_icoef){
    forder = t_forder;
    iorder = t_iorder;
    fcoef = t_fcoef;
    icoef = t_icoef;
    mem_x = new double[forder];
    mem_y = new double[iorder];
    for(int n = 0; n<forder; n++) mem_x[n] = 0;
    for(int n = 0; n<iorder; n++) mem_y[n] = 0;
}

double iir::calc(double x) {
    double y = 0;
    //calc x[n-k]
    y = fcoef[0] * x;
    for(int k=1; k<forder; k++) {
        y += fcoef[k] * mem_x[k];
    }
    for(int k=0; k<forder-1; k++) mem_x[forder - k] = mem_x[forder - k - 1];
    mem_x[0] = x;
    
    //calc y[n-k]
    for(int k=0; k<iorder; k++) {
        y += icoef[k] * mem_y[k];
    }
    for(int k=0; k<iorder-1; k++) mem_y[iorder - k] = mem_y[iorder - k -1];
    mem_y[0] = y;

    return y;
}

int main(int argc, char** argv) {
    int ford = atoi(argv[1]) + 1;    
    int iord = atoi(argv[2]); 
    double* fg = new double[ford];
    double* ig = new double[iord];

    for(unsigned int n=0; n<ford; n++) {
        std::cout << "Finite coefficient " << n << "(x[n-" << n << "]): ";
        double coeff;
        std::cin >> coeff;
        fg[n] = coeff;
    }

    for(unsigned int n=0; n<iord; n++) {
        std::cout << "Infinite coefficient " << n+1 << "(y[n-" << n+1 << "]): ";
        double coeff;
        std::cin >> coeff;
        ig[n] = coeff;
    }


    std::cout << "init filter\n";
    iir filter(iord, ford - 1, ig, fg);
    
    
    std::cout << "calculating....\n";
    wavio input;
    std::string ifile;
    std::cout << "input file: \n";
    std::cin >> ifile;
    input.read(ifile.c_str(), 0);

    double* x = input.data;
    unsigned long N = input.N;
    double* y = new double[N];

    for(unsigned long n=0; n<N; n++) {
        x[n] = (double)(rand() % 200)/200 - 1;
        y[n] = filter.calc(x[n]);
    }
    std::cout << "writing\n";
    
    wavio wav;
    wav.data = y;
    wav.N = N;
    wav.write("test_output.wav", 16, 1);

    wav.data = x;
    wav.N = N;
    wav.write("test_input.wav", 16, 1);




}
