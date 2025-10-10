#pragma once

#include "instructions/Instruction.h"
#include <unordered_map>

class Decoder {
    std::unordered_map<uint8_t, InstructionCreator> singleInstructionGroup;
    std::unordered_map<uint8_t, std::unordered_map<uint8_t, InstructionCreator>> multiInstructionGroup;

public:
    Decoder() = default;
    void RegisterInstruction(uint8_t C, InstructionCreator creator);
    void RegisterInstruction(uint8_t C, uint8_t N, InstructionCreator creator);
    std::unique_ptr<Instruction> Decode(const OpCode& opCode);
};