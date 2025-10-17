#pragma once

#include "instructions/Instruction.h"

class CALL : public Instruction {
protected:
    void DoExecute(VirtualMachine& vm) const override;

public:
    CALL(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};