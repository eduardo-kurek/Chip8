#include "Decoder.h"

void Decoder::RegisterInstruction(uint8_t C, InstructionCreator creator){
    this->singleInstructionGroup[C] = creator;
}

void Decoder::RegisterInstruction(uint8_t C, uint8_t N, InstructionCreator creator){
    this->multiInstructionGroup[C][N] = creator;
}

std::unique_ptr<Instruction> Decoder::Decode(const OpCode& opCode){
    auto it = multiInstructionGroup.find(opCode.C());
    if(it != multiInstructionGroup.end()){
        auto it2 = it->second.find(opCode.N());
        if(it2 != it->second.end()){
            return it2->second(opCode);
        }
    }

    auto it3 = singleInstructionGroup.find(opCode.C());
    if(it3 != singleInstructionGroup.end()){
        return it3->second(opCode);
    }

    return nullptr;
}
