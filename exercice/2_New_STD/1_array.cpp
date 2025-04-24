#include <array>
#include <iostream>
#include <numeric>      // std::accumulate
#include <algorithm>    // std::minmax_element


int main() {
    // 1. Initialisation de semaine1 avec des températures donnees
    std::array<double, 7> semaine1 = { 14.2, 16.1, 15.8, 17.0, 19.5, 18.3, 17.9 };

    // 2. Affichez la température du troisième jour
    

    // 3. Taille du tableau
    

    // 4. Première et dernière température
    

    // 5. Calcul de la somme, moyenne, min, max
    
    std::cout << "Somme : " << somme << "C\n";
    std::cout << "Moyenne: " << moyenne << "C\n";
    std::cout << "Temperature minimale : " << *min_it << "C\n";
    std::cout << "Temperature maximale : " << *max_it << "C\n";

    // 6. Creation d'une autre semaine avec 3.0
    

    // 7. Échange des tableaux
    

    // 8. Affichage de la nouvelle semaine1
    std::cout << "\nNouvelle semaine1 apres echange :\n";
    for (double t : semaine1) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    // 9. Entrée utilisateur pour remplacer les temperatures de semaine1
    std::cout << "\nEntrez utilisateurs  nouvelles temperatures :\n";
    

    // 10. Affichage final de semaine1 apres saisie utilisateur
    std::cout << "\nTemperatures saisies pour semaine1 :\n";
    for (double t : semaine1) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    return 0;
}
