#include <iostream>
#include <string>
#include <utility>  // Pour std::move

class Person {
private:
    std::string name;
    int age;

public:
    // Constructeur classique
    Person(std::string n, int a) : name(std::move(n)), age(a) {
        std::cout << "Constructeur: " << name << ", " << age << "\n";
    }

    // Constructeur de deplacement
    

    // Opérateur d'assignation de déplacement
    

    // Affichage des informations de la personne
    void display() const {
        std::cout << "Nom: " << name << ", age: " << age << "\n";
    }
};

Person createPerson() {
    return Person("John", 30);
}

int main() {
    // Creation un objet p1 avec un constructeur classique
    Person p1("Alice", 25);
    p1.display();

    // Deplacer p1 dans un autre objet p2

    p2.display();

    // apres le deplacement, p1 est dans un etat valide mais indefini
    std::cout << "Apres deplacement: \n";
    p1.display();

    // Creation un objet p3 avec un constructeur classique
    Person p3 = Person("Bob", 40); 
    p3.display(); 

    // deplacer p3 and p4 deja cree
    Person p4("Charlie", 35);
	p.display();
    
    p4.display();

    // Ne doit pas appeler deux constructeurs
    Person p5 = createPerson();
    p5.display();

    return 0;
}
