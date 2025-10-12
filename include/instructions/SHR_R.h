#pragma once

#include "instructions/Instruction.h"

class SHR_R : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    SHR_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};