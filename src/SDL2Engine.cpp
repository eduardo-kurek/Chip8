#include "SDL2Engine.h"

SDL2Engine::SDL2Engine(VirtualMachine &vm, uint8_t scale)
    : GraphicEngine(vm, scale)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Chip8 Framebuffer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        vm.display.WIDTH * scale, vm.display.HEIGHT * scale,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        vm.display.WIDTH, vm.display.HEIGHT
    );
}

void SDL2Engine::HandleEvents(){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        switch (event.type){

            case SDL_QUIT: Quit(); return;

            case SDL_KEYUP: {
                auto code = GetKeyCode(event);
                auto key = GetKey(code);
                if(key)
                    vm.ReleaseKey(key.value());
                break;
            }

            case SDL_KEYDOWN: {
                auto code = GetKeyCode(event);
                if(code == SDLK_ESCAPE){
                    Quit();
                    return;
                }
                
                auto key = GetKey(code);
                if(key)
                    vm.PressKey(key.value());
                break;
            }
            
            default:
                break;
        }
    }
}

void SDL2Engine::Quit(){
    quitted = true;
}

SDL_KeyCode SDL2Engine::GetKeyCode(const SDL_Event &event){
    return (SDL_KeyCode)event.key.keysym.sym;
}

std::optional<uint8_t> SDL2Engine::GetKey(const SDL_KeyCode& code) const{
    if(keyMap.contains(code))
        return keyMap.at(code);
    return {};
}

void SDL2Engine::Render(){
    uint32_t pixels[vm.display.WIDTH * vm.display.HEIGHT];

    for(uint16_t y = 0; y < vm.display.HEIGHT; ++y){
        for(uint16_t x = 0; x < vm.display.WIDTH; ++x){
            if(vm.display.At(x, y)){
                pixels[y * vm.display.WIDTH + x] = 0xb9c9bdFF; // Branco
            }else{
                pixels[y * vm.display.WIDTH + x] = 0x18161CFF; // Preto
            }
        }
    }

    SDL_UpdateTexture(texture, nullptr, pixels, vm.display.WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void SDL2Engine::Sync(){
    SDL_Delay(16);  // ~30 FPS
}

bool SDL2Engine::Quitted(){ return quitted; }

SDL2Engine::~SDL2Engine(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
