#pragma once

#include "instructions/Instruction.h"

class LD_B : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    LD_B(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};