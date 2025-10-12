#pragma once

#include "instructions/Instruction.h"

class AND_R : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    AND_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};