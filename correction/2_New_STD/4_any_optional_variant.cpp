#include <iostream>
#include <any>
#include <variant>
#include <vector>
#include <optional>

//find even or optional null see usage end this exercice
std::optional<int> find_even(const std::vector<int>& v) {
    for (int val : v) {
        if (val % 2 == 0)
            return val;
    }
    return std::nullopt;
}

int main() {

    /*
    * ANY SECTION
    */

    std::any a;

    // a est vide au départ
    std::cout << "Possede une valeur ? " << std::boolalpha << a.has_value() << std::endl;

    // Stocker un entier 100 dans a
    a = 100;

    // Afficher la valeur avec std::any_cast
    std::cout << "Valeur : " << std::any_cast<int>(a) << std::endl;

    // Réinitialiser la valeur
    a.reset();

    // Vérifier de nouveau si une valeur est présente
    std::cout << "Apres reset oossede une valeur ? " << a.has_value() << std::endl;

    // Stocker une chaîne "Bonjour"
    a = std::string("Bonjour");

    try {
        // Tenter de récupérer un int
        std::cout << std::any_cast<int>(a) << std::endl;
    }
    catch (const std::bad_any_cast& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    /*
    * VARIANT SECTION
    */

    std::variant<int, double, std::string> v;

    v = 10;
    std::cout << "Contenu : " << std::get<int>(v) << std::endl;
    std::cout << "Index actif : " << v.index() << std::endl;

    v = 2.71;
    std::cout << "Contenu : " << std::get<double>(v) << std::endl;

    v = "Salut";

    if (auto ptr = std::get_if<std::string>(&v)) {
        std::cout << "Contenu string : " << *ptr << std::endl;
    }
    else {
        std::cout << "Pas une string." << std::endl;
    }

    // Tenter un mauvais accès avec get<int>
    try {
        int val = std::get<int>(v);
    }
    catch (const std::bad_variant_access& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    /*
    * OPTIONAL SECTION
    */

    
    std::optional<int> opt;

    std::cout << "opt a une valeur ? " << (opt.has_value() ? "Oui" : "Non") << std::endl;

    opt = 99;
    if (opt) {
        std::cout << "Valeur : " << *opt << std::endl;
    }

    //discard the value
    opt.reset();

    //get value or default value
    std::cout << "Valeur ou par defaut : " << opt.value_or(0) << std::endl;

    std::vector<int> data_not_even = { 1, 3, 5 };
    std::vector<int> data_even = { 1, 2, 5 };

    
    //test it for not even 
    auto res_not_even = find_even(data_not_even);
    if (res_not_even.has_value()) {
        std::cout << "data_not_even Nombre pair trouve : " << *res_not_even << std::endl;
    }
    else {
        std::cout << "data_not_even Aucun nombre pair." << std::endl;
    }
    //test it for even 
    auto res_even = find_even(data_even);
    if (res_even.has_value()) {
        std::cout << "data_even Nombre pair trouve : " << *res_even << std::endl;
    }
    else {
        std::cout << "data_even Aucun nombre pair." << std::endl;
    }
    return 0;
}
