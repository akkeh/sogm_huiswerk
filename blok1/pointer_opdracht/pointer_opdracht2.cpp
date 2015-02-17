#include <iostream>

int pass_value(int in_val) {        // pass-by-value
    in_val = 5;

    return in_val;
}

int pass_ptr(int* in_val) {         //pass-by-pointer (== pass by reference?)
    *in_val = 5;
    return *in_val;
}

int pass_ref(int& in_val) {         //pass-by-reference
    in_val = 7;
    return in_val;
}

void void_ptr(void* in_val) {       //pass void-pointer??
    std::cout<<"inval: " << in_val << std::endl;
    int val = 1;
    in_val = &val;
    
}

int main() {
    int val = 9;
    std::cout<<"val: " << val << std::endl;
    int old_val = val;

    pass_value(val);
    std::cout<<"val na pass_value(): " << val << std::endl;
    std::cout<<"veranderd? ";
    if(old_val != val) std::cout<<"ja\n"; 
    else std::cout<<"nee\n";
    old_val = val;

    pass_ptr(&val);
    std::cout<<"val na pass_ptr(): " << val << std::endl;
    std::cout<<"veranderd? ";
    if(old_val != val) std::cout<<"ja\n"; 
    else std::cout<<"nee\n";
    old_val = val;


    pass_ref(val);
    std::cout<<"val na pass_ref(): " << val << std::endl;
    std::cout<<"veranderd? ";
    if(old_val != val) std::cout<<"ja\n"; 
    else std::cout<<"nee\n";
    old_val = val;


    void_ptr(&val);
    std::cout<<"val na void_ptr(): " << val << std::endl;
     std::cout<<"veranderd? ";
    if(old_val != val) std::cout<<"ja\n"; 
    else std::cout<<"nee\n";
    old_val = val;

   return 0;
} //main()
