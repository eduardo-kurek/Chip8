#include <SDL.h>
#include <iostream>
#include "VirtualMachine.h"

#include "Decoder.h"
#include <CLI/CLI.hpp>
#include "Memory.h"
#include "SDL2Engine.h"

int main(int argc, char* argv[]){

    std::string romPath = "";
    uint8_t scale = 13;
    uint16_t clock = 500;

    CLI::App app{"Chip8"};
    
    app.add_option("ROM_PATH", romPath, "Chip8 ROM file location")->required();
    app.add_option("-s,--scale", scale, "Default = 13. Amount of times the screen will be multiplied by")->check(CLI::Range(1,30));
    app.add_option("-c,--clock", clock, "Default = 500Hz. Amount of instructions the program will run each seconds in Hertz.")->check(CLI::Range(1, 5000));

    try {
        app.parse(argc, argv);
    } catch (const CLI::ParseError &e) {
        return app.exit(e);
    }

    VirtualMachine vm(romPath);
    SDL2Engine engine(vm, scale);
    

    while(true){
        engine.HandleEvents();
        if(engine.Quitted())
            break;

        if(vm.NotWaitingForInput())
            vm.ExecuteNextInstruction();
        
        vm.delayTimer.Update();
        vm.soundTimer.Update();

        engine.Render();
        engine.Sync();
    }

    return 0;
}