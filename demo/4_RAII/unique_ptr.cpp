#include <iostream>
#include <memory>

class Ressource {
public:
    Ressource() { std::cout << "Ressource allouee\n"; }
    ~Ressource() { std::cout << "Ressource liberee\n"; }
};

int main() {
    {
        Ressource ptr = Ressource();
    }
    std::cout << "hors scope\n";
    {
        std::unique_ptr<Ressource> ptr = std::make_unique<Ressource>();
    }
    std::cout << "hors scope\n";
}