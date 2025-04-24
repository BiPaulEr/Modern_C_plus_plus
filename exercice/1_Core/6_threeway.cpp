#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <compare>

class Book {
public:
    std::string title;
    std::string author;
    int year;

    Book(std::string t, std::string a, int y) : title(t), author(a), year(y) {}

	//comparaison operators annee puis par titre

    void display() const {
        std::cout << title << " (" << year << ") - " << author << "\n";
    }
};

// find_oldest

//find_newest

//remove_newer_than(std::vector<Book>& books, int max_year)

// count_before(const std::vector<Book>& books, const Book& reference)

int main() {
    std::vector<Book> library = {
        {"1984", "George Orwell", 1949},
        {"Brave New World", "Aldous Huxley", 1932},
        {"Animal Farm", "George Orwell", 1945},
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"Fahrenheit 451", "Ray Bradbury", 1953},
        {"1984", "George Orwell", 1950}
    };

    //trie la list
    //

    std::cout << "Livres tries :\n";
    for (const auto& b : library) b.display();

    std::cout << "\nLe plus vieux livre :\n";
    find_oldest(library).display();

    std::cout << "\nLe plus recent livre :\n";
    find_newest(library).display();

    std::cout << "\n Livres publies avant 1950 : " << count_before(library, { "dummy", "", 1950 }) << "\n";

    std::cout << "\nSuppression des livres apres 1950...\n";
    remove_newer_than(library, 1950);
    for (const auto& b : library) b.display();

    return 0;
}
