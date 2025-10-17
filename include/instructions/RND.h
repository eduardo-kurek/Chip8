#pragma once

#include "instructions/Instruction.h"

class RND : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    RND(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};