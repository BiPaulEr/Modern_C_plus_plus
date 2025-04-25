#include <iostream>
#include <memory>

class Ressource {
    int* ptr;
public:
    Ressource(int value) : ptr(new int(value)) { std::cout << "Ressource allouee\n"; }
    ~Ressource() {
        std::cout << "Ressource liberee\n"; 
        delete ptr;
    }
};


int main() {
    std::shared_ptr<Ressource> ptr1 = std::make_shared<Ressource>(99);
    std::cout << "Nombre de references : " << ptr1.use_count() << "\n";

    std::shared_ptr<Ressource> ptr3(ptr1.get()); // Copie, compteur de références +1
    std::cout << "Nombre de references after ptr3 from raw pointer : " << ptr1.use_count() << "\n";
    std::cout << "fin programme\n";
    return 0; // La ressource sera libérée ici lorsque le dernier shared_ptr sera détruit
}
