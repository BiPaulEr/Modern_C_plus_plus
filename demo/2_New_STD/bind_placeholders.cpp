#include <iostream>
#include <functional>
  

void afficher(int a, int b) {
    std::cout << "a: " << a << ", b: " << b << std::endl;
}
void incrementer(int& x) {
    x++;
}


void afficher_const(const int& x) {
    std::cout << "La valeur est : " << x << std::endl;
}

int main() {
    auto f = std::bind(afficher, 10, 20);
    f();  // Appelle afficher(10, 20)
    auto f1 = std::bind(afficher, 10, std::placeholders::_1);
    f1(20);  // Appelle afficher(10, 20)
    auto f2 = std::bind(afficher, std::placeholders::_1, 10);
    f2(20);  // Appelle afficher(20, 10)
    auto f3 = std::bind(afficher, std::placeholders::_2, std::placeholders::_1);
    f3(20, 10);  // Appelle afficher(10, 20)
    auto f4 = std::bind(afficher, std::placeholders::_1, std::placeholders::_2);
    f4(20, 10);  // Appelle afficher(20, 10)

    int val = 0;
    auto f_ref = std::bind(incrementer, std::ref(val));
    f_ref();  // Incrémente val
	std::cout << "Valeur de val : " << val << std::endl;
    f_ref();  // Incrémente val
    std::cout << "Valeur de val : " << val << std::endl;
    auto f_cref = std::bind(afficher_const, std::cref(val));
    f_cref();  // Affiche "La valeur est : 10"
}
