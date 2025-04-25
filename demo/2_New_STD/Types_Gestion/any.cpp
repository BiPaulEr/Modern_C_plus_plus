#include <iostream>
#include <any>
#include <string>
#include <typeinfo>

int main() {
    std::any a;

    // a est vide au départ
    std::cout << "a.has_value() ? " << std::boolalpha << a.has_value() << std::endl;

    // Stockage d'un int
    a = 42;
    std::cout << "Contenu (int) : " << std::any_cast<int>(a) << std::endl;

    // Vérification du type contenu
    std::cout << "Type de a : " << a.type().name() << std::endl;
    std::cout << "a.has_value() ? " << a.has_value() << std::endl;

    // Réinitialisation : suppression de la valeur
    a.reset();
    std::cout << "Après reset : a.has_value() ? " << a.has_value() << std::endl;

    // Stockage d'une string
    a = std::string("Hello");
    std::cout << "Contenu (string) : " << std::any_cast<std::string>(a) << std::endl;
    std::cout << "Type de a : " << a.type().name() << std::endl;

    // Tentative d'accès avec un mauvais type
    try {
        std::cout << "Tentative d'accès en tant que int : ";
        std::cout << std::any_cast<int>(a) << std::endl;  // Mauvais type -> exception
    }
    catch (const std::bad_any_cast& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
