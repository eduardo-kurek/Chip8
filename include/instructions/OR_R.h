#pragma once

#include "instructions/Instruction.h"

class OR_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    OR_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};