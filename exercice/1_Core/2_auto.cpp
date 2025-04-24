#include <iostream>
#include <array>
#include <algorithm>

int main() {
    std::array<float, 5> nums_float = { 2.5, 4.0, 7.3, 10.1, 3.2 };
    std::array<int, 5> nums_int = { 2, 4, 7, 10, 3 };
    
    //calcul la somme de larray
    auto sum;

    //calcul le produit de larray
    auto product;

    //doubel value de l'array
    auto doubleValues;

    std::cout << "Somme float : " << sum(nums_float) << "\n";
    std::cout << "Produit float : " << product(nums_float) << "\n";
    std::cout << "Somme int : " << sum(nums_int) << "\n";
    std::cout << "Produit int : " << product(nums_int) << "\n";

    doubleValues(nums_float); // Modifie les valeurs en place
    doubleValues(nums_int); // Modifie les valeurs en place

    std::cout << "Apres avoir double les valeurs de num_float: ";
    //
    std::cout << "\n";

    std::cout << "Apres avoir double les valeurs de num_float: ";
    //
    std::cout << "\n";

    return 0;
}
