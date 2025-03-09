#include <iostream>
#include <initializer_list> 

class MaClasse {
    public:
        MaClasse(std::initializer_list<int> liste) { // Constructeur avec std::initializer_list
            for (int val : liste) {
                std::cout << "Valeur recue : " << val << std::endl;
            }
        }
};

int main() {
    MaClasse obj = { 10, 20, 30 };  // Initialise un objet avec std::initializer_list
    return 0;
}