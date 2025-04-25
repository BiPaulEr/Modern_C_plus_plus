#include <iostream>
#include <any>
#include <string>
#include <typeinfo>

int main() {
    std::any a;

    // a est vide au d�part
    std::cout << "a.has_value() ? " << std::boolalpha << a.has_value() << std::endl;

    // Stockage d'un int
    a = 42;
    std::cout << "Contenu (int) : " << std::any_cast<int>(a) << std::endl;

    // V�rification du type contenu
    std::cout << "Type de a : " << a.type().name() << std::endl;
    std::cout << "a.has_value() ? " << a.has_value() << std::endl;

    // R�initialisation : suppression de la valeur
    a.reset();
    std::cout << "Apr�s reset : a.has_value() ? " << a.has_value() << std::endl;

    // Stockage d'une string
    a = std::string("Hello");
    std::cout << "Contenu (string) : " << std::any_cast<std::string>(a) << std::endl;
    std::cout << "Type de a : " << a.type().name() << std::endl;

    // Tentative d'acc�s avec un mauvais type
    try {
        std::cout << "Tentative d'acc�s en tant que int : ";
        std::cout << std::any_cast<int>(a) << std::endl;  // Mauvais type -> exception
    }
    catch (const std::bad_any_cast& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    return 0;
}
