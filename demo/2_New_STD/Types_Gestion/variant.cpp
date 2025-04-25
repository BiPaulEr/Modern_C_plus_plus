#include <iostream>
#include <variant>


int main() {
    std::variant<int, double, std::string> v;

    v = 42;
    std::cout << "Contenu : " << std::get<int>(v) << std::endl;
    std::cout << "index() : " << v.index() << std::endl;

    v = 3.14;
    std::cout << "Contenu : " << std::get<double>(v) << std::endl;
    std::cout << "index() : " << v.index() << std::endl;

    v = "Hello, world!";
    std::cout << "Contenu : " << std::get<std::string>(v) << std::endl;
    std::cout << "index() : " << v.index() << std::endl; // Affiche 0 (int)

    try {
        int result = std::get<int>(v);
    }
	catch (const std::bad_variant_access& e) {
		std::cerr << "Erreur : " << e.what() << std::endl;
	}

    if (auto ptr = std::get_if<int>(&v)) {
        std::cout << "std::get_if<int> v : " << *ptr << std::endl;
    }
    else {
        std::cout << "Le type n'est pas un int." << std::endl;
    }

     if (auto ptr = std::get_if<std::string>(&v)) {
         std::cout << "std::get_if<string> : " << *ptr << std::endl;
     }
     else {
         std::cout << "Le type nest pas un string." << std::endl;
     }
     
    return 0;


}
