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

    auto operator<=>(const Book& other) const {
        if (auto cmp = year <=> other.year; cmp != 0) return cmp;
        return title <=> other.title;
    }

    void display() const {
        std::cout << title << " (" << year << ") - " << author << "\n";
    }
};

const Book& find_oldest(const std::vector<Book>& books) {
    return *std::min_element(books.begin(), books.end());
}

const Book& find_newest(const std::vector<Book>& books) {
    return *std::max_element(books.begin(), books.end());
}

void remove_newer_than(std::vector<Book>& books, int max_year) {
    books.erase(
    std::remove_if(books.begin(), books.end(),
        [&](const Book& b) { return b.year > max_year; })
    );
}

int count_before(const std::vector<Book>& books, const Book& reference) {
    return std::count_if(books.begin(), books.end(),
        [&](const Book& b) { return b < reference; });
}

int main() {
    std::vector<Book> library = {
        {"1984", "George Orwell", 1949},
        {"Brave New World", "Aldous Huxley", 1932},
        {"Animal Farm", "George Orwell", 1945},
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"Fahrenheit 451", "Ray Bradbury", 1953},
        {"1984", "George Orwell", 1950}
    };

    std::sort(library.begin(), library.end());

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
