#include <iostream>
#include <thread>

void travail(const std::string& name) {
    std::cout << "Tache en cours... " << name<< "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Tache terminee. " << name<< "\n";
}

int main() {
    std::jthread t1(travail, std::string("Travail1"));
    t1.join();
    {
        std::jthread t2(travail, std::string("Travail2"));
        std::cout << "Fin du scope.\n";
        //join call automaticly
    }
    std::cout << "Hors du scope.\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Fin du programme.\n";
}

