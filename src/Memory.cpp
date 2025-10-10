#include <cstdint>
#include <array>
#include "Memory.h"

uint8_t Memory::readByte(uint16_t address){
    return m_memory[address];
}

void Memory::writeByte(uint16_t address, uint8_t value){
    m_memory[address] = value;
}