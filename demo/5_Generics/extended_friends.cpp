#include <iostream>
#include <string>

template<typename T>
class Boite;

template<typename T>
std::ostream& operator<<(std::ostream& os, const Boite<T>& boite);

template<typename T>
class Boite {
private:
    T contenu;

public:
    Boite(T c) : contenu(c) {}

    friend std::ostream& operator<< <>(std::ostream& os, const Boite<T>& boite);
	friend void afficherContenu<>(const Boite<T>& boite);
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Boite<T>& boite) {
    os << "Contenu de la boite : " << boite.contenu;
    return os;
}

template<typename T>
void afficherContenu(const Boite<T>& boite) {
    std::cout << "[Afficher] " << boite.contenu << std::endl;
}

int main() {
    Boite<int> boiteInt(42);
    Boite<std::string> boiteString("Bonjour");

    std::cout << boiteInt << std::endl;
    std::cout << boiteString << std::endl;

    afficherContenu(boiteInt);
    afficherContenu(boiteString);
}
