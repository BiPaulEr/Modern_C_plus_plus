#include <iostream>
#include <string>
#include <utility> // pour std::move

class A {
    int x = 0;
public:
    A() //?

    ~A() //?
    
    A(const A& other) //?

    A(A&& other)//?

    A& operator=(const A& other)//?

    A& operator=(A&& other)//?
};

class B {
    std::string name;
public:
    B(std::string n)//?

    ~B()//?

    B()//?

    B(const B& other)//?

    B(B&& other)//?

    B& operator=(const B& other)//?

    B& operator=(B&& other)//?
};

class C {
    int* ptr;
public:
    C(int val) //?

    ~C() //?

    C(const C& other)//?

    C(C&& other)//?

    C& operator=(const C& other) //?

    C& operator=(C&& other) //?
};

class D {
    A a;
public:
    D()//?

    ~D()//?
};

class E {
    B b;
    C c;
public:
    E(std::string name, int value) //?

    ~E() //?
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
