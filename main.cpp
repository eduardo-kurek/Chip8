#include <SDL.h>
#include <iostream>
#include "Context.h"

#include "Decoder.h"
// #include <CLI/CLI.hpp>
#include "Memory.h"
#include "SDL2Engine.h"

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

#define CHIP8_WIDTH 64
#define CHIP8_HEIGHT 32
#define SCALE 10

uint8_t display[CHIP8_WIDTH][CHIP8_HEIGHT];

int main(int argc, char *argv[]) {
    
    SDL2Engine engine(CHIP8_WIDTH, CHIP8_HEIGHT, SCALE);

    while(engine.IsRunning()){
        engine.Render(display);
        engine.Sync();
    }

    return 0;


    // CLI::App app{"Chip8 Interpreter"};
    // std::string romPath;

    // app.add_option("rom", romPath, "Caminho da ROM")->required();
    // app.parse(argc, argv);

    // Decoder decoder;
    // decoder.Register(0xFFFF, 0x00E0, Instruction::GetFactoryOf<CLS>());
    // decoder.Register(0xFFFF, 0x00EE, Instruction::GetFactoryOf<RET>());

    // decoder.Register(0XF000, 0x1000, Instruction::GetFactoryOf<JMP>());
    
    // decoder.Register(0xF000, 0x2000, Instruction::GetFactoryOf<CALL>());
    
    // decoder.Register(0xF000, 0x3000, Instruction::GetFactoryOf<SE_N>());

    // decoder.Register(0xF000, 0x4000, Instruction::GetFactoryOf<SNE_N>());

    // decoder.Register(0xF000, 0x5000, Instruction::GetFactoryOf<SE_R>());
    
    // decoder.Register(0xF000, 0x6000, Instruction::GetFactoryOf<LD_N>());
    
    // decoder.Register(0xF000, 0x7000, Instruction::GetFactoryOf<ADD_N>());

    // decoder.Register(0xF00F, 0x8000, Instruction::GetFactoryOf<LD_R>());
    // decoder.Register(0xF00F, 0x8001, Instruction::GetFactoryOf<OR_R>());
    // decoder.Register(0xF00F, 0x8002, Instruction::GetFactoryOf<AND_R>());
    // decoder.Register(0xF00F, 0x8003, Instruction::GetFactoryOf<XOR_R>());
    // decoder.Register(0xF00F, 0x8004, Instruction::GetFactoryOf<ADD_R>());
    // decoder.Register(0xF00F, 0x8005, Instruction::GetFactoryOf<SUB_R>());
    // decoder.Register(0xF00F, 0x8006, Instruction::GetFactoryOf<SHR_R>());
    // decoder.Register(0xF00F, 0x8007, Instruction::GetFactoryOf<SUBN_R>());
    // decoder.Register(0xF00F, 0x800E, Instruction::GetFactoryOf<SHL_R>());

    // decoder.Register(0xF00F, 0x9000, Instruction::GetFactoryOf<SNE_R>());

    // decoder.Register(0xF000, 0xA000, Instruction::GetFactoryOf<LD_I>());

    // decoder.Register(0xF000, 0xB000, Instruction::GetFactoryOf<JMP_V0>());

    // decoder.Register(0xF000, 0xC000, Instruction::GetFactoryOf<RND>());



    // Memory mem(romPath);
    // Context ctx;

    // /*
    // for(uint32_t i = 0; i < mem.GetInstructionsCount(); i++){
    //     uint16_t address = ctx.programCounter.GetAddress();
    //     OpCode opcode(mem.Fetch(address));
    //     ctx.programCounter.IncrementAddress();
    //     auto inst = decoder.Decode(opcode);
    //     if(inst)
    //         inst->Execute(ctx);
    //     else
    //         std::cerr << "Unknown opcode: (" << std::hex << std::setfill('0') << 
    //         std::setw(4) << opcode.Code() << " at address " << address <<
    //         std::dec << std::setfill(' ') << ")" << std::endl;
    // }*/

    // std::cout << ctx;

    // OpCode opcode(0x4222);
    // auto inst = decoder.Decode(opcode);
    // if(inst)
    //     inst->Execute(ctx);
    // else
    //     std::cerr << "Unknown opcode: (" << std::hex << std::setfill('0') << 
    //     std::setw(4) << opcode.Code() <<
    //     std::dec << std::setfill(' ') << ")" << std::endl;

    // std::cout << ctx;

    // return 0;
}