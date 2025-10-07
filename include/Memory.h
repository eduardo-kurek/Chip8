#pragma once

#include <cstdint>
#include <array>

class Memory {
private:
    static constexpr uint16_t MEMORY_SIZE = 4096;
    std::array<uint8_t, MEMORY_SIZE> m_memory;

public:
    uint8_t readByte(uint16_t address);

    void writeByte(uint16_t address, uint8_t value);
};