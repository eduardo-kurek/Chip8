#include <cstdint>
#include <array>
#include <fstream>
#include <iostream>
#include "Memory.h"

Memory::Memory(const std::string& romPath){
    std::ifstream file(romPath, std::ios::binary | std::ios::ate);
    
    if(!file.is_open())
        throw std::runtime_error("Failed to open ROM file");

    romSize = file.tellg();
    file.seekg(0, std::ios::beg);

    instCount = romSize / 2;

    if(romSize > Memory::MEMORY_SIZE - Memory::START_ROM)
        throw std::runtime_error("ROM file is too large");

    auto destination_start = mem.begin() + Memory::START_ROM;

    if(!file.read(reinterpret_cast<char*>(&*destination_start), romSize))
        throw std::runtime_error("Failed to read ROM data");

    #ifdef DEBUG
        std::cout << "ROM loaded successfully! (" << romSize << " bytes) at address " <<
        std::hex << Memory::START_ROM << std::dec << std::endl;
    #endif

    const uint8_t digitSprites[80]= {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80, // F
    };

    for(int i = 0; i < 80; i++) {
        mem[0x000 + i] = digitSprites[i];
    }
}

uint16_t Memory::FetchInstruction(uint16_t address){
    if(address >= Memory::MEMORY_SIZE - 1)
        throw std::out_of_range("Memory access out of bounds");

    return (mem[address] << 8) | mem[address + 1];
}

uint8_t Memory::At(uint16_t address){ return mem[address]; }
uint16_t Memory::GetRomSize() const{ return romSize; }
uint16_t Memory::GetInstructionsCount() const{ return romSize / 2; }
