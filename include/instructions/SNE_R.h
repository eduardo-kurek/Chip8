#pragma once

#include "instructions/Instruction.h"

class SNE_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SNE_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};