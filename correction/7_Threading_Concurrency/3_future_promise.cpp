#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <string>
#include <unordered_map>

class Order {
public:
    std::string order_id;
    std::string item_name;
    double price;

    // Constructor to initialize order details
    Order(const std::string& id, const std::string& item, double p)
        : order_id(id), item_name(item), price(p) {
    }

    // Convert Order to string for easy printing
    std::string to_string() const {
        return order_id + ": " + item_name + " - $" + std::to_string(price);
    }
};

// Simulating an inventory with prices for different orders
std::unordered_map<std::string, double> inventory = {
    {"Order123", 50.0},  // Laptop
    {"Order124", 30.0},  // Smartphone
    {"Order125", 20.0},  // Tablet
    {"Order126", 10.0}   // Charger
};

// Step 1: Receive order and return the details
Order receive_order(std::promise<Order>& prom, const Order& order) {
    std::cout << "Order received: " << order.to_string() << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    prom.set_value(order);  // Pass the order to the next step
    return order;  // Return the order details
}

// Step 2: Validate order and calculate price
Order validate_order(std::promise<Order>& prom, std::future<Order>& future_order_details) {
    Order order = future_order_details.get();
    std::cout << "Validating order: " << order.to_string() << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));

    if (inventory.find(order.order_id) != inventory.end()) {
        order.price = inventory[order.order_id];
        prom.set_value(order);
    }
    else {
        order.price = 0.0;
        prom.set_value(order);
    }

    return order;
}

// Step 3: Charge customer and return confirmation
std::string charge_customer(std::future<Order>& futur_order_with_price) {
    Order order = futur_order_with_price.get();  // Wait for validated order
    if (order.price == 0.0) {
        std::cout << "Order is invalid, cannot process payment.\n";
        return "Payment failed: " + order.to_string();
    }
    else {
        std::cout << "Charging customer for: " << order.to_string() << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulate charging time
        std::cout << "Payment successful for: " << order.to_string() << "\n";
        return "Payment successful: " + order.to_string();
    }
}

int main() {
    Order order_details("Order123", "Laptop", 0.0); 

    //Creation for promise and future
    std::promise<Order> order_promise;
    std::future<Order> received_order_future = order_promise.get_future();

    std::promise<Order> validation_promise;
    std::future<Order> validated_order_future = validation_promise.get_future();

    // Create a thread to receive order
    std::thread order_thread(receive_order, std::ref(order_promise), std::ref(order_details));

    // Create a thread to validate order and calculate price
    std::thread validation_thread(validate_order, std::ref(validation_promise), std::ref(received_order_future));

    // Create a thread to receive order to charge customer
    std::thread charging_thread(charge_customer, std::ref(validated_order_future));

    // Wait for all threads to complete and handle the results
    order_thread.join();
    validation_thread.join();
    charging_thread.join();

    return 0;
}
