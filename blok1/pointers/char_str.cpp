#include <iostream>
#include <cmath>

int main() {
    char* str = "test";            //  "test0" is wat in geheugen komt

    
    char* str_ptr = str;
    for(int i=0; i<5; i++) {
        std::cout << (int) *str_ptr << std::endl;
        str_ptr++;
    }
    str_ptr = str;
    while((int) *str_ptr != '\0') {
        std::cout << *str_ptr << std::endl;
        str_ptr++;
    }
   
    return 0;
}
