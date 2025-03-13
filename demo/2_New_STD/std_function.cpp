#include <iostream>
#include <functional>

void hello() {
    std::cout << "Bonjour, std::function !\n";
}

class A {
public:
    void afficher() { std::cout << "Methode de A appelee\n"; }
};

int main() {
    std::function<void()> f = hello;  // Stocker la fonction
    f();  // Appeler la fonction stockée

    std::function<int(int, int)> add = [](int a, int b) { return a + b; };
    std::cout << "3 + 5 = " << add(3, 5) << std::endl;
    
    A obj;
    std::function<void(A&)> methode = &A::afficher;  // Stocker un pointeur de méthode
    methode(obj);  // Appeler la méthode sur obj
}
