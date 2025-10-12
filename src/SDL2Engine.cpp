#include "SDL2Engine.h"

SDL2Engine::SDL2Engine(uint16_t width, uint16_t height, uint8_t scale)
    : GraphicEngine(width, height, scale)
{
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow(
        "Chip8 Framebuffer",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width * scale, height * scale,
        SDL_WINDOW_SHOWN
    );

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        width, height
    );
}

bool SDL2Engine::IsRunning(){
    SDL_Event event;

    while (running) {
        // Lê eventos
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }
    
    return running;
}

void SDL2Engine::Render(uint8_t display[64][32]){
    uint32_t pixels[width * height];

    // Preencher o array de pixels com base no framebuffer binário
    for (uint16_t y = 0; y < height; ++y) {
        for (uint16_t x = 0; x < width; ++x) {
            if (display[x][y]) {
                pixels[y * width + x] = 0xFFFFFFFF; // Branco
            } else {
                pixels[y * width + x] = 0x000000FF; // Preto
            }
        }
    }

    SDL_UpdateTexture(texture, nullptr, pixels, width * sizeof(uint32_t));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void SDL2Engine::Sync(){
    SDL_Delay(16);  // ~60 FPS
}

SDL2Engine::~SDL2Engine(){
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
