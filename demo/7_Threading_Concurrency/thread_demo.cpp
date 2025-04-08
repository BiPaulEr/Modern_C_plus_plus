#include <iostream>
#include <thread>

void travail(const std::string& name) {
    std::cout << "Tache en cours... " << name<< "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Tache terminee. " << name<< "\n";
}

int main() {
    std::thread t1(travail, std::string("Travail1"));
    t1.join();  // Le main attend 2 secondes
    std::thread t2(travail, std::string("Travail2"));
    t2.join();
    {
        std::thread t3(travail, std::string("Travail3"));
        t3.detach(); //obligatoire
    }
    {
		std::string name = "Travail4";
        std::thread t4(travail, std::ref(name));
        t4.detach(); // name no longer present for Tache Terminee
    }
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Fin du programme.\n";
}

