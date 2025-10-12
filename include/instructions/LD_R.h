#pragma once

#include "instructions/Instruction.h"

class LD_R : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    LD_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};