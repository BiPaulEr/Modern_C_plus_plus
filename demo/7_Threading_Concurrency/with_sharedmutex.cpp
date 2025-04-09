#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <chrono>

std::shared_mutex rw_mutex;
int valeur_partagee = 0;

void lecteur(int id) {
    for (int i = 0; i < 10; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        std::shared_lock verrou(rw_mutex);  // verrou partagé pour lecture
        std::cout << "[Lecteur " << id << "] Lit la valeur : " << valeur_partagee << "\n";
        // verrou automatiquement relâché ici
    }
}

void ecrivain(int id) {
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        std::unique_lock verrou(rw_mutex);  // verrou exclusif pour écriture
        std::cout << "[Ecrivain " << id << "] VERROU \n";
        ++valeur_partagee;
        std::cout << "[Ecrivain " << id << "] Incremente a : " << valeur_partagee << "\n";
        // verrou automatiquement relâché ici
    }
}

int main() {
    std::vector<std::thread> threads;

    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(lecteur, i + 1);
    }

    threads.emplace_back(ecrivain, 1);

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
