#include "Decoder.h"

void Decoder::RegisterInstruction(uint8_t group, InstructionCreator creator){
    this->singleInstructionGroup[group] = creator;
}

std::unique_ptr<Instruction> Decoder::Decode(const OpCode& opCode){
    auto it = singleInstructionGroup.find(opCode.Group());
    if(it != singleInstructionGroup.end()){
        return it->second(opCode);
    }
    return nullptr;
}
