#include <iostream>
#include <thread>
#include <syncstream>
#include <chrono>

void log_safely(int id) {
    for (int i = 0; i < 3; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(50 * id));
        std::osyncstream(std::cout) << "[Thread " << id << "] Message " << i << "\n";
    }
}

int main() {
    std::thread t1(log_safely, 1);
    std::thread t2(log_safely, 2);
    std::thread t3(log_safely, 3);

    t1.join();
    t2.join();
    t3.join();
}
