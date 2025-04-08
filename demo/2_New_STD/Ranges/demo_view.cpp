#include <iostream>
#include <vector>
#include <ranges>

int main() {

    std::vector<int> vec = { 1, 2, 3, 4, 5 };
    auto filtered = vec | std::views::filter([](int x) { return x % 2 == 0; });
    auto transformed = vec | std::views::transform([](int x) { return x * 2; });
    auto taken = vec | std::views::take(3);
    auto dropped = vec | std::views::drop(3);
    auto reversed = vec | std::views::reverse;

    std::cout << "Filtre (pairs) : ";
    for (int x : filtered) std::cout << x << " ";
    std::cout << "\nTransforme (*2) : ";
    for (int x : transformed) std::cout << x << " ";
    std::cout << "\nPremiers 5 éléments : ";
    for (int x : taken) std::cout << x << " ";
    std::cout << "\nApres avoir ignore 5 éléments : ";
    for (int x : dropped) std::cout << x << " ";
    std::cout << "\nInverse : ";
    for (int x : reversed) std::cout << x << " ";
};