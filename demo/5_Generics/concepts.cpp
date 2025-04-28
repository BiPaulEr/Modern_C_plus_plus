#include <concepts>
#include <iostream>

template<typename T>
concept Entier = std::is_integral_v<T>;

template<Entier T>
void afficher(T x) {
    std::cout << "C'est un entier : " << x << std::endl;
}

template<typename T>
concept Flottant = std::is_floating_point_v<T>;

template<Flottant T>
void afficherFlottant(T x) {
    std::cout << "C'est un nombre flottant : " << x << std::endl;
}

template<typename T>
concept EstUnPointeur = std::is_pointer_v<T>;

template<EstUnPointeur T>
void afficherPointeur(T ptr) {
    if (ptr)
        std::cout << "Pointeur non nul." << std::endl;
    else
        std::cout << "Pointeur nul." << std::endl;
}
    
int main() {
    afficher(42);      // OK, car 42 est un entier
    // afficher(3.14); // Erreur de compilation, 3.14 n'est pas un entier

    afficherFlottant(3.14);  // OK
    // afficherFlottant(42); // Erreur de compilation, 42 est un entier

    int a = 5;
    afficherPointeur(&a);  // OK
    int* p = nullptr;
    afficherPointeur(p);   // OK
}
