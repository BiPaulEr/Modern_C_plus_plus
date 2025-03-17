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
    std::shared_ptr<Ressource> shared = std::make_shared<Ressource>();
    std::weak_ptr<Ressource> weak = shared; // weak_ptr does NOT increase use_count

    std::cout << "Initial use_count: " << shared.use_count() << std::endl;


    std::cout << "Resetting shared pointer..." << std::endl;
    shared.reset(); // Deletes object, since weak_ptr does not own it

    std::cout << "After reset, use_count: " << weak.use_count() << std::endl;

    if (weak.expired()) { // Check if weak_ptr is still valid
        std::cout << "Weak pointer is now expired." << std::endl;
    }

    return 0;
}