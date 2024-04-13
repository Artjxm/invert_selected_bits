#ifndef INVERT_SELECTED_BITS_H
#define INVERT_SELECTED_BITS_H

#include <vector>
#include <stdexcept>
#include <bitset>

// Реализация функции с общей маской для каждого байта
static void invert_selected_bits(uint8_t *memory_ptr, size_t length_bytes, uint8_t mask)
{
    if (!memory_ptr)
        throw std::invalid_argument("Error: invalid memory pointer value.\n");
    if (!length_bytes)
        throw std::invalid_argument("Error: invalid length of memory.\n");

    for (size_t i(0); i < length_bytes; ++i)
    {
        *memory_ptr++ ^= mask;
    }
}

// Реализация функции с собственной маской для каждого байта
static void invert_selected_bits(uint8_t *memory_ptr, size_t length_bytes, std::vector<uint8_t> mask)
{
    if (!memory_ptr)
        throw std::invalid_argument("Error: invalid memory pointer value.\n");
    if (!length_bytes)
        throw std::invalid_argument("Error: invalid length of memory.\n");
    if (!mask.size()) {
        throw std::invalid_argument("Error: invalid mask vector.\n");
    }

    for (size_t i(0); i < length_bytes; ++i) {
        *memory_ptr++ ^= mask.at(i)++;
    }
}



#endif