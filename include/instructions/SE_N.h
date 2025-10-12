#pragma once

#include "instructions/Instruction.h"

class SE_N : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SE_N(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};