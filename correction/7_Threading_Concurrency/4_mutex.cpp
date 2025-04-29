#include <iostream>
#include <thread>
#include <shared_mutex>
#include <vector>
#include <chrono>
#include <mutex>
#include <syncstream>

std::shared_mutex db_mutex;
std::vector<int> database = { 1, 2, 3, 4, 5 };

void lecture(int id) {
    std::shared_lock<std::shared_mutex> lock(db_mutex);  // plusieurs threads peuvent lire en même temps
    std::string str;
    for (int val : database) {
        str += std::to_string(val) + " ";
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::osyncstream(std::cout) << "[Lecteur " << id << "] Contenu : " << str << std::endl;
    
}

void ecriture(int id, int nouvelle_valeur) {
    std::lock_guard<std::shared_mutex> lock(db_mutex);
    std::osyncstream(std::cout) << "[Ecrivain " << id << "] Ajoute " << nouvelle_valeur << std::endl;
    database.push_back(nouvelle_valeur);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

int main() {

    std::thread threads[] = {
        std::thread(lecture, 1),
        std::thread(ecriture, 1, -99),
        std::thread(lecture, 2),
        std::thread(ecriture, 3, -100),
        std::thread(lecture, 3),
        std::thread(ecriture, 4, -101),
        std::thread(lecture, 4),
        std::thread(ecriture, 5, -102),
        std::thread(lecture, 5),
        std::thread(ecriture, 6, -103),
        std::thread(lecture, 6)
    };

    for (auto& t : threads) t.join();

    return 0;
}
