#pragma once

#include "instructions/Instruction.h"

class JMP_V0 : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    JMP_V0(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};