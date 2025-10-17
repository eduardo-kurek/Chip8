#pragma once

#include "instructions/Instruction.h"

class LD_K : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    LD_K(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};