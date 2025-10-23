#pragma once

#include <array>
#include <cstdint>

class VirtualMachine;

struct Context {
    friend class VirtualMachine;
    std::array<uint8_t, 16> V{};
    uint16_t I = 0x0000;
    PC pc;
    std::array<uint16_t, 16> stack{};
    uint8_t stackPointer = 0x00;
    std::array<bool, 16> keys;
    Display display;
    Memory mem;

};