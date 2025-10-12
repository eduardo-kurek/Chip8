#pragma once

#include "instructions/Instruction.h"

class SHL_R : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    SHL_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};