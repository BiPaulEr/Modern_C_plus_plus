#include <iostream>

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}
template <typename... Args>
auto sum_of_conditionals(Args... args) {
    return (... + (args > 0 ? args : 0));
}

template <typename... Args>
auto sum_of_squares(Args... args) {
    return (... + (args * args));  
}

template <typename... Args>
auto count_positive(Args... args) {
    return (... + (args > 0 ? 1 : 0)); 
}

int main() {
    std::cout << sum(1, 2, 3, 4) << std::endl;   // → 10
    std::cout << sum(1.5, 2, 3) << std::endl;    // → 6.5
    std::cout << sum_of_conditionals(1, -2, 3, 4, -5) << std::endl;  // 1 + 3 + 4 = 8
    std::cout << sum_of_conditionals(-1, -2, -3) << std::endl;       // 0

    std::cout << sum_of_squares(1, 2, 3, 4) << std::endl;  
    std::cout << sum_of_squares(1.5, 2.5) << std::endl; 
}

