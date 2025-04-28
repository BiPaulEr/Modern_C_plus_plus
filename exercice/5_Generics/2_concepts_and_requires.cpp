#include <concepts>
#include <iostream>

// Creer un concept SimpleNumeric qui est un entier ou un nombre floattant

// Creer le template associe

void doubler(T valeur) {
    std::cout << "Valeur doublee : " << valeur * 2 << std::endl;
}

struct Executable {
    void run() const {
        std::cout << "Execution de base" << std::endl;
    }
};

struct AdvancedExecutable : Executable {
    void operator()() const {
        std::cout << "AdvancedExecutable lance" << std::endl;
    }
};

// creer un concept RunnableAndCallable : doit être une Executable + invocable

//Creer le template avec le concept RunnableAndCallable

void lancer(T executable) {
    executable();
    executable.run();
}

// Concept : doit supporter soustraction et division, et être appelable
template<typename T>
concept CalculableEtAppelable = requires(T x) {
    { x - x } -> std::same_as<T>;
    { x / x } -> std::same_as<T>;
    { x() } -> std::same_as<void>;
};

// Une classe Operateur qui respecte CalculableEtAppelable
struct Operateur {
    friend std::ostream& operator<<(std::ostream& os, const Operateur& op) {
        os << op.valeur;
        return os;
    }
};

// Faire le template associé à CalculableEtAppelable


void faireCalculs(T op) {
    std::cout << "Soustraction : " << op - op << std::endl;
    std::cout << "Division : " << op / op << std::endl;
    op();
}

int main() {
    doubler(8);
    doubler(2.5);

    AdvancedExecutable ae;
    lancer(ae);

    Operateur o(10);
    faireCalculs(o);
}
