#pragma once

#include "instructions/Instruction.h"

class SUB_R : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SUB_R(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};