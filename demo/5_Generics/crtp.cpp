#include <iostream>

template <typename T>
class Base {
public:
    void afficher() {
        static_cast<T*>(this)->afficher_impl();
    }
};

class Derivee : public Base<Derivee> {
public:
    void afficher_impl() {
        std::cout << "Affichage depuis la classe derivee !" << std::endl;
    }
};

int main() {
    Derivee d;
    d.afficher();  // Appelle afficher_impl() de Derivee
}