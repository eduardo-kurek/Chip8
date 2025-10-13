#include <SDL.h>
#include <iostream>
#include "VirtualMachine.h"

#include "Decoder.h"
// #include <CLI/CLI.hpp>
#include "Memory.h"
#include "SDL2Engine.h"



#define SCALE 13

int main(int argc, char *argv[]) {

    VirtualMachine vm("1-chip8-logo.ch8");
    SDL2Engine engine(vm.display, SCALE);


    while (true)
    {
        //std::cout << vm << "INSTRUÇÃO " << i << ":";
        vm.ExecuteNextInstruction();
        //std::cout << vm << std::endl;
        engine.Render();
    }
    

    // while(engine.IsRunning()){
    //     vm.ExecuteNextInstruction();
    //     engine.Render();
    //     engine.Sync();
    // }

    return 0;


    // CLI::App app{"Chip8 Interpreter"};
    // std::string romPath;

    // app.add_option("rom", romPath, "Caminho da ROM")->required();
    // app.parse(argc, argv);
    
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
    // }

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