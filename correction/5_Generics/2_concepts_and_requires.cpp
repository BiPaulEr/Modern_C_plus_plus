#include <concepts>
#include <iostream>

// Creer un concept SimpleNumeric qui est un entier ou un nombre floattant
template<typename T>
concept SimpleNumeric = std::integral<T> || std::floating_point<T>;

template<typename T>
    requires SimpleNumeric<T>
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
template<typename T>
concept RunnableAndCallable = std::derived_from<T, Executable>&& std::invocable<T>;
//Creer le template avec le concept RunnableAndCallable
template<typename T>
    requires RunnableAndCallable<T>
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
    double valeur;
    Operateur(double v) : valeur(v) {}

    Operateur operator-(const Operateur& other) const {
        return Operateur(valeur - other.valeur);
    }

    Operateur operator/(const Operateur& other) const {
        return Operateur(valeur / other.valeur);
    }

    void operator()() const {
        std::cout << "Operation effectuee" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Operateur& op) {
        os << op.valeur;
        return os;
    }
};

// Faire le template associé à CalculableEtAppelable
template<typename T>
    requires CalculableEtAppelable<T>
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
