#include <iostream>
#include <memory>

class Ressource {
public:
    Ressource() { std::cout << "Ressource allouee\n"; }
    ~Ressource() { std::cout << "Ressource liberee\n"; }
};

void fonction(std::shared_ptr<Ressource> ptr) {
    std::cout << "Utilisation de la ressource\n";
    std::cout << "Nombre de references dans fonction : " << ptr.use_count() << "\n";
}

int main() {
    std::shared_ptr<Ressource> ptr1 = std::make_shared<Ressource>();
    std::shared_ptr<Ressource> ptr2 = ptr1; // Copie, compteur de références +1

    std::cout << "Nombre de references : " << ptr1.use_count() << "\n";

    fonction(ptr2); // Passe un shared_ptr par valeur
    std::cout << "Nombre de references apres appel : " << ptr1.use_count() << "\n";

	ptr2.reset(); // Décrémente le compteur de références
	std::cout << "Nombre de references apres reset : " << ptr1.use_count() << "\n";

    std::cout << "reset ptr1\n";
	ptr1.reset(); 
    std::cout << "fin programme\n";
    return 0; // La ressource sera libérée ici lorsque le dernier shared_ptr sera détruit
}
