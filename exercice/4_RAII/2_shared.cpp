#include <iostream>
#include <memory>

class SharedResource {
public:
    SharedResource() { std::cout << "Ressource Partagee allouee\n"; }
    ~SharedResource() { std::cout << "Ressource Partagee liberee\n"; }
    void afficher() const { std::cout << "SharedResource::afficher()\n"; }
};


void test_shared_ptr() {
	// Creation d'un shared_ptr ptr1 avec SharedResource

    std::cout << "References apres ptr1 : " << ptr1.use_count() << "\n";

    {
        // Creation d'un shared_ptr ptr2 par copie
        
        //Afficher count ref   -- combien ici ?
        
        ptr2->afficher();
    }

    //Afficher count ref   -- combien ici ?
    
    ptr1->afficher();

    //if reset -- libere ?
}


void test_shared_ptr_from_raw_pointer() {

    SharedResource* ptr = new SharedResource();

    std::shared_ptr<SharedResource> sptr1(ptr);

    //std::shared_ptr<SharedResource> sptr1(ptr); // POSSIBLE ?

    sptr1->afficher();
}

int main() {
    std::cout << "Test avec shared_ptr :\n";
    test_shared_ptr();

    std::cout << "\nTest d'une mauvaise utilisation de shared_ptr :\n";
    test_shared_ptr_from_raw_pointer();

    std::cout << "\nFin du programme shared_ptr\n";
    return 0;
}
