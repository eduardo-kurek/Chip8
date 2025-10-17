#include "Decoder.h"
#include <bit>
#include <cstdio>

#include "instructions/CLS.h"
#include "instructions/RET.h"
#include "instructions/JMP.h"
#include "instructions/CALL.h"
#include "instructions/SE_N.h"
#include "instructions/SNE_N.h"
#include "instructions/SE_R.h"
#include "instructions/LD_N.h"
#include "instructions/ADD_N.h"
#include "instructions/LD_R.h"
#include "instructions/OR_R.h"
#include "instructions/AND_R.h"
#include "instructions/XOR_R.h"
#include "instructions/ADD_R.h"
#include "instructions/SUB_R.h"
#include "instructions/SHR_R.h"
#include "instructions/SUBN_R.h"
#include "instructions/SHL_R.h"
#include "instructions/SNE_R.h"
#include "instructions/LD_I.h"
#include "instructions/JMP_V0.h"
#include "instructions/RND.h"
#include "instructions/DRW.h"
#include "instructions/SKP.h"
#include "instructions/SKPN.h"
#include "instructions/LD_DT_R.h"
#include "instructions/LD_K.h"
#include "instructions/LD_R_DT.h"
#include "instructions/LD_R_ST.h"
#include "instructions/ADD_I.h"
#include "instructions/LD_I_R.h"
#include "instructions/LD_B.h"
#include "instructions/LD_I_Rs.h"
#include "instructions/LD_Rs_I.h"

Decoder* Decoder::instance = nullptr;

void Decoder::Register(uint16_t mask, uint16_t pattern, InstructionCreator handler){
    Entry entry(mask, pattern, handler);
    auto index = GetMaskIndex(mask);
    entries[index].push_back(entry);
}

void Decoder::Initialize(){
    Register(0xFFFF, 0x00E0, Instruction::GetFactoryOf<CLS>());
    Register(0xFFFF, 0x00EE, Instruction::GetFactoryOf<RET>());

    Register(0XF000, 0x1000, Instruction::GetFactoryOf<JMP>());
    
    Register(0xF000, 0x2000, Instruction::GetFactoryOf<CALL>());
    
    Register(0xF000, 0x3000, Instruction::GetFactoryOf<SE_N>());

    Register(0xF000, 0x4000, Instruction::GetFactoryOf<SNE_N>());

    Register(0xF000, 0x5000, Instruction::GetFactoryOf<SE_R>());
    
    Register(0xF000, 0x6000, Instruction::GetFactoryOf<LD_N>());
    
    Register(0xF000, 0x7000, Instruction::GetFactoryOf<ADD_N>());

    Register(0xF00F, 0x8000, Instruction::GetFactoryOf<LD_R>());
    Register(0xF00F, 0x8001, Instruction::GetFactoryOf<OR_R>());
    Register(0xF00F, 0x8002, Instruction::GetFactoryOf<AND_R>());
    Register(0xF00F, 0x8003, Instruction::GetFactoryOf<XOR_R>());
    Register(0xF00F, 0x8004, Instruction::GetFactoryOf<ADD_R>());
    Register(0xF00F, 0x8005, Instruction::GetFactoryOf<SUB_R>());
    Register(0xF00F, 0x8006, Instruction::GetFactoryOf<SHR_R>());
    Register(0xF00F, 0x8007, Instruction::GetFactoryOf<SUBN_R>());
    Register(0xF00F, 0x800E, Instruction::GetFactoryOf<SHL_R>());

    Register(0xF00F, 0x9000, Instruction::GetFactoryOf<SNE_R>());

    Register(0xF000, 0xA000, Instruction::GetFactoryOf<LD_I>());

    Register(0xF000, 0xB000, Instruction::GetFactoryOf<JMP_V0>());

    Register(0xF000, 0xC000, Instruction::GetFactoryOf<RND>());

    Register(0xF000, 0xD000, Instruction::GetFactoryOf<DRW>());

    Register(0xF0FF, 0xE09E, Instruction::GetFactoryOf<SKP>());
    Register(0xF0FF, 0xE0A1, Instruction::GetFactoryOf<SKPN>());
    
    Register(0xF0FF, 0XF007, Instruction::GetFactoryOf<LD_DT_R>());
    Register(0xF0FF, 0XF00A, Instruction::GetFactoryOf<LD_K>());
    Register(0xF0FF, 0XF015, Instruction::GetFactoryOf<LD_R_DT>());
    Register(0xF0FF, 0XF018, Instruction::GetFactoryOf<LD_R_ST>());
    Register(0xF0FF, 0XF01E, Instruction::GetFactoryOf<ADD_I>());
    Register(0xF0FF, 0XF029, Instruction::GetFactoryOf<LD_I_R>());
    Register(0xF0FF, 0XF033, Instruction::GetFactoryOf<LD_B>());
    Register(0xF0FF, 0XF055, Instruction::GetFactoryOf<LD_I_Rs>());
    Register(0xF0FF, 0XF065, Instruction::GetFactoryOf<LD_Rs_I>());

}

uint16_t Decoder::GetMaskIndex(uint16_t mask) const{
    return std::popcount(mask) - 1;
}

std::unique_ptr<Instruction> Decoder::Decode(const OpCode& opCode) const{
    for(int i = 15; i >= 0; i--){
        for(Entry entry : entries[i]){
            if((opCode.Code() & entry.mask) == entry.pattern){
                return entry.handler(opCode);
            }
        }
    }
    return nullptr;
}

const Decoder& Decoder::Instance(){
    if(instance == nullptr){
        instance = new Decoder();
        instance->Initialize();
    }
    return *instance;
}
