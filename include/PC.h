#pragma once

#include <cstdint>

class PC {
    uint16_t address = 0x200;

public:
    uint16_t GetAddress() const;
    void SetAddress(uint16_t newAddress);
    void IncrementAddress();
};