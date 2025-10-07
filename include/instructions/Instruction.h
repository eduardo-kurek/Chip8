#pragma once

#include "Chip8.h"

class Instruction {
    Chip8& vm;
public:
    Instruction(Chip8& vm) : vm(vm) {}
    virtual void Execute() = 0;
};