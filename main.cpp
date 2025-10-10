// #include <SDL.h>
// #include <CLI/CLI.hpp>
#include <iostream>
#include <Chip8.h>
#include <instructions/CLS.h>
#include <Decoder.h>

int main(int argc, char *argv[]) {
    // CLI::App app{"Meu interpretador Chip8"};

    // std::string rom;
    // app.add_option("rom", rom, "Caminho da ROM")->required();

    // CLI11_PARSE(app, argc, argv);

    // std::cout << "ROM carregada: " << rom << std::endl;

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

    Chip8 vm;
    Decoder decoder;
    decoder.RegisterInstruction(0x0, 0x0, Instruction::Factory<CLS>());

    auto inst = decoder.Decode(0x0001);
    if(inst){
        inst->Execute(vm);
    }
    else{
        std::cout << "Erro ao dar decode;" << std::endl;
    }

    return 0;
}