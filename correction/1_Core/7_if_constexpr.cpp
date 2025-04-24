#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <cmath> // modf
#include <concepts> // optional pour C++20

template <typename T>
void print_info(const T& value) {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "Entier: " << value;
        if (value % 2 == 0) std::cout << " (pair)";
        else std::cout << " (impair)";
        std::cout << "\n";
    }
    else if constexpr (std::is_floating_point<T>::value) {
        double intpart;
        double frac = std::modf(value, &intpart);
        std::cout << "Flottant: " << value << "\n";
        std::cout << "Partie entiere: " << intpart << "\n";
        std::cout << "Partie decimale: " << frac << "\n";
    }
    else if constexpr (std::is_same<T, std::string>::value) {
        std::cout << "Chaine de caracteres : \"" << value << "\"\n";
        std::cout << "Longueur : " << value.length() << "\n";
    }
    else {
        std::cout << "Type inconnu\n";
    }
}
int main() {
    print_info(42);
    print_info(3.14);
    print_info(std::string("Hello"));
    print_info(true);
}
