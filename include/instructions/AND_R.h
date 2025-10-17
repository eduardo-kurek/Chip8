#pragma once

#include "instructions/Instruction.h"

class VirtualMachine;

class AND_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    AND_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};