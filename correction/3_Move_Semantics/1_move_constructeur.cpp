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
    Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Constructeur de deplacement: " << name << ", " << age << "\n";
    }

    // Opérateur d'assignation de déplacement
    Person& operator=(Person&& other) noexcept {
        if (this != &other) {
            name = std::move(other.name);
            age = other.age;
            other.age = 0;
            std::cout << "Assignation de deplacement: " << name << ", " << age << "\n";
        }
        return *this;
    }

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
    Person p2 = std::move(p1); 
    p2.display();

    // apres le deplacement, p1 est dans un etat valide mais indefini
    std::cout << "Apres deplacement: \n";
    p1.display();

    // placer un objet temporaire directement dans p3
    Person p3 = Person("Bob", 40);  // Utilisation du constructeur de déplacement directement
    p3.display();  // Affiche Bob, 40

    // deplacer p3 and p4 deja cree
    Person p4("Charlie", 35);
    p4.display();
    p4 = std::move(p3);
    p4.display(); 

    // Ne doit pas appeler deux constructeurs
    Person p5 = createPerson();
    p5.display();

    return 0;
}
