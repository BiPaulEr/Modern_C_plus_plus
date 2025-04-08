#include <iostream>
#include <variant>
#include <string>
#include <type_traits>  // pour std::decay_t

void handleVariant(const std::variant<int, double, std::string>& v) {
    std::visit([](auto&& arg) {
        using T = std::decay_t<decltype(arg)>;

        if constexpr (std::is_same_v<T, int>)
            std::cout << "int: " << arg << '\n';
        else if constexpr (std::is_same_v<T, double>)
            std::cout << "double: " << arg << '\n';
        else if constexpr (std::is_same_v<T, std::string>)
            std::cout << "string: " << arg << '\n';
        }, v);
}

int main() {
    handleVariant(42);                       // int
    handleVariant(3.14);                    // double
    handleVariant(std::string("hello"));    // string
}
