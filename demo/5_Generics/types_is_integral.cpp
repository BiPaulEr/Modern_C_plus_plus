#include <iostream>
#include <string>
#include <type_traits>

template <typename T>
void checkType() {
    if constexpr (std::is_integral<T>::value) {
        std::cout << "T est un type entier.\n";
    }
    else {
        std::cout << "T nest pas un type entier.\n";
    }
}

int main() {
    checkType<int>();    // Affiche : "T est un type entier."
    checkType<double>(); // Affiche : "T n'est pas un type entier."
    return 0;
}
