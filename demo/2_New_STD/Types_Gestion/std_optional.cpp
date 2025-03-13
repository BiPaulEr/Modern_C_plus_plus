#include <iostream>
#include <optional>
#include <vector>

std::optional<int> find_value(const std::vector<int>& v, int x) {
    for (const int& val : v) {
        if (val == x) {
            return val; // Retourne une valeur optionnelle
        }
    }
    return std::nullopt; // Aucun risque de fuite m�moire
}

int main() {
    // 1. Initialisation d'un std::optional vide
    std::optional<int> opt;
    std::cout << "opt contient une valeur ? " << (opt.has_value() ? "Oui" : "Non") << std::endl;

    // 2. Stocker une valeur dans l'optionnel
    opt = 42;
    std::cout << "Apr�s assignation, opt contient une valeur ? " << (opt.has_value() ? "Oui" : "Non") << std::endl;

    // 3. V�rifier si une valeur est pr�sente avec if (opt)
    if (opt) {
        std::cout << "Valeur stock�e dans opt : " << *opt << std::endl; // Utilisation de *opt
    }

    // 4. Acc�der � la valeur avec value_or (utilisation d'une valeur par d�faut)
    std::cout << "Valeur ou d�faut (si vide) : " << opt.value_or(100) << std::endl;

    // 5. Supprimer la valeur stock�e
    opt.reset();
    std::cout << "Apr�s reset(), opt contient une valeur ? " << (opt.has_value() ? "Oui" : "Non") << std::endl;

    // 6. Tester value_or apr�s reset()
    std::cout << "Valeur apr�s reset() ou valeur par defaut : " << opt.value_or(100) << std::endl;

    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    auto result = find_value(numbers, 6); // Test avec une valeur absente
    if (result) {
        std::cout << "Valeur trouv�e : " << *result << std::endl;
    }
    else {
        std::cout << "Valeur non trouvee" << std::endl;
    }

    return 0;
}
