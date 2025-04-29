export module math.advanced_operations;

export int multiply(int a, int b) {
    return a * b;
}

export int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    else {
        //std::cerr << "Erreur : division par zéro\n";
        return 0;
    }
}