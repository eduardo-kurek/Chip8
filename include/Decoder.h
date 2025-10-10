#pragma once

#include "instructions/Instruction.h"
#include <unordered_map>
#include <vector>

class Decoder {

    struct Entry {
        uint16_t mask;
        uint16_t pattern;
        InstructionCreator handler;

        Entry(uint16_t mask, uint16_t pattern, InstructionCreator handler){
            this->mask = mask;
            this->pattern = static_cast<uint16_t>(pattern & mask);
            this->handler = handler;
        }
    };

    uint16_t GetMaskIndex(uint16_t mask) const;

    std::vector<Entry> entries[16];

public:
    Decoder() = default;
    void Register(uint16_t mask, uint16_t pattern, InstructionCreator handler);
    std::unique_ptr<Instruction> Decode(const OpCode& opCode);
};