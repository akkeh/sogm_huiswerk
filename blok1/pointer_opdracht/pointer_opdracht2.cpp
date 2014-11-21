#include <iostream>

int pass_value(int in_val) {
    in_val = 5;

    return in_val;
}

int pass_ptr(int* in_val) {
    *in_val = 5;
    return *in_val;
}

int main() {
    int val = 9;
    std::cout<<"val: " << val << std::endl;
    
    pass_value(val);
    std::cout<<"val na pass_value(): " << val << std::endl;
    
    pass_ptr(&val);
    std::cout<<"val na pass_ptr(): " << val << std::endl;

    

    return 0;
} //main()
