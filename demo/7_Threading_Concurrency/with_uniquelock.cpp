#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::mutex mtx;
std::condition_variable cv;
bool pret = false;


void verrouillage_differé() {
    std::unique_lock<std::mutex> verrou(mtx, std::defer_lock); // pas encore verrouillé
    std::cout << "[defer] Mutex pas encore verrouille\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    verrou.lock();  // verrouillage manuel
    std::cout << "[defer] Mutex verrouille manuellement\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    verrou.unlock();
    std::cout << "[defer] Mutex déverrouille\n";
}

void attendre_condition() {
    std::unique_lock<std::mutex> verrou(mtx);
    std::cout << "[cv] En attente du signal...\n";
    cv.wait(verrou, [] { return pret; }); // attend que `pret` soit vrai
    std::cout << "[cv] Condition recue ! Section critique\n";
}

void emettre_signal() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> verrou(mtx);
        pret = true;
        std::cout << "[cv] Signal envoye\n";
    }
    cv.notify_one();
}

int main() {

    std::thread t1(verrouillage_differé);
    std::thread t2(attendre_condition);
    std::thread t3(emettre_signal);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
