#pragma once

#include "instructions/Instruction.h"

class LD_N : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    LD_N(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};