#include <concepts>
#include <iostream>

template<typename T>
    requires requires(T x) {
        { x + x } -> std::convertible_to<T>;
}
void addition(T x) {
    std::cout << x + x << std::endl;
}

template<typename T>
    requires requires(T t) {
        { t(42) };  // T should be callable with an integer
}
void invoke(T t) {
    t(42);  // Call the function with an integer argument
}

template<typename T>
    requires requires(T a) {
        { a + a };  // T must support the '+' operator
        { a * a };  // T must support the '*' operator
}
void arithmeticOperations(T a) {
    std::cout << "Sum: " << a + a << ", Product: " << a * a << std::endl;
}


template<typename T>
    requires requires(T t) {
        { t.print() };  // T should have a member function 'print()'
}
void callPrint(T t) {
    t.print();  // Call the print() member function
}


template<typename T, typename U>
    requires std::integral<T>&& std::floating_point<U>
void combineTypes(T t, U u) {
    std::cout << "Integer: " << t << ", Float: " << u << std::endl;
}

struct OpertorInt {
    void operator()(int x) {
        std::cout << "Test::operator() called with " << x << std::endl;
    }
};
struct Printer {
    void print() {
        std::cout << "Printer::print() called "<< std::endl;
    }
};
int main() {
    addition(5);       // OK, 5 + 5 est valide
    addition(2.5);     // OK, 2.5 + 2.5 est valide
    // addition("abc"); // Erreur : pas d'opération '+' définie pour const char*
    
	invoke(OpertorInt()); // OK, 42 est un entier

	arithmeticOperations(4); // OK, 4 + 4 et 4 * 4 sont valides

	callPrint(Printer()); // OK, Printer a une méthode print()
}
