#include <iostream>
#include <thread>
#include <future>
#include <chrono>

void travail(std::promise<int> promesse) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    promesse.set_value(42);
}

int main() {
    std::promise<int> promesse;
    std::future<int> futur = promesse.get_future();

    std::thread t(travail, std::move(promesse));

    std::cout << "En attente du resultat...\n";
    int resultat = futur.get(); // Attend la valeur (bloquant)
    std::cout << "Resultat reçu : " << resultat << "\n";

    t.join();
    return 0;
}
