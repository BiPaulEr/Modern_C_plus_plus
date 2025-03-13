#include <iostream>
#include <chrono>
#include <thread>

int main() {
    // 1. Utilisation des durées (std::chrono::duration)
    std::chrono::seconds duree_seconde(2);
    std::chrono::milliseconds duree_millisecondes(500);
    std::chrono::microseconds duree_microsecondes(1000000); // 1 seconde en µs

    std::cout << "Duree en secondes: " << duree_seconde.count() << " s" << std::endl;
    std::cout << "Duree en millisecondes: " << duree_millisecondes.count() << " ms" << std::endl;
    std::cout << "Duree en microsecondes: " << duree_microsecondes.count() << " micro_s" << std::endl;

    // 2. Utilisation des points spécifiques dans le temps (std::chrono::time_point)
    auto maintenant = std::chrono::system_clock::now();
    std::time_t temps_actuel = std::chrono::system_clock::to_time_t(maintenant);
    std::cout << "Temps actuel (heure systeme): " << std::ctime(&temps_actuel) << std::endl;

    // 3. Mesurer le temps avec différentes horloges
    std::cout << "debut de la mesure du temps..." << std::endl;

    auto start_steady = std::chrono::steady_clock::now();  // Horloge stable
    auto start_high = std::chrono::high_resolution_clock::now();  // Haute précision

    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simuler une tâche

    auto end_steady = std::chrono::steady_clock::now();
    auto end_high = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed_steady = end_steady - start_steady;
    std::chrono::duration<double> elapsed_high = end_high - start_high;

    std::cout << "Temps ecoule (steady_clock) : " << elapsed_steady.count() << " secondes" << std::endl;
    std::cout << "Temps ecoule (high_resolution_clock) : " << elapsed_high.count() << " secondes" << std::endl;

    // 4. Conversion des durées
    std::chrono::seconds une_seconde(1);

    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(une_seconde);
    std::chrono::microseconds us = std::chrono::duration_cast<std::chrono::microseconds>(une_seconde);

    std::cout << "1 seconde en millisecondes: " << ms.count() << " ms" << std::endl;
    std::cout << "1 seconde en microsecondes: " << us.count() << " µs" << std::endl;

    return 0;
}
