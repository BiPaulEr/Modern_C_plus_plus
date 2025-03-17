#include <iostream>
#include <memory>

class Ressource {
public:
    Ressource() { std::cout << "Ressource allouee\n"; }
    ~Ressource() { std::cout << "Ressource liberee\n"; }
};

void utiliserRessource(std::unique_ptr<Ressource> ptr) {
    std::cout << "Utilisation de la ressource\n";
}

int main() {
    std::unique_ptr<Ressource> ptr1 = std::make_unique<Ressource>();
    // Transfert de la responsabilité à ptr2
    std::unique_ptr<Ressource> ptr2 = std::move(ptr1);

    if (!ptr1) {
        std::cout << "ptr1 ne possède plus la ressource\n";
    }

	//utiliserRessource(ptr2); // Erreur pas de copie possible
    utiliserRessource(std::move(ptr2)); // Transfert de ptr2 à la fonction
    std::cout << "Global context\n";
    return 0;
}