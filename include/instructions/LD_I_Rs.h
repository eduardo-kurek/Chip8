#pragma once

#include "instructions/Instruction.h"

class LD_I_Rs : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    LD_I_Rs(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};