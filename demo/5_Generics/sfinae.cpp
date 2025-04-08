#include <iostream>
#include <type_traits>

template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type checkType(T) {
    std::cout << "T est un entier.\n";
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type checkType(T) {
    std::cout << "T est un flottant.\n";
}

int main() {
    checkType(5);      // Appelle la version pour entiers
    checkType(3.14);   // Appelle la version pour flottants
    return 0;
}
