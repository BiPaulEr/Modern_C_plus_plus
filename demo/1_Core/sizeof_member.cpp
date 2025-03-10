#include <iostream>

struct Test {
    int a;      // 4 octets (sur une architecture 32 bits ou 64 bits)
    double b;   // 8 octets
    char c;     // 1 octet (+ padding)
};

int main() {
    std::cout << "Taille de l'objet Test : " << sizeof(Test) << " octets\n";
    std::cout << "Taille de a : " << sizeof(((Test*)0)->a) << " octets\n";
    std::cout << "Taille de b : " << sizeof(((Test*)0)->b) << " octets\n";
    std::cout << "Taille de c : " << sizeof(((Test*)0)->c) << " octets\n";
}