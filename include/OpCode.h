#pragma once

#include <cstdint>
#include <concepts>

class OpCode {
private:
    uint8_t c, x, y, n, nn;
    uint16_t nnn;
    uint16_t code;

public:
    OpCode(uint16_t code);
    uint8_t C() const;
    uint8_t X() const;
    uint8_t Y() const;
    uint8_t N() const;
    uint8_t NN() const;
    uint16_t NNN() const;
    uint16_t Code() const;
};