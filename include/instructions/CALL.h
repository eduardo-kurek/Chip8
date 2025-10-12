#pragma once

#include "instructions/Instruction.h"

class CALL : public Instruction {
protected:
    void DoExecute(Context& ctx) const override;

public:
    CALL(const OpCode& opCode) : Instruction(opCode) {};
    std::string GetName() const override;
};