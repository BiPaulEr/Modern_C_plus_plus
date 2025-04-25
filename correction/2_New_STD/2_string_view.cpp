#include <iostream>
#include <string>
#include <string_view>
#include <compare>

int main() {
    // 1. Declarer une chaine classique contenant une phrase
    std::string phrase_str = "Les pommes sont delicieuses";

    // 2. Creer une vue sur cette chaine
    std::string_view phrase = phrase_str;
    std::cout << "View : : " << phrase << std::endl;

    // 3. Afficher la premiere lettre de la phrase
    std::cout << "Premiere lettre : " << phrase.front() << std::endl;

    // 4. Afficher la taille totale de la phrase
    std::cout << "Taille : " << phrase.size() << std::endl;

    // 5. Extraire un mot de la phrase a partir de sa position et de sa longueur
    std::string_view mot = phrase.substr(4, 6); // "pommes"
    std::cout << "Mot extrait : " << mot << std::endl;

    // 6. Remplacer un mot dans la chaine de base par un autre mot
    std::size_t pos = phrase_str.find("pommes");
    if (pos != std::string::npos) {
        phrase_str.replace(pos, 6, "bananes");
    }

    // 7. Affichage de la view
    std::cout << "View : : " << phrase << std::endl;

    // 8. Creer une autre phrase a comparer
    std::string_view phrase2 = "Les bananes sont exquises";

    // 9. Comparer <=> les deux phrases et afficher un message selon le resultat
    auto resultat = phrase <=> phrase2;
    if (resultat == 0) {
        std::cout << "Les deux phrases sont identiques." << std::endl;
    }
    else if (resultat < 0) {
        std::cout << "La premiere phrase est plus petite." << std::endl;
    }
    else {
        std::cout << "La premiere phrase est plus grande." << std::endl;
    }

    return 0;
}
