#include <iostream>
#include <variant>
#include <string>

struct Car {
    void start() const { std::cout << "Car is starting.\n"; }
    void stop() const { std::cout << "Car is stopping.\n"; }
};

struct Bike {
    void start() const { std::cout << "Bike is starting.\n"; }
    void stop() const { std::cout << "Bike is stopping.\n"; }
};

struct Boat {
    void start() const { std::cout << "Boat is starting.\n"; }
    void stop() const { std::cout << "Boat is stopping.\n"; }
};

// Create a concept StartStopable for Bike / Boat / Car 
template <typename T>
concept StartStopable = requires(T a) {
    { a.start() } -> std::same_as<void>;
    { a.stop() } -> std::same_as<void>;
};

// Create a variant Vehicule
using Vehicle = std::variant<Car, Bike, Boat>;

//Complete the template startVehicle

void startVehicle(const T& vehicle) {

}

//Complete the template stopVehicle

void stopVehicle(const T& vehicle) {

}

// complete the function to start and stop the vehicule
void test(const Vehicle& vehicle) {

}

int main() {
    Vehicle car = Car{};
    Vehicle bike = Bike{};
    Vehicle boat = Boat{};

    test(car);
    test(bike);
    test(boat);
    return 0;
}
