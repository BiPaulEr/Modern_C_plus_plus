#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };

    
    auto sum = [](auto arr) {
        return std::accumulate(arr.begin(), arr.end(), 0);
        };

    
    auto product = [](auto arr) {
        return std::accumulate(arr.begin(), arr.end(), 1, std::multiplies<>());
        };

    *********sumResult = sum(numbers);
    ********* productResult = product(numbers); 

    
    std::cout << "Somme: " << sumResult << std::endl;
    std::cout << "Produit: " << productResult << std::endl;

    std::cout << "Add 6 " << std::endl;
    auto& refNumbers = numbers;
    ******** newRefNumbers = refNumbers;
    newRefNumbers.push_back(6);

    ****** sumResult_add6 = sum(numbers);
   ******* productResult_add6 = product(numbers);

    std::cout << "Somme: " << sumResult_add6 << std::endl;
    std::cout << "Produit: " << productResult_add6 << std::endl;


    std::vector<float> floatNumbers = { 1.1f, 2.2f, 3.3f, 4.4f, 5.5f };
    ********* floatSum = sum(floatNumbers);

    std::cout << "Somme des flottants: " << floatSum << std::endl;

    
    return 0;
}
