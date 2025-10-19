#include <iostream>
#include <argparse/argparse.hpp>
#include "VirtualMachine.h"
#include "SDL2Engine.h"

#define FRAME_RATE 60

VirtualMachine* vm;
GraphicEngine* engine;

std::string romPath;
uint16_t scale;
uint16_t instructionsPerFrame;

void parse_args(int argc, char* argv[]);
void chip8_loop();
void frame_tick();

int main(int argc, char* argv[]){
    parse_args(argc, argv);
    chip8_loop();
    return 0;
}

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
    instructionsPerFrame = program.get<int>("-c") / 60;

    vm = new VirtualMachine(romPath);
    engine = new SDL2Engine(*vm, scale, FRAME_RATE);
}

void chip8_loop(){
    while(engine->IsRunning()){
        engine->PrepareSync();
        frame_tick();
        engine->DoSync();
    }
}

void frame_tick(){
    engine->HandleEvents();

    for(int i = 0; i < instructionsPerFrame; i++)
        if(vm->NotWaitingForInput())
            vm->ExecuteNextInstruction();
    
    vm->DecrementTimers();
    engine->Render();
}