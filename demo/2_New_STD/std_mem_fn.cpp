#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

class A {
public:
    void afficher() {
        std::cout << "Methode appelee via mem_fn\n";
    }
};
int main() {
    A obj;
    auto f = std::mem_fn(&A::afficher);
    f(obj);

    std::vector<A> objets(3);
    std::for_each(objets.begin(), objets.end(), std::mem_fn(&A::afficher));
    return 0;
}
