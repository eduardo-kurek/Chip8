#pragma once

#include "instructions/Instruction.h"

class JMP : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    JMP(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};