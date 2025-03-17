#include <iostream>
#include <string>

template <typename T>
class Printer {
public:
    void print(const T& value) {
        std::cout << "Valeur : " << value << std::endl;
    }
};

template <>
class Printer<std::string> {
public:
    void print(const std::string& value) {
        std::cout << "Chaine de caractères : " << value << std::endl;
    }
};

int main() {
    Printer<int> p1;
    p1.print(42);

    Printer<std::string> p2;
    p2.print("Hello");

    return 0;
}
