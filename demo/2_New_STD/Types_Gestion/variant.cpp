#include <iostream>
#include <variant>

int main() {
    std::variant<int, double, std::string> v;

    v = 42;
    std::cout << "Contenu : " << std::get<int>(v) << std::endl;

    v = 3.14;
    std::cout << "Contenu : " << std::get<double>(v) << std::endl;

    v = "Hello, world!";
    std::cout << "Contenu : " << std::get<std::string>(v) << std::endl;

    try {
        int result = std::get<int>(v);
    }
	catch (const std::bad_variant_access& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
    return 0;
}
