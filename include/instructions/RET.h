#pragma once

#include "instructions/Instruction.h"

class RET : public Instruction {
public:
    RET(const OpCode& opcode) : Instruction(opCode) {};
    void Execute(Chip8& vm) const override;
};