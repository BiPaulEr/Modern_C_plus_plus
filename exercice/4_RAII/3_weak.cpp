#include <iostream>
#include <memory>

class B;

class A {
public:
    std::shared_ptr<B> b_ptr;
    ~A() {
        std::cout << "A detruit\n";
    }
};

class B {
public:
    std::weak_ptr<A> a_ptr;
    ~B() {
        std::cout << "B detruit\n";
    }
};
// corrige pour eviter le probleme de dependance circulaire
void test_circulaire_shared() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->b_ptr = b;
    b->a_ptr = a;
    std::cout << "Fin de test_circulaire_shared\n";
}

void test_weak_ptr() {
	//creer un shared_ptr sp de int avec 77
    
	//creer un weak_ptr wp a partir de sp
    

	//afficher le nombre ref depuis sp
    
    //afficher wp expired ? 
    

    if (auto locked = wp.lock()) {
		// Afficher le int depuis locked
        std::cout << "Acces via weak_ptr.lock() : " <<  << "\n";
        // Afficher ref count --- combien ?
        std::cout << "Use count (sp) : " <<  << "\n";
    }

    sp.reset();
    std::cout << "Apres reset du shared_ptr\n";

    //afficher wp expired ? 
    
}

int main() {
    test_circulaire_shared();
    test_weak_ptr();
    return 0;
}
