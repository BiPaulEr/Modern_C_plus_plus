#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string nettoyer_mot(const std::string& mot) {
    std::string propre;
    return propre;
}

int main() {
    const std::string texte = "Le Chat dort. Le chien aboie. Le chat mange. Le chien court. Le chat dort encore.";

    
    std::istringstream iss(texte);
    std::string mot;

    // Remplir le map avec les fr�quences de mots pour l'instant affichage des mots
    while (iss >> mot) {
        std::cout << mot << std::endl;
    }

    // Affichage des fr�quences
    std::cout << "Frequences :\n";
   

    // Trouver le mot le plus fr�quent
    std::string mot_max;
    int max_freq = 0;
  

    std::cout << "\nMot le plus frequent : " << mot_max << " (" << max_freq << " fois)\n";

    // Afficher les mots avec fr�quence > N
    int N = 0;
    std::cout << "\nEntrez un nombre N : ";
    

    std::cout << "Mots apparaissant plus de " << N << " fois :\n";


    std::cout << "\nNombre de buckets : " <<  '\n';
    std::cout << "Facteur de charge : " <<  '\n';

    return 0;
}
