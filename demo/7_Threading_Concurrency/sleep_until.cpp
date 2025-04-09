#include <iostream>
#include <thread>
#include <chrono>

void tacheAvecSleepUntil() {
    for (int i = 1; i <= 5; ++i) {
        auto debut = std::chrono::steady_clock::now();
        auto heureCible = debut + std::chrono::seconds(i);
        std::cout << "[sleep_until] evenement " << i << " -> " << i << " secondes\n";
        std::this_thread::sleep_until(heureCible);
        std::cout << "FIN [sleep_until]\n\n";
    }
}

int main() {
    std::thread t(tacheAvecSleepUntil);
    t.join();
    std::cout << "Fin du programme avec sleep_until.\n";
}
