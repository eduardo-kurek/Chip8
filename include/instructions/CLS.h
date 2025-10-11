#pragma once

#include "instructions/Instruction.h"

class CLS : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    CLS(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};