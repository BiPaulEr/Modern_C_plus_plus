#include <iostream>
#include <thread>
#include <latch>
#include <chrono>

std::latch ready_latch(4);

void participant(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(100 * id));
    std::cout << "Participant " << id << " est pret.\n";
    ready_latch.count_down();
    ready_latch.wait();
    std::cout << "Participant " << id << " commence la course !\n";
}

int main() {
    std::thread t1(participant, 1);
    std::thread t2(participant, 2);
    std::thread t3(participant, 3);

    std::this_thread::sleep_for(std::chrono::milliseconds(250));
    std::cout << "Lancement par larbitre...\n";
    ready_latch.count_down();

    t1.join();
    t2.join();
    t3.join();
}
