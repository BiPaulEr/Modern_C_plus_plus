#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<int> nombres = { 10, 20, 30, 40, 50 };

    nombres.insert(60);
    nombres.insert(30);  

    auto result = nombres.insert(40);
    if (!result.second) {
        std::cout << "40 est deja present dans lensemble.\n";
    }

    if (nombres.find(30) != nombres.end()) {
        std::cout << "30 est present dans lensemble.\n";
    }
    else {
        std::cout << "30 nest pas dans lensemble.\n";
    }

    if (nombres.find(100) == nombres.end()) {
        std::cout << "100 nest pas dans lensemble.\n";
    }

    nombres.erase(20);  // Supprimer un élément par valeur

    auto it = nombres.find(40);
    if (it != nombres.end()) {
        nombres.erase(it);  // Supprimer par itérateur
    }

    nombres.clear();

    if (nombres.count(30) > 0) {
        std::cout << "30 est present dans lensemble.\n";
    }
    else {
        std::cout << "30 est pas present dans lensemble.\n";
    }

    std::cout << "Taille de lunordered_set : " << nombres.size() << std::endl;

    nombres = { 10, 20, 30, 40, 50 };

    std::cout << "elements de lensemble : ";
    for (const int& n : nombres) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "elements de lensemble (avec iterateurs) : ";
    for (auto it = nombres.begin(); it != nombres.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    if (nombres.empty()) {
        std::cout << "Lensemble est vide." << std::endl;
    }
    else {
        std::cout << "Lensemble nest pas vide." << std::endl;
    }

    return 0;
}
