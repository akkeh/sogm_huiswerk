#include <cmath>
#include <iostream>
#include <cstdlib>
/*

*/
class iir{
    double* mem_x;
    double* mem_y;
    double* swap_x;
    double* swap_y;
    unsigned int iord, ford;
    double* ig;
    double* fg;
public:
    iir(unsigned int t_iord, unsigned int t_ford, double* t_ig, double* t_fg) {
        iord = t_iord;
        ford = t_ford;
        ig = new double[iord];
        fg = new double[ford+1];

        mem_x = new double[ford];
        for(unsigned int n=0; n<ford; n++) {
            fg[n] = t_fg[n];
            mem_x[n] = 0;
        }
        mem_y = new double[iord];
        for(unsigned int n=0; n<iord; n++) {
            ig[n] = t_ig[n];
            mem_y[n] = 0;
        }
    }

    double calc(double x) {
        swap_x = new double[ford];
        swap_y = new double[iord];

        double y = 0;
        for(unsigned int n=0; n<iord; n++) {
            y += mem_y[n] * ig[n];
            swap_y[n+1 % iord] = mem_y[n];
        }
        
        for(unsigned int n=0; n<ford; n++) {
            y += mem_x[n] * fg[n+1];
            swap_x[n+1 % ford] = mem_x[n];
        }
        y += x * fg[0];
        swap_x[0] = x;
        swap_y[0] = y;
        mem_x = swap_x;
        mem_y = swap_y;

        return y;
    }

};

int main(int argc, char** argv) {
    double freq = atof(argv[1]);

    int iord = 1;
    int ford = 2;
    double* ig = new double[iord];
    double* fg = new double[ford];
    for(unsigned int n=0; n<iord; n++) {
        std::cout << "Infinite coefficient " << n << ": ";
        double coeff;
        std::cin >> coeff;
        ig[n] = coeff;
    }
    for(unsigned int n=0; n<ford; n++) {
        std::cout << "Finite coefficient " << n << ": ";
        double coeff;
        std::cin >> coeff;
        fg[n] = coeff;
    }
    iir filter(iord, ford, ig, fg);
    
    unsigned long N = 44100;
    double* x = new double[N];
    double* y = new double[N];
    for(unsigned long n=0; n<N; n++) {
        y[n] = filter.calc(std::sin((M_PI+M_PI) * freq * n / 44100.0));
    }

}
