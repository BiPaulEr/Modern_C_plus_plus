#include <concepts>
#include <iostream>

template<typename T>
concept Entier = std::is_integral_v<T>;

template<Entier T>
void afficher(T x) {
    std::cout << "C'est un entier : " << x << std::endl;
}

int main() {
    afficher(42);      // OK, car 42 est un entier
    // afficher(3.14); // Erreur de compilation, 3.14 n'est pas un entier
}
