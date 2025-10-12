#pragma once

#include "instructions/Instruction.h"

class SNE_N : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    SNE_N(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};