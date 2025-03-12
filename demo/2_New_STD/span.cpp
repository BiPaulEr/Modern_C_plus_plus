#include <iostream>
#include <span>  // Nécessaire pour std::span
#include <vector>

void print_span(std::span<int> sp) {
    std::cout << "Contenu du span : ";
    for (int i : sp) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Tableau statique
    int arr[] = { 1, 2, 3, 4, 5 };

    std::span<int> span1(arr);

    print_span(span1);  // Affiche: 1 2 3 4 5

    std::cout << "Premier element (via operator[]): " << span1[0] << std::endl;  // Affiche: 1
    std::cout << "Troisième element (via operator[]): " << span1[2] << std::endl;  // Affiche: 3
    std::cout << "Premier element (via front()): " << span1.front() << std::endl;  // Affiche: 1
    std::cout << "Dernier element (via back()): " << span1.back() << std::endl;  // Affiche: 5

    std::span<int> span2(arr + 1, 3);  // Prend les éléments à partir de arr[1] et contient 3 éléments
    print_span(span2);  // Affiche: 2 3 4

    std::span<int> subspan = span1.subspan(2, 2);  // À partir de l'index 2, prendre 2 éléments
    print_span(subspan);  // Affiche: 3 4

    std::vector<int> vec = { 10, 20, 30, 40, 50 };
    std::span<int> span3(vec);  // Crée un span à partir du vector
    print_span(span3);  // Affiche: 10 20 30 40 50

    return 0;
}
