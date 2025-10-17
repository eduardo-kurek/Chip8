#pragma once

#include "instructions/Instruction.h"

class SE_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SE_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};