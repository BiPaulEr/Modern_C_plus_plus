#include <iostream>
#include <tuple>
#include <string>

void print_tuple(const std::tuple<int, double, std::string>& t) {
    std::cout << "Premier element : " << std::get<0>(t) << std::endl;
    std::cout << "Deuxieme element : " << std::get<1>(t) << std::endl;
    std::cout << "Troisieme element : " << std::get<2>(t) << std::endl;
}

std::tuple<int, double, std::string> create_tuple() {
    return std::make_tuple(10, 3.14, "C++");
}

template <typename Tuple>
void print_tuple_size(const Tuple& t) {
    std::cout << "Taille du tuple : " << std::tuple_size<Tuple>::value << std::endl;
}

void modify_tuple(std::tuple<int, double, std::string>& t) {
    std::get<0>(t) = 42;
    std::get<1>(t) = 2.71;
    std::get<2>(t) = "C++11";
}

int main() {
    std::cout << "Demonstration de base avec std::tuple : " << std::endl;
    
    std::tuple<int, double, std::string> t(10, 3.14, "C++");

    print_tuple(t);

    std::cout << "\nApres modification de l'element du tuple : " << std::endl;
    modify_tuple(t);
    print_tuple(t);

    print_tuple_size(t);

    return 0;
}
