#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tmtx;

void thread1() {
    tmtx.lock(); // prend le verrou et ne le lâche pas tout de suite
    std::cout << "[Thread 1] Verrou pris pour 500ms\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    tmtx.unlock();
    std::cout << "[Thread 1] Verrou relache\n";
}

void thread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // attend un peu
    std::cout << "[Thread 2] Essaie de verrouiller...\n";
    if (tmtx.try_lock_for(std::chrono::milliseconds(200))) {
        std::cout << "[Thread 2] Verrou obtenu !\n";
        tmtx.unlock();
    }
    else {
        std::cout << "[Thread 2] Impossible d'obtenir le verrou apres 200ms\n";
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();
}
