#pragma once

#include "instructions/Instruction.h"
#include <unordered_map>

class Decoder {
    std::unordered_map<uint8_t, InstructionCreator> singleInstructionGroup;

public:
    Decoder() = default;
    void RegisterInstruction(uint8_t c, InstructionCreator creator);
    std::unique_ptr<Instruction> Decode(const OpCode& opCode);
};