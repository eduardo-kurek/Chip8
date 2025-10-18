#include <argparse/argparse.hpp>
#include <iostream>
#include "VirtualMachine.h"
#include "SDL2Engine.h"

std::string romPath;
uint16_t scale;
uint16_t emulatorClock;

void parse_args(int argc, char* argv[]){
    argparse::ArgumentParser program("Chip8", "1.0");

    program.add_argument("ROM_PATH")
        .help("Chip8 ROM file location")
        .required();

    program.add_argument("-s", "--scale")
        .help("Amount of times the screen will be multiplied by")
        .default_value(13)
        .scan<'i', int>();

    program.add_argument("-c", "--clock")
        .help("Amount of instructions the program will run each second")
        .default_value(500)
        .scan<'i', int>();

    try {
        program.parse_args(argc, argv);
    } catch (const std::exception& err) {
        std::cerr << err.what() << std::endl;
        std::cerr << program;
        exit(1);
    }

    romPath = program.get<std::string>("ROM_PATH");
    scale = program.get<int>("--scale");
    emulatorClock = program.get<int>("-c");
}

void chip8_loop(){
    VirtualMachine vm(romPath);
    SDL2Engine engine(vm, scale);

    while(engine.IsRunning()){
        engine.HandleEvents();

        for(int i = 0; i < emulatorClock / 60; i++)
            if(vm.NotWaitingForInput())
                vm.ExecuteNextInstruction();
        
        vm.delayTimer.Update();
        vm.soundTimer.Update();

        engine.Render();
        engine.Sync();
    }
}


int main(int argc, char* argv[]){
    parse_args(argc, argv);
    chip8_loop();
    return 0;
}