#include <iostream>

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);  // fold expression (C++17)
}

int main() {
    std::cout << sum(1, 2, 3, 4) << std::endl;   // → 10
    std::cout << sum(1.5, 2, 3) << std::endl;    // → 6.5
}

