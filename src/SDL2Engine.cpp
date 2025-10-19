#include "SDL2Engine.h"

SDL2Engine::SDL2Engine(VirtualMachine &vm, uint8_t scale, uint16_t frameRate)
    : ticksPerFrame(1000 / frameRate), GraphicEngine(vm, scale)
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
    while(SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_QUIT: Quit(); break;
            case SDL_KEYUP: HandleKeyUp(); break;
            case SDL_KEYDOWN: HandleKeyDown(); break;
            default: break;
        }
    }
}

void SDL2Engine::Quit(){ isRunning = false; }

void SDL2Engine::HandleKeyDown(){
    auto code = GetCurrentKeyCode();
    if(code == SDLK_ESCAPE){
        Quit();
        return;
    }
    
    auto key = GetCurrentKey();
    if(key)
        vm.PressKey(key.value());
}

void SDL2Engine::HandleKeyUp(){
    auto key = GetCurrentKey();
    if(key)
        vm.ReleaseKey(key.value());
}

SDL_KeyCode SDL2Engine::GetCurrentKeyCode() const{
    return (SDL_KeyCode)event.key.keysym.sym;
}

std::optional<uint8_t> SDL2Engine::GetCurrentKey() const{
    auto keyCode = GetCurrentKeyCode();
    if(keyMap.contains(keyCode))
        return keyMap.at(keyCode);
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

void SDL2Engine::PrepareSync(){
    lastFrameTime = SDL_GetTicks();
}

void SDL2Engine::DoSync(){
    Uint32 elapsedTicks = SDL_GetTicks() - lastFrameTime;
    if(elapsedTicks < ticksPerFrame)
        SDL_Delay(ticksPerFrame - elapsedTicks);
}

bool SDL2Engine::IsRunning(){ return isRunning; }

SDL2Engine::~SDL2Engine(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
