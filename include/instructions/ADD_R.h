#pragma once

#include "instructions/Instruction.h"

class ADD_R : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    ADD_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};