#include <concepts>
#include <iostream>

template<typename T>
    requires requires(T x) {
        { x + x } -> std::convertible_to<T>;
}
void addition(T x) {
    std::cout << x + x << std::endl;
}

int main() {
    addition(5);       // OK, 5 + 5 est valide
    addition(2.5);     // OK, 2.5 + 2.5 est valide
    // addition("abc"); // Erreur : pas d'opération '+' définie pour const char*
}
