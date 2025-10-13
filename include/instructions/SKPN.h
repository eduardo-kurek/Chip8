#pragma once

#include "instructions/Instruction.h"

class SKPN : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    SKPN(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};