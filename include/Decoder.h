#pragma once

#include "instructions/Instruction.h"
#include <unordered_map>
#include <vector>

class Decoder {
    static Decoder* instance;
    
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
    Decoder() = default;
    void Register(uint16_t mask, uint16_t pattern, InstructionCreator handler);
    void Initialize();

    
public:
    std::unique_ptr<Instruction> Decode(const OpCode& opCode) const;
    static const Decoder& Instance();
};