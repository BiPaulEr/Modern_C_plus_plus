#include <iostream>
#include <format>

int main() {
    int age = 25;
    std::string name = "Alice";

    // Formatage d'une cha�ne avec des variables
    std::string formatted_str = std::format("Nom : {}, age : {}", name, age);

    std::cout << formatted_str << std::endl; // Affiche: Nom : Alice, �ge : 25

    return 0;
}
