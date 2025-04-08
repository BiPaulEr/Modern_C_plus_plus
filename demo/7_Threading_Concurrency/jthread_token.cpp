#include <iostream>
#include <thread>
#include <chrono>

void travail(std::stop_token stop_token) {
    for (int i = 0; i < 10; ++i) {
        if (stop_token.stop_requested()) {
            std::cout << "Le thread a ete arrete proprement." << std::endl;
            return;
        }
        std::cout << "Travail en cours... " << i << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    std::jthread t(travail); 

    std::this_thread::sleep_for(std::chrono::seconds(5));

    t.request_stop();

    std::cout << "Fin du programme principal." << std::endl;
    return 0;
}
