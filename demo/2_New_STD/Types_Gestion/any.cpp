#include <iostream>
#include <any>

int main() {
    std::any a = 42;          // Stockage d'un int
    std::cout << std::any_cast<int>(a) << std::endl;  // Accès à l'élément stocké (42)

    a = std::string("Hello");  // Stockage d'une string
    std::cout << std::any_cast<std::string>(a) << std::endl;  // Accès à la string

    try {
		std::cout << std::any_cast<int>(a) << std::endl;  // Erreur : impossible de convertir une string en int
	}
    catch (const std::bad_any_cast& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}