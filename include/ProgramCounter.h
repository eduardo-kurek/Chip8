#pragma once

#include <cstdint>

class ProgramCounter {
    uint16_t address;

public:
    ProgramCounter(uint16_t address = 0x200);
    operator uint16_t() const;
    ProgramCounter& operator=(uint16_t newAddress);
    ProgramCounter& operator++();
    ProgramCounter operator++(int);
};