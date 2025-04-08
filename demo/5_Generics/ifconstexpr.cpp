#include <type_traits>
#include <iostream>

template<typename T>
void afficher(T val) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Type entier : " << val << std::endl;
    }
    else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Type flottant : " << val << std::endl;
    }
    else {
        std::cout << "Type inconnu" << std::endl;
    }
}

int main() {
    afficher(10);     // entier
    afficher(3.14);   // flottant
    afficher("texte"); // inconnu
}
