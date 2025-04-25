#include <iostream>
#include <memory>

class Ressource {
public:
    Ressource(int value) : data(value) {
        std::cout << "Ressource(" << data << ") allouee\n";
    }
    ~Ressource() {
        std::cout << "Ressource(" << data << ") liberee\n";
    }
    void afficher() const {
        std::cout << "Valeur de la ressource : " << data << "\n";
    }

private:
    int data;
};


void test_unique_ptr() {
    // Creer ptr1 avec Ressource 10
    
    ptr1->afficher();

	//EST CE POSSIBLE DE FAIRE UNE COPIE ?
    // std::unique_ptr<Ressource> ptr2 = ptr1;
}


void test_move_semantics() {
    // Creer ptr1 avec Ressource 20
    

    // Transferer la propriete de ptr1 vers ptr3
    
    if (!ptr1) {
        std::cout << "ptr1 est maintenant nul apres le move\n";
    }
    ptr3->afficher();

    // Si ptr3->reset()  destruction ?
}

// Méthode pour tester l'effet de sortir du scope
void test_scope_behavior() {
    {
        std::unique_ptr<Ressource> ptr_in_scope = std::make_unique<Ressource>(30);
        ptr_in_scope->afficher();
        
    }  //destruction ici ?
    
} //destruction ici ?

int main() {
    std::cout << "Test avec unique_ptr :\n";
    test_unique_ptr();

    std::cout << "\nTest de transfert de propriete :\n";
    test_move_semantics();

    std::cout << "\nTest de comportement a la sortie du scope :\n";
    test_scope_behavior();

    return 0;
}
