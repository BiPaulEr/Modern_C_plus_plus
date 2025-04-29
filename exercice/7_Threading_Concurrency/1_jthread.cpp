#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <vector>
#include <mutex>

std::mutex write_to_console;

class ThreadController {
public:
    void add_thread(std::jthread thread) {
        threads.push_back(std::move(thread));
		alive.push_back(true);
    }

    void stop_thread(int id) {
        if (id < 1 || id > threads.size()) {
            std::cout << "ID de thread invalide." << std::endl;
            return;
        }

        if (is_thread_alive(id)) {
            // *************
            // *************
            std::cout << "Thread " << id << " arrete." << std::endl;
        }
        else {
            std::cout << "Thread " << id << " est deja arrete ou termine." << std::endl;
        }
    }

    bool all_threads_stopped() const {
        for (size_t i = 0; i < threads.size(); ++i) {
            if (is_thread_alive(i + 1)) {
                return false;
            }
        }
        return true;
    }

    bool is_thread_alive(int id) const {
        if (id < 1 || id > threads.size()) {
            std::cout << "ID de thread invalide." << std::endl;
            return false;
        }
        return alive[id - 1];
    }

private:
    std::vector<std::jthread> threads;
    std::vector<bool> alive;
};

void task(/*********/) {
    while (true) { // *************
        write_to_console.lock();
        std::cout << "Thread " << id << std::endl;
		write_to_console.unlock();
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    std::cout << "Thread " << id << " arrete." << std::endl;
}

int main() {
    std::cout << "Appuyez sur Enter pour arreter tous les threads." << std::endl;

    ThreadController controller;

    controller.add_thread(std::jthread(task, 1));
    controller.add_thread(std::jthread(task, 2));
    controller.add_thread(std::jthread(task, 3));

    while (!controller.all_threads_stopped()) {
        int id;
        std::cout << "Entrez l'ID du thread a arreter (1, 2, 3) ou -1 pour terminer: ";
        std::cin >> id;

        if (id == -1) break;

        controller.stop_thread(id);
    }

    std::cout << "Programme termine." << std::endl;

    return 0;
}
