#include <iostream>
#include <any>
#include <variant>
#include <vector>
#include <optional>

//find even or optional null see usage end this exercice
std::optional<int> find_even(const std::vector<int>& v) {

}

int main() {

    /*
    * ANY SECTION
    */

    std::any a;

    // a est vide au départ
    std::cout << "Possede une valeur ? " << std::boolalpha <<  << std::endl;

    // Stocker un entier 100 dans a
    a = ;

    // Afficher la valeur avec std::any_cast
    std::cout << "Valeur : " <<  << std::endl;

    // Réinitialiser la valeur
    

    // Vérifier de nouveau si une valeur est présente
    std::cout << "Apres reset oossede une valeur ? " << << std::endl;

    // Stocker une chaîne "Bonjour"
    a = 

    try {
        // Tenter de récupérer un int
        std::cout <<   << std::endl;
    }
    catch ( ) {
        std::cerr << "Erreur : " <<  << std::endl;
    }

    /*
    * VARIANT SECTION
    */

    std::variant<int, double, std::string> v;

    //get contenu and index
    v = 10;
    std::cout << "Contenu : " <<   << std::endl;
    std::cout << "Index actif : " <<   << std::endl;

    v = 2.71;
    std::cout << "Contenu : " <<  << std::endl;

    v = "Salut";

    if () {
        std::cout << "Contenu string : " <<  << std::endl;
    }
    else {
        std::cout << "Pas une string." << std::endl;
    }

    // Tenter un mauvais accès avec get<int>
    try {
        
    }
    catch () {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }

    /*
    * OPTIONAL SECTION
    */

    
    std::optional<int> opt;

    std::cout << "opt a une valeur ? " << (     ? "Oui" : "Non") << std::endl;

    opt = 99;
    if () {
        std::cout << "Valeur : " <<   << std::endl;
    }

    //discard the value
    

    //get value or default value
    std::cout << "Valeur ou par defaut 0 : " <<  << std::endl;

    std::vector<int> data_not_even = { 1, 3, 5 };
    std::vector<int> data_even = { 1, 2, 5 };

    
    //test it for not even 
    auto res_not_even = find_even(data_not_even);
    if () {
        std::cout << "data_not_even Nombre pair trouve : " <<    << std::endl;
    }
    else {
        std::cout << "data_not_even Aucun nombre pair." << std::endl;
    }
    //test it for even 
    auto res_even = find_even(data_even);
    if () {
        std::cout << "data_even Nombre pair trouve : " <<   << std::endl;
    }
    else {
        std::cout << "data_even Aucun nombre pair." << std::endl;
    }
    return 0;
}
