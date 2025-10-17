#pragma once

#include "instructions/Instruction.h"

class XOR_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    XOR_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};