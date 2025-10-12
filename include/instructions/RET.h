#pragma once

#include "instructions/Instruction.h"

class RET : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    RET(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};