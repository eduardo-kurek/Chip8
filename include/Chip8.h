#pragma once

#include <array>
#include <cstdint>
#include "PC.h"
#include "Memory.h"

class Chip8{
    private:
        Memory RAM;

        std::array<uint8_t, 16> m_Vx{}; 
        uint16_t m_I = 0x0000;          
        PC m_Pc;                        

        std::array<uint16_t, 16> m_stack{};
        uint8_t stackPointer = 0x00;

        std::array<uint8_t, (64*32)> DISPLAY;

        uint16_t fetchOpCode();
        void execute(uint16_t opCode);
        
    public:

        Chip8();
        bool loadROM(const char* filepath);
        void run();
};