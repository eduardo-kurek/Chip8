#pragma once

#include "GraphicEngine.h"
#include <SDL.h>

class SDL2Engine : public GraphicEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    bool running = true;

public:
    SDL2Engine(uint16_t width, uint16_t height, uint8_t scale);
    virtual bool IsRunning() override;
    virtual void Render(uint8_t display[64][32]) override;
    virtual void Sync() override;
    ~SDL2Engine() override;
};