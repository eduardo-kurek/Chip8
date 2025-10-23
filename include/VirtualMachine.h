#pragma once

#include <array>
#include <cstdint>
#include <iostream>
#include "ProgramCounter.h"     
#include "Display.h"
#include "Memory.h"
#include <string>
#include "Decoder.h"
#include "Timer.h"
#include <functional>

class VirtualMachine {
public:
    using OnInputReceived = std::function<void(uint8_t)>;

private:
    OnInputReceived callback = nullptr;
    bool waitingForInput = false;
    void InputReceived(uint8_t key);

public:
    std::array<uint8_t, 16> V{};
    uint16_t I = 0x0000;
    ProgramCounter pc;
    std::array<uint16_t, 16> stack{};
    uint8_t stackPointer = 0x00;
    std::array<bool, 16> keys;
    Display display;
    Memory mem;
    const Decoder& decoder;
    
    Timer delayTimer;
    Timer soundTimer;
    
    VirtualMachine(std::string romPath);
    void ExecuteNextInstruction();
    void Execute(const OpCode& opCode);
    void PressKey(uint8_t key);
    void ReleaseKey(uint8_t key);
    void WaitForInput(OnInputReceived callback);
    bool NotWaitingForInput() const;
    void DecrementTimers();
    friend std::ostream& operator<<(std::ostream& os, const VirtualMachine& vm);
};
