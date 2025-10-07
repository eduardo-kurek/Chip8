#pragma once

#include "instructions/Instruction.h"

class CLS : public Instruction {
    int valor;
public:
    CLS(Chip8& vm, int valor, int registrador) : base(vm){}

    virtual void Execute() override {
    }
};