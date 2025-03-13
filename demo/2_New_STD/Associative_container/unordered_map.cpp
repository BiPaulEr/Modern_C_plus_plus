#include <iostream>
#include <unordered_map>

int main() {

    std::unordered_map<std::string, int> population = {
        {"Paris", 2200000}, {"Lyon", 515000}, {"Marseille", 861000}
    };

    population["Toulouse"] = 479000;
    population["Bordeaux"] = 250000;

    population.insert({ "Lille", 232000 });
    population.insert({ "Nice", 340000 });  // Ajout d'une ville

    auto result = population.insert({ "Paris", 2200000 });
    if (!result.second) {
        std::cout << "Paris existe déjà dans la carte." << std::endl;
    }

    std::cout << "Population de Lyon : " << population["Lyon"] << std::endl;

    auto it = population.find("Marseille");
    if (it != population.end()) {
        std::cout << "Population de Marseille : " << it->second << std::endl;
    }

    it = population.find("Paris");
    if (it == population.end()) {
        std::cout << "Paris n'a pas été trouvé." << std::endl;
    }

    population.erase("Lille");

    auto it_to_remove = population.find("Bordeaux");
    if (it_to_remove != population.end()) {
        population.erase(it_to_remove);
    }

    population.erase(population.begin(), population.end());  // Supprimer tous les éléments

    if (population.count("Toulouse") > 0) {
        std::cout << "Toulouse est présente dans la carte." << std::endl;
    }
    else {
        std::cout << "Toulouse n'est pas présente." << std::endl;
    }

    std::cout << "Taille du unordered_map : " << population.size() << std::endl;

    std::cout << "Liste des villes et populations :\n";
    for (const auto& pair : population) {
        std::cout << pair.first << " => " << pair.second << std::endl;
    }

    std::cout << "\nParcours avec itérateurs :\n";
    for (auto it = population.begin(); it != population.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    if (population.empty()) {
        std::cout << "Le unordered_map est vide." << std::endl;
    }
    else {
        std::cout << "Le unordered_map n'est pas vide." << std::endl;
    }

    return 0;
}
