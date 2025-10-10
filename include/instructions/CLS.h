#pragma once

#include "instructions/Instruction.h"

class CLS : public Instruction {
public:
    CLS(const OpCode& opcode) : Instruction(opCode) {};
    void Execute(Chip8& vm) const override;
};