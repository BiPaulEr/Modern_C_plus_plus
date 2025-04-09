#include <iostream>
#include <thread>

class Singleton {
public:
    static Singleton& instance() {
        std::call_once(init_flag, []() {
            singleton_instance = new Singleton();
            });
        return *singleton_instance;
    }

private:
    Singleton() { std::cout << "Singleton construit.\n"; }
    static Singleton* singleton_instance;
    static std::once_flag init_flag;
};
Singleton* Singleton::singleton_instance = nullptr;
std::once_flag Singleton::init_flag;

int main() {
    std::thread t1([] { Singleton::instance(); });
    std::thread t2([] { Singleton::instance(); });
    std::thread t3([] { Singleton::instance(); });

    t1.join();
    t2.join();
    t3.join();

    return 0;
}
