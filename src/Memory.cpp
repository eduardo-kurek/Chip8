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
}

uint16_t Memory::Fetch(uint16_t address){
    if(address >= Memory::MEMORY_SIZE - 1)
        throw std::out_of_range("Memory access out of bounds");

    return (mem[address] << 8) | mem[address + 1];
}

uint16_t Memory::GetRomSize() const{ return romSize; }
uint16_t Memory::GetInstructionsCount() const{ return romSize / 2; }
