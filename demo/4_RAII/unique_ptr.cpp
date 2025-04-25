#include <iostream>
#include <memory>

class Ressource {
public:
    Ressource(const std::string&& name) : name(name){ std::cout << "Ressource allouee\n"; }
    ~Ressource() { std::cout << "Ressource liberee\n"; }
    std::string name = "Ressource";
	void display() {
		std::cout << "isntance name : " << name << "\n";
	}
};

int main() {
    {
        Ressource ptr = Ressource("Ressource 1");
    }
    std::cout << "hors scope\n";
    {
        std::unique_ptr<Ressource> ptr = std::make_unique<Ressource>("Ressource 2");
		ptr->display();
    }
    std::cout << "hors scope\n";
}