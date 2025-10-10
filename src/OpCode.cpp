#include "OpCode.h"

OpCode::OpCode(uint16_t code){
    group = code >> 12;
    x = (code & 0x0F00) >> 8;
    y = (code & 0x00F0) >> 4;
    n = (code & 0x000F);
    nn = (code & 0x00FF);
    nnn = (code & 0x0FFF);
}

uint8_t OpCode::Group() const { return group; }
uint8_t OpCode::X() const { return x; }
uint8_t OpCode::Y() const { return y; }
uint8_t OpCode::N() const { return n; }
uint8_t OpCode::NN() const { return nn; }
uint16_t OpCode::NNN() const { return nnn; }
