#pragma once

#include <cstdint>
#include <concepts>

class OpCode {
private:
    uint8_t group, x, y, n, nn;
    uint16_t nnn;

public:
    OpCode(uint16_t code);
    uint8_t Group() const;
    uint8_t X() const;
    uint8_t Y() const;
    uint8_t N() const;
    uint8_t NN() const;
    uint16_t NNN() const;
};