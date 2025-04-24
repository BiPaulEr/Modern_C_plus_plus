#include <iostream>
#include <array>
#include <algorithm>

// constexpr fonction qui vérifie si un entier est premier
 bool isPrime(int n) {

}

// constexpr Genere une table booleenne de nombre premier
std::array<bool, 51> generatePrimeTable() {
    std::array<bool, 51> table = {};

    return table;
}

// constexpr Initialisation à la compilation
auto primeTable = generatePrimeTable();

//Affiche les nombres premiers dans un tableau générique
auto printPrimesInArray = [](const auto& arr) {
    std::cout << "Nombres premiers : ";
    



    std::cout << "\n";
    };

// Compte combien il y a de nombres premiers dans le tableau
auto countPrimes = [](const auto& arr) {
    return std::count_if(arr.begin(), arr.end(), 


        );
    };

int main() {
    std::array<int, 10> nums = { 3, 4, 5, 10, 13, 20, 17, 23, 30, 37 };

    std::cout << "=== Analyse des nombres ===\n";
    printPrimesInArray(nums);
    std::cout << " Nombre total de nombres premiers : " << countPrimes(nums) << "\n";

    return 0;
}
