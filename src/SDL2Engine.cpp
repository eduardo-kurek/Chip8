#include "SDL2Engine.h"

SDL2Engine::SDL2Engine(const Display& display, uint8_t scale)
    : GraphicEngine(display, scale)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Chip8 Framebuffer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        display.WIDTH * scale, display.HEIGHT * scale,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        display.WIDTH, display.HEIGHT
    );
}

bool SDL2Engine::IsRunning(){
    SDL_Event event;

    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            running = false;
        }
    }
    
    return running;
}

void SDL2Engine::Render(){
    uint32_t pixels[display.WIDTH * display.HEIGHT];

    for(uint16_t y = 0; y < display.HEIGHT; ++y){
        for(uint16_t x = 0; x < display.WIDTH; ++x){
            if(display.At(x, y)){
                pixels[y * display.WIDTH + x] = 0xb9c9bdFF; // Branco
            }else{
                pixels[y * display.WIDTH + x] = 0x18161CFF; // Preto
            }
        }
    }

    SDL_UpdateTexture(texture, nullptr, pixels, display.WIDTH * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void SDL2Engine::Sync(){
    SDL_Delay(32);  // ~30 FPS
}

SDL2Engine::~SDL2Engine(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
