#pragma once

#include "instructions/Instruction.h"

class SUBN_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SUBN_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};