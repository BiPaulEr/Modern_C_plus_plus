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
template <StartStopable T>
void startVehicle(const T& vehicle) {
    vehicle.start();
    std::cout << "Vehicle started.\n";
}

//Complete the template stopVehicle
template <StartStopable T>
void stopVehicle(const T& vehicle) {
    vehicle.stop();
    std::cout << "Vehicle stopped.\n";
}

// complete the function to start and stop the vehicule
void test(const Vehicle& vehicle) {
    std::visit([](const auto& v) {
        startVehicle(v);
        stopVehicle(v);
        }, vehicle);
}

int main() {
    // Create vehicles
    Vehicle car = Car{};
    Vehicle bike = Bike{};
    Vehicle boat = Boat{};

    // Dispatch the vehicles to start and stop
    test(car);
    test(bike);
    test(boat);

    return 0;
}
