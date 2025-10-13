#pragma once

#include <cstdint>
#include <array>
#include <string>

class Memory {
private:
    static constexpr uint16_t MEMORY_SIZE = 4096;
    static constexpr uint16_t START_ROM = 0x200;
    std::array<uint8_t, MEMORY_SIZE> mem;
    std::streamsize romSize;
    uint16_t instCount;

public:
    Memory(const std::string& romPath);
    uint16_t FetchInstruction(uint16_t address);
    uint8_t At(uint16_t address);
    uint16_t GetRomSize() const;
    uint16_t GetInstructionsCount() const;
};