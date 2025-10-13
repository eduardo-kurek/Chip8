#include <SDL.h>
#include <iostream>
#include "VirtualMachine.h"

#include "Decoder.h"
// #include <CLI/CLI.hpp>
#include "Memory.h"
#include "SDL2Engine.h"

#define SCALE 13

int main(int argc, char *argv[]){
    VirtualMachine vm("1-chip8-logo.ch8");
    SDL2Engine engine(vm, SCALE);

    std::cout << vm << std::endl;

    vm.Execute(0xFF0A);
    vm.PressKey(0x9);

    std::cout << vm << std::endl;

    return 0;

    while(true){
        engine.HandleEvents();
        if(engine.Quitted())
            break;

        if(vm.NotWaitingForInput())
            vm.ExecuteNextInstruction();

        engine.Render();
        engine.Sync();
    }

    return 0;
}