#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, world!";

    // starts_with: V�rifie si la cha�ne commence par "Hello"
    if (str.starts_with("Hello")) {
        std::cout << "La chaine commence par 'Hello'" << std::endl;
    }

    // ends_with: V�rifie si la cha�ne se termine par "world!"
    if (str.ends_with("world!")) {
        std::cout << "La chaine se termine par 'world!'" << std::endl;
    }

    // replace: Remplace "world" par "C++" dans la cha�ne
    str.replace(7, 5, "C++");
    std::cout << "Apr�s remplacement: " << str << std::endl;  // Affiche : Hello, C++!

    // copy: Copie les 5 premiers caract�res dans un buffer
    char buffer[6];
    str.copy(buffer, 5, 0);
    buffer[5] = '\0';  // Terminer la cha�ne par un caract�re nul
    std::cout << "Contenu du buffer : " << buffer << std::endl;  // Affiche : Hello
        return 0;
}
