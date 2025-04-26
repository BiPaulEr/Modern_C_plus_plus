#include <iostream>
#include <type_traits>
#include <string>
#include <vector>

// Pour les types ENTIERS
template <typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
checkType(const T& value) {
    std::cout << "[ENTIER] Valeur = " << value
        << " | Taille = " << sizeof(T) << " octets\n";
    return value;
}

// Pour les types FLOTTANTS
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
checkType(const T& value) {
    std::cout << "[FLOTTANT] Valeur = " << value
        << " | Precision = " << (sizeof(T) * 8) << " bits\n";
}

// Pour le type STRING
template <typename T>
typename std::enable_if<std::is_same<T, std::string>::value, float>::type
checkType(const T& value) {
    std::cout << "[CHAINE] Contenu = \"" << value
        << "\" | Longueur = " << value.size() << "\n";
    return 4.4;
}

//Pour les POINTEURS
template <typename T>
typename std::enable_if<std::is_pointer<T>::value, void>::type
checkType(const T& ptr) {
    if (ptr) {
        std::cout << "[POINTEUR] Adresse = " << static_cast<const void*>(ptr)
            << " | Valeur pointee = " << *ptr << "\n";
    }
    else {
        std::cout << "[POINTEUR NULL] Aucun pointeur valide.\n";
    }
}

int main() {
    std::cout << "\n--- Test avec des entiers ---\n";
    checkType(42);              // int
    checkType(12345678901234LL);// long long

    std::cout << "\n--- Test avec des flottants ---\n";
    checkType(3.1415);           // double
    checkType(2.71828f);         // float

    std::cout << "\n--- Test avec une string ---\n";
    checkType(std::string("Hello, world!"));

    std::cout << "\n--- Test avec des pointeurs ---\n";
    int a = 10;
    checkType(&a);               // pointeur sur int
    int* null_ptr = nullptr;
    checkType(null_ptr);         // pointeur nul

    // Erreur de compilation si decommente :
    /*
    struct CustomType {};
    CustomType myObject;
    checkType(myObject); // Aucun checkType() ne matche : erreur
    */

    return 0;
}
