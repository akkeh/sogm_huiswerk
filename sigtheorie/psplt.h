#ifndef _PSPLT_H_
#define _PSPLT_H_

#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

class psplt{
public:
    psplt(double* t_x, double* t_y, unsigned long t_N);   
private:
    std::ofstream fs;
    std::string filename;
    // data:
    double* x;
    double* y;
    unsigned long N;
    // axis:
    unsigned long xmin, xmax;
    unsigned long ymin, ymax;
   
    int init_file();
    int write_file(); 
    int write_data();
    int write_opts();
    int write_gproc();
    int write_dproc();
    int invocate();
};

#endif
