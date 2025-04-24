#include <array>
#include <iostream>
#include <numeric>      // std::accumulate
#include <algorithm>    // std::minmax_element
#include <iomanip>      // std::setprecision

int main() {
    // 1. Initialisation de semaine1 avec des températures donnees
    std::array<double, 7> semaine1 = { 14.2, 16.1, 15.8, 17.0, 19.5, 18.3, 17.9 };

    // 2. Affichez la température du troisième jour
    std::cout << "Temperature du 3e jour : " << semaine1.at(2) << "C\n";

    // 3. Taille du tableau
    std::cout << "Taille du tableau : " << semaine1.size() << "\n";

    // 4. Première et dernière température
    std::cout << "Premiere temperature : " << semaine1.front() << "C\n";
    std::cout << "Derniere temperature : " << semaine1.back() << "C\n";

    // 5. Calcul de la somme, moyenne, min, max
    double somme = std::accumulate(semaine1.begin(), semaine1.end(), 0.0);
    double moyenne = somme / semaine1.size();

    auto [min_it, max_it] = std::minmax_element(semaine1.begin(), semaine1.end());

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Somme : " << somme << "C\n";
    std::cout << "Moyenne: " << moyenne << "C\n";
    std::cout << "Temperature minimale : " << *min_it << "C\n";
    std::cout << "Temperature maximale : " << *max_it << "C\n";

    // 6. Creation d'une autre semaine avec 3.0
    std::array<double, 7> semaine2;
    semaine2.fill(3.0);

    // 7. Échange des tableaux
    semaine1.swap(semaine2);

    // 8. Affichage de la nouvelle semaine1
    std::cout << "\nNouvelle semaine1 apres echange :\n";
    for (double t : semaine1) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    // 9. Entrée utilisateur pour remplacer les temperatures de semaine1
    std::cout << "\nEntrez utilisateurs  nouvelles temperatures :\n";
    for (size_t i = 0; i < semaine1.size(); ++i) {
        std::cout << "Jour " << i + 1 << " : ";
        std::cin >> semaine1[i];
    }

    // 10. Affichage final de semaine1 apres saisie utilisateur
    std::cout << "\nTemperatures saisies pour semaine1 :\n";
    for (double t : semaine1) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    return 0;
}
