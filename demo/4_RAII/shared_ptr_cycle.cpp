#include <iostream>
#include <memory>

class B; // Forward declaration

class A {
public:
    std::shared_ptr<B> pointer;
    ~A() {
        std::cout << "A was destroyed" << std::endl;
    }
};

class B {
public:
    std::shared_ptr<A> pointer;
    ~B() {
        std::cout << "B was destroyed" << std::endl;
    }
};

int main() {
    
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    std::cout << "a use count : " << a.use_count() << std::endl;
    std::cout << "b use count : " << b.use_count() << std::endl;

    std::cout << "Copy pointeur to each other" << std::endl;
    a->pointer = b;
    b->pointer = a;
	std::cout << "a use count : " << a.use_count() << std::endl;
	std::cout << "b use count : " << b.use_count() << std::endl;

    std::cout << "Simulation sortie du contexte"  << std::endl;
    a.reset();
    std::cout << "a use count after a reset : " << b->pointer.use_count() << std::endl;

    std::cout << "Sortie du programme" << std::endl;
    
    return 0;
}
