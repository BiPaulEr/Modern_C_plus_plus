#include <iostream>
#include <string>
#include <string_view>
#include <compare>

int main() {
    // 1. Declarer une chaine classique contenant une phrase
    std::string phrase_str = "Les pommes sont delicieuses";

    // 2. Creer une vue sur cette chaine
    
    std::cout << "View : " << phrase << std::endl;

    // 3. Afficher la premiere lettre de la phrase
   

    // 4. Afficher la taille totale de la phrase
    

    // 5. Extraire "pommes" de la phrase a partir de sa position et de sa longueur
    
    std::cout << "Mot extrait : " << mot << std::endl;

    // 6. Remplacer un mot dans la chaine de base par un autre mot
     

    // 7. Affichage de la view
    std::cout << "View : : " << phrase << std::endl;

    // 8. Creer une autre phrase a comparer
    std::string_view phrase2 = "Les bananes sont exquises";

    // 9. Comparer <=> les deux phrases et afficher un message selon le resultat
    
    std::cout << "Les deux phrases sont identiques." << std::endl;
    
   
   std::cout << "La premiere phrase est plus petite." << std::endl;
   
   std::cout << "La premiere phrase est plus grande." << std::endl;
    

    return 0;
}
