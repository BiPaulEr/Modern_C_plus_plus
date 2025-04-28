#include <concepts>
#include <iostream>


template<typename T, typename U>
concept SameType = std::same_as<T, U>; // T and U must be the same type

template<typename T, typename U>
    requires SameType<T, U>
void compareTypes(T a, U b) {
    std::cout << "Les types sont identiques." << std::endl;
}


struct Base {
    void action() const {
        std::cout << "Action de Base" << std::endl;
    }
};

struct Derived : Base {
    void operator()() const {
        std::cout << "Operator() de Derived" << std::endl;
    }
};

template<typename T>
concept DerivedAndCallable = std::derived_from<T, Base> && std::invocable<T>;

template<typename T>
    requires DerivedAndCallable<T>
void utiliser(T objet) {
    objet();
    objet.action();
}

template<typename T>
concept ArithmetiqueEtAppelable = requires(T a) {
    { a + a } -> std::same_as<T>;
    { a* a } -> std::same_as<T>;
    { a() } -> std::same_as<void>;
};

template<typename T>
    requires ArithmetiqueEtAppelable<T>
void faireOperations(T a) {
    std::cout << "Addition: " << a + a << std::endl;
    std::cout << "Multiplication: " << a * a << std::endl;
    a(); // appel de la fonction
}

struct Test {
    int value;
    Test(int v) : value(v) {}
    Test operator+(const Test& other) const { return Test(value + other.value); }
    Test operator*(const Test& other) const { return Test(value * other.value); }
    void operator()() const {
        std::cout << "Appel de l'objet Test" << std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Test& t) {
        os << t.value;
        return os;
    }
};

int main() {
    compareTypes(5, 10); // OK, les types sont identiques
    //compareTypes(5, 3.14); // Erreur de compilation, les types ne sont pas identiques

    utiliser(Derived()); // OK

    Test t(5);
    faireOperations(t); // OK
}