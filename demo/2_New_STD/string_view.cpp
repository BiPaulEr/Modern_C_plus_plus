#include <iostream>
#include <string_view>

int main() {
    std::string str = "C++17 is great!";
    std::string_view sv2{ str };    
    
    std::cout << "str " << str << std::endl;
    std::cout << "sv2 " << sv2 << std::endl;
    std::cout << "Sub " << sv2.substr(0, 5) << std::endl;

    std::cout << " Adresse sv2.data() " << static_cast<const void*>(sv2.data()) << " Adresse str.c_str() " << static_cast<const void*>(str.c_str()) << std::endl;
    std::cout << "size sv2 " << sv2.size() << std::endl;
    sv2.remove_prefix(2);
    std::cout << "sv2 after remove_prefix(2) " << sv2 << std::endl;
    sv2.remove_suffix(4);
    std::cout << "sv2 after remove_suffix(4) " << sv2 << std::endl;
    std::cout << "size sv2 after remove_prefix(2) et remove_suffix(4) " << sv2.size() << std::endl;
    std::cout << "empty ? sv2 " << sv2.empty() << std::endl;

    str = "123456789";
    std::cout << "str " << str << std::endl;
    std::cout << "sv2 after str change" << sv2 << std::endl;
    str.clear();
    std::cout << "sv2 after clear " << sv2 << std::endl;

    std::string* new_str = new std::string{ "std::string_view ?" };
	std::string_view sv3{ *new_str };
    std::cout << "sv3 avent delete " << sv3 << std::endl;
    delete new_str;
    std::cout << "sv3 after delete " << sv3 << std::endl;
    return 0;
}
