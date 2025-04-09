#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex rmtx;
std::mutex mtx;

void fonction_rec(const std::string& name, int n) {
    if (n <= 0) return;

    // Verrouille le mutex pour entrer dans la section critique
    std::lock_guard<std::recursive_mutex> verrou(rmtx);
    //std::lock_guard<std::mutex> verrou(mtx);

    std::cout << name << " recursif n=" << n << std::endl;

    // Appel récursif de la fonction
    fonction_rec(name, n - 1);

    // À la fin de la fonction, le verrou est automatiquement relâché
}

int main() {
    std::thread t1(fonction_rec, "T1", 5);
    std::thread t2(fonction_rec, "T2", 3);

    t1.join();
    t2.join();

    return 0;
}
