#pragma once

#include "instructions/Instruction.h"

class LD_I : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    LD_I(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};