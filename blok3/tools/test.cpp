#include <iostream>
#include <cstdlib>

int main() {
    unsigned int t1, t2;
    int t3;
    t1 = 10;
    t2 = 30;
    t3 = t1 - t2;
    if((t1 < t2) && (t1 < abs(t3))) std::cout << "t3: " << t3 << std::endl; 

}
