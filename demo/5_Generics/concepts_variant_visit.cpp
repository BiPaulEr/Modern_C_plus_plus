#include <iostream>
#include <variant>
#include <string>
#include <concepts>


struct Move { int x, y; void draw() const { std::cout << "Move.\n"; } };
struct Attack { std::string target; void draw() const { std::cout << "Attack.\n"; } };
struct Heal { int amount; void draw() const { std::cout << "Heal.\n"; } };

template <typename T>
concept Drawable = requires(T a) {
    { a.draw() } -> std::same_as<void>;
};

template <Drawable T>
void drawAction(const T& action) {
    action.draw();
    std::cout << "Drawing an action.\n";
}

using Action = std::variant<Move, Attack, Heal>;

void dispatch(const Action& action) {
    std::visit([](const auto& a) {
        drawAction(a);
        }, action);
}
int main() {
	Action moveAction = Move{ 1, 2 };
	Action attackAction = Attack{ "enemy" };
	Action healAction = Heal{ 10 };
	dispatch(moveAction);
	dispatch(attackAction);
	dispatch(healAction);
	return 0;
}