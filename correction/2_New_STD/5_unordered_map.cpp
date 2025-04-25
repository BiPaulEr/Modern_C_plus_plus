#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cctype>

std::string nettoyer_mot(const std::string& mot) {
    std::string propre;
    for (char c : mot) {
        if (std::isalpha(c)) {
            propre += std::tolower(c);
        }
    }
    return propre;
}

int main() {
    const std::string texte = "Le chat dort. Le chien aboie. Le chat mange. Le chien court. Le chat dort encore.";

    std::unordered_map<std::string, int> frequence;
    std::istringstream iss(texte);
    std::string mot;

    // Remplir le map avec les fréquences de mots
    while (iss >> mot) {
        std::string mot_nettoye = nettoyer_mot(mot);
        if (!mot_nettoye.empty()) {
            frequence[mot_nettoye]++;
        }
    }

    // Affichage des fréquences
    std::cout << "Frequences :\n";
    for (const auto& pair : frequence) {
        std::cout << pair.first << " : " << pair.second << '\n';
    }

    // Trouver le mot le plus fréquent
    std::string mot_max;
    int max_freq = 0;
    for (const auto& [cle, valeur] : frequence) {
        if (valeur > max_freq) {
            max_freq = valeur;
            mot_max = cle;
        }
    }

    std::cout << "\nMot le plus frequent : " << mot_max << " (" << max_freq << " fois)\n";

    // Afficher les mots avec fréquence > N
    int N;
    std::cout << "\nEntrez un nombre N : ";
    std::cin >> N;

    std::cout << "Mots apparaissant plus de " << N << " fois :\n";
    for (const auto& [cle, valeur] : frequence) {
        if (valeur > N) {
            std::cout << "- " << cle << '\n';
        }
    }

    std::cout << "\nNombre de buckets : " << frequence.bucket_count() << '\n';
    std::cout << "Facteur de charge : " << frequence.load_factor() << '\n';

    return 0;
}
