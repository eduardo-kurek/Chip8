#include "Decoder.h"
#include <bit>
#include <cstdio>



void Decoder::Register(uint16_t mask, uint16_t pattern, InstructionCreator handler){
    Entry entry(mask, pattern, handler);
    auto index = GetMaskIndex(mask);
    entries[index].push_back(entry);
}

uint16_t Decoder::GetMaskIndex(uint16_t mask) const{
    return std::popcount(mask) - 1;
}

std::unique_ptr<Instruction> Decoder::Decode(const OpCode& opCode){
    for(int i = 15; i >= 0; i--){
        for(Entry entry : entries[i]){
            if((opCode.Code() & entry.mask) == entry.pattern){
                return entry.handler(opCode);
            }
        }
    }
    return nullptr;
}
