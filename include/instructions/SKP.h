#pragma once

#include "instructions/Instruction.h"

class SKP : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SKP(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};