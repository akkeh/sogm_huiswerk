#include <iostream>

int main() {

    char letter = 'a';
    char* letterpntr = &letter;
    
    std::cout << "letter: " << letter << std::endl;
    std::cout << "pointer: " << (std::hex) << (long)letterpntr << std::endl;
    std::cout << "inhoud: " << *letterpntr << std::endl;
    
    *letterpntr = 'z';             // door '*' gaat het over de inhoud
    std::cout << "letter: " << letter << std::endl;
    std::cout << "pointer: " << (std::hex) << (long)letterpntr << std::endl;
    std::cout << "inhoud: " << *letterpntr << std::endl;
    




    
    return 0;
}
