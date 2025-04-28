#include <iostream>

template <typename T, typename... Args>
bool contains(T value, Args... args) {
    return (... || (value == args));
}

template <typename... Args>
void print_with_separator(const std::string& sep, Args... args) {
    (((std::cout << args << sep), ...) << "\n");
}

template <typename... Args>
auto count_positive(Args... args) {
    return (... + (args > 0 ? 1 : 0));
}

int main() {
    //1
    print_with_separator(", ", 1, 2, 3, 4);  
    print_with_separator(" - ", "apple", "banana", "cherry"); // → apple - banana - cherry - 

    // 2
    std::cout << contains(3, 1, 2, 3, 4) << std::endl;  // → true
    std::cout << contains(5, 1, 2, 3, 4) << std::endl;  // → false

    //3
    std::cout << count_positive(1, -2, 3, 4, -5) << std::endl;  // → 3 (1, 3, 4 sont positifs)
    std::cout << count_positive(-1, -2, -3) << std::endl;       // → 0
}
