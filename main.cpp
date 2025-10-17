#include <SDL.h>
#include <iostream>
#include "VirtualMachine.h"

#include "Decoder.h"
// #include <CLI/CLI.hpp>
#include "Memory.h"
#include "SDL2Engine.h"

#define SCALE 13

int main(int argc, char* argv[]){
    VirtualMachine vm(argv[1]);
    SDL2Engine engine(vm, SCALE);

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