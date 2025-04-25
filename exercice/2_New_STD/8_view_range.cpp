#include <iostream>
#include <vector>
#include <string>
#include <ranges>
#include <algorithm>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 14}, {"Bob", 17}, {"Charlie", 9},
        {"Diana", 8}, {"Eve", 13}, {"Frank", 15}
    };

    std::cout << " Liste initiale des etudiants:\n";
    for (const auto& s : students) {
        std::cout << "- " << s.name << ": " << s.score << "\n";
    }

    // Vue : premiers 3 étudiants du tableau initial
    std::cout << "\nLes 3 premiers etudiants :\n";
    for () {
        std::cout << "- " << s.name << ": " << s.score << "\n";
    }

    // Vue : etudiants sauf les 2 premiers
    std::cout << "\nEtudiants sauf les 2 premiers :\n";
    for () {
        std::cout << "- " << s.name << ": " << s.score << "\n";
    }

	// Faire un view avec un bonus de 2 points aux étudiants ayant un score >= 14
    

    // Afficher la view
    std::cout << "Etudiants recompenses :\n";
    for (const auto& s : rewarded_view) {
        std::cout << "- " << s.name << ": " << s.score << "\n";
    }

    // tri par score decroissant de students
    

    std::cout << "\Etudiants tries par score decroissant:\n";
    for (const auto& s : students) {
        std::cout << "- " << s.name << ": " << s.score << "\n";
    }

	// view transforme en std::string " name ( score ) " des étudiants récompensés
    

    std::cout << "\n Resume lisible des etudiants recompenses:\n";
    for (const auto& line : summary_view) {
        std::cout << line << "\n";
    }

	// Afficher le meilleur etudiant
    
    std::cout << "\n Meilleur etudiant :\n";
    std::cout << max.name << " " << max.score << "\n";
    
    return 0;
}
