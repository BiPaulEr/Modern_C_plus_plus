#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";

    // starts_with: Vérifie si la chaîne commence par "Hello"
    if (str.starts_with("Hello")) {
        std::cout << "La chaine commence par 'Hello'" << std::endl;
    }

    // ends_with: Vérifie si la chaîne se termine par "world!"
    if (str.ends_with("world!")) {
        std::cout << "La chaine se termine par 'world!'" << std::endl;
    }

    // replace: Remplace "world" par "C++" dans la chaîne
    str.replace(7, 5, "C++");
    std::cout << "Après remplacement: " << str << std::endl;  // Affiche : Hello, C++!

    // copy: Copie les 5 premiers caractères dans un buffer
    char buffer[6];
    str.copy(buffer, 5, 0);
    buffer[5] = '\0';  // Terminer la chaîne par un caractère nul
    std::cout << "Contenu du buffer : " << buffer << std::endl;  // Affiche : Hello
        return 0;
}
