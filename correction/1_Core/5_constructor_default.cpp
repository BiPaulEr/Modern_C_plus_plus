#include <iostream>
#include <string>
#include <utility> // pour std::move

class A {
    int x = 0;
public:
    A() = default;

    ~A() = default;
    
    A(const A& other) = default;

    A(A&& other) = default;

    A& operator=(const A& other) = default;

    A& operator=(A&& other) = default;
};

class B {
    std::string name;
public:
    B(std::string n) : name(std::move(n)) {}

    ~B() = default;

    B() = delete;

    B(const B& other) = default;

    B(B&& other) noexcept = default;

    B& operator=(const B& other) = default;

    B& operator=(B&& other) noexcept = default;
};

class C {
    int* ptr;
public:
    C(int val) {
        ptr = new int(val);
        std::cout << "Construction C avec " << *ptr << "\n";
    }

    ~C() {
        if (ptr) {
            std::cout << "Destruction C, delete " << *ptr << "\n";
            delete ptr;
        }
    }

    C(const C& other) : ptr(new int(*other.ptr)) {
        std::cout << "Constructeur de copie C\n";
    }

    C(C&& other) noexcept : ptr(other.ptr) {
        std::cout << "Constructeur de déplacement C\n";
        other.ptr = nullptr;
    }

    C& operator=(const C& other) {
        std::cout << "Affectation par copie C\n";
        if (this != &other) {
            delete ptr;
            ptr = new int(*other.ptr);
        }
        return *this;
    }

    C& operator=(C&& other) noexcept {
        std::cout << "Affectation par déplacement C\n";
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
};

class D {
    A a;
public:
    D() = default;

    ~D() = default;
};

class E {
    B b;
    C c;
public:
    E(std::string name, int value) : b(std::move(name)), c(value) {}

    ~E() = default;
};

int main() {
    std::cout << "Creation de A:\n";
    A a1; 
    A a2 = a1;
    A a3 = std::move(a1);
    a2 = a3;
    a3 = a2;

    std::cout << "\nCreation de B:\n";
    B b1("Hello");
    // B b2;        // Erreur !
    B b2 = b1;
    B b3 = std::move(b1); 
    b2 = b3;
    b3 = std::move(b2);

    std::cout << "\nCreation de C\n";
    C c1(42);
    C c2 = c1;
    C c3 = std::move(c1);
    c2 = c3;
    c3 = std::move(c2);

    std::cout << "\nCreation de D:\n";
    D d1;

    std::cout << "\nCreation de E:\n";
    E e1("Alice", 99);

    std::cout << "Fin du programme\n";
    return 0;
}
