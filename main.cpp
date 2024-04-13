#include <iostream>
#include <cassert>

#include "invert_selected_bits.h"

int main()
{
    std::uint8_t data[]{0x0F, 0b10101010, 250};
    
    size_t desired_length = 3;

    uint8_t mask(0xFF);

    invert_selected_bits(data, desired_length, mask);

    assert(data[0] == 0xF0);
    assert(data[1] == 0b01010101);
    assert(data[2] == 5);
    std::cout << "All single mask tests passed.\n";

    // Приводим начальные данные в исходный вид
    invert_selected_bits(data, desired_length, mask);

    std::vector<uint8_t> masks{0x0F, 0xAA, 0xFF};

    invert_selected_bits(data, desired_length, masks);

    assert(data[0] == 0x00);
    assert(data[1] == 0b00000000);
    assert(data[2] == 5);
    std::cout << "All multiple masks tests passed.\n";

    return 0;
}