#pragma once

#include "instructions/Instruction.h"

class DRW : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    DRW(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};