#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include "PC.h"     
#include "Display.h"
#include "Memory.h"
#include <string>
#include "Decoder.h"

class VirtualMachine {

public:
    std::array<uint8_t, 16> V{};
    uint16_t I = 0x0000;
    PC programCounter;
    std::array<uint16_t, 16> stack{};
    uint8_t stackPointer = 0x00;
    std::array<bool, 16> keys;
    Display display;
    Memory mem;
    const Decoder& decoder;

    VirtualMachine(std::string romPath) : mem(romPath), decoder(Decoder::Instance()) {};
    void ExecuteNextInstruction();
    void Execute(const OpCode& opCode);
    void PressKey(uint8_t key);
    void ReleaseKey(uint8_t key);
    friend std::ostream& operator<<(std::ostream& os, const VirtualMachine& vm);
};
