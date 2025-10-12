#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include "PC.h"
#include <string>

class Context {
public:
    std::array<uint8_t, 16> V{};
    uint16_t I = 0x0000;
    PC programCounter;
    std::array<uint16_t, 16> stack{};
    uint8_t stackPointer = 0x00;
    std::array<uint8_t, (64*32)> DISPLAY{};

    friend std::ostream& operator<<(std::ostream& os, const Context& ctx);
};
