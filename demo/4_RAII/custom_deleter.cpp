#include <iostream>
#include <memory>
#include <cstdio> // Pour FILE*

// Custom deleter pour la fermeture automatique du fichier
void fileDeleter(FILE* file) {
    if (file) {
        std::cout << "Fermeture du fichier automatiquement\n";
        fclose(file);
    }
}

int main() {
    std::shared_ptr<FILE> fichier(fopen("exemple.txt", "w"), fileDeleter);

    if (!fichier) {
        std::cerr << "Erreur lors de l'ouverture du fichier\n";
        return 1;
    }

    std::cout << "ecriture dans le fichier...\n";
    fprintf(fichier.get(), "Bonjour, ceci est un test de fichier avec un smart pointer !\n");

    // Pas besoin d'appeler fclose(), il sera automatiquement fermé par le custom deleter

    return 0;
}
