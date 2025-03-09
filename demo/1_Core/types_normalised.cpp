#include <iostream>
#include <cstdint> // Pour uint8_t, uint64_t, etc.

int main() {
    uint8_t u8 = 255;       // Un entier sur 8 bits
    uint16_t u16 = 65535;   // Un entier sur 16 bits
    uint32_t u32 = 4294967295;  // Un entier sur 32 bits
    uint64_t u64 = 18446744073709551615U; // Un entier sur 64 bits

    std::cout << "u8: " << +u8 << " size : " << sizeof(u8) << std::endl;
    std::cout << "u16: " << u16 << " size : " << sizeof(u16) << std::endl;
    std::cout << "u32: " << u32 << " size : " << sizeof(u32) << std::endl;
    std::cout << "u64: " << u64 << " size : " << sizeof(u64) << std::endl;

    return 0;
}
