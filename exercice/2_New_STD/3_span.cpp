#include <iostream>
#include <array>
#include <vector>
#include <span>
#include <numeric>   // Pour std::accumulate

int main() {
    // 1. Declaration d’un tableau statique contenant 7 notes
    double notes[]{ 12.5, 15.0, 17.25, 10.0, 13.75, 16.5, 14.0 };

    // 2. Creation d’une vue sur ce tableau

    // 3. Affichage d’informations sur le tableau
    std::cout << "Taille : " <<     << std::endl;
    std::cout << "Premiere note : " <<         << std::endl;
    std::cout << "Derniere note : " <<       << std::endl;

    // 4. Calcul de la somme et de la moyenne

    std::cout << "Somme des notes : " << somme << std::endl;
    std::cout << "Moyenne : " << moyenne << std::endl;

    // 5. Creation et affichage d’une vue contenant les 3 premieres notes


    std::cout << "Premieres notes : ";
    for (double note : debut) {
        std::cout << note << " ";
    }
    std::cout << std::endl;

    // 6. Creation  et affichage d’une vue contenant les 3 dernieres notes

    std::cout << "Dernieres notes : ";
    for (double note : fin) {
        std::cout << note << " ";
    }
    std::cout << std::endl;

    // 7. Creation d’une vue centrale sur les 3 notes du milieu

    std::cout << "Notes du milieu : ";
    for (double note : milieu) {
        std::cout << note << " ";
    }
    std::cout << std::endl;

    // 9. Creation d’un std::array avec les mêmes valeurs


    // 10. Création d’un std::vector avec les mêmes valeurs


    // 11. Création de vues à partir de ces deux conteneurs

    // 12. Affichage de la première note de chaque vue
    std::cout << "Première note du std::array : " << span_array.front() << std::endl;
    std::cout << "Première note du std::vector : " << span_vector.front() << std::endl;

    return 0;
}
