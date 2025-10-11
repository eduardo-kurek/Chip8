// #include <SDL.h>
#include <iostream>
#include "Context.h"
#include <instructions/CLS.h>
#include <instructions/RET.h>
#include "Decoder.h"
#include <CLI/CLI.hpp>
#include "Memory.h"

int main(int argc, char *argv[]) {
    CLI::App app{"Chip8 Interpreter"};
    std::string romPath;

    app.add_option("rom", romPath, "Caminho da ROM")->required();
    app.parse(argc, argv);

    // SDL_Window *window;

    // SDL_Init(SDL_INIT_VIDEO);

    // window = SDL_CreateWindow(
    //         "SDL2Test",
    //         SDL_WINDOWPOS_UNDEFINED,
    //         SDL_WINDOWPOS_UNDEFINED,
    //         640,
    //         480,
    //         SDL_WINDOW_OPENGL
    // );

    // if (window == nullptr) {
    //     std::cout << "Could not create window" << SDL_GetError() << std::endl;
    //     return -1;
    // }

    // SDL_Delay(3000);

    // SDL_DestroyWindow(window);
    // SDL_Quit();

    Decoder decoder;
    decoder.Register(0xFFFF, 0x00E0, Instruction::GetFactoryOf<CLS>());
    decoder.Register(0xFFFF, 0x00EE, Instruction::GetFactoryOf<RET>());

    Memory mem(romPath);
    Context ctx;

    for(uint32_t i = 0; i < mem.GetInstructionsCount(); i++){
        uint16_t address = ctx.programCounter.GetAddress();
        OpCode opcode(mem.Fetch(address));
        auto inst = decoder.Decode(opcode);
        if(inst)
            inst->Execute(ctx);
        else
            std::cerr << "Unknown opcode: (" << std::hex << std::setfill('0') << 
            std::setw(4) << opcode.Code() << " at address " << address <<
            std::dec << std::setfill(' ') << ")" << std::endl;
        ctx.programCounter.IncrementAddress();
    }

    return 0;
}