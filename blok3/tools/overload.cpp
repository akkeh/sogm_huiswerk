#include <iostream>

class iets {
public:
    iets() {
        val = 0;
    }
    
    iets(double t_val) {
        val = val;
    }

    double val(

    double operator+ (iets b) {
        return iets c(val + b.val);
    }

private:
    double val;

};


int main() {
    iets a(10);
    iets b(11);
    iets c = a+b;
    std::cout << "val: " << c.val << std::endl; 
}
