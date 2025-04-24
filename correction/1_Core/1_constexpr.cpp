#include <iostream>
#include <array>
#include <algorithm>

// constexpr fonction qui vérifie si un entier est premier
constexpr bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (!(n % i)) return false;
    }
    return true;
}

// Génère une table booleenne de nombre premier
constexpr std::array<bool, 51> generatePrimeTable() {
    std::array<bool, 51> table = {};
    for (int i = 0; i <= 50; ++i) {
        table[i] = isPrime(i);
    }
    return table;
}

// Initialisation à la compilation
constexpr auto primeTable = generatePrimeTable();

//Affiche les nombres premiers dans un tableau générique
auto printPrimesInArray = [](const auto& arr) {
    std::cout << "Nombres premiers : ";
    for (const auto& x : arr) {
        if (x >= 0 && x < static_cast<int>(primeTable.size()) && primeTable[x]) {
            std::cout << x << " ";
        }
    }
    std::cout << "\n";
    };

// Compte combien il y a de nombres premiers dans le tableau
auto countPrimes = [](const auto& arr) {
    return std::count_if(arr.begin(), arr.end(), [](int x) {
        return (x >= 0 && x < static_cast<int>(primeTable.size()) && primeTable[x]);
        });
    };

int main() {
    std::array<int, 10> nums = { 3, 4, 5, 10, 13, 20, 17, 23, 30, 37 };

    std::cout << "=== Analyse des nombres ===\n";
    printPrimesInArray(nums);
    std::cout << " Nombre total de nombres premiers : " << countPrimes(nums) << "\n";

    return 0;
}
