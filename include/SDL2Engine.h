#pragma once

#include <SDL.h>
#include "GraphicEngine.h"

class SDL2Engine : public GraphicEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    bool running = true;

public:
    SDL2Engine(const Display& display, uint8_t scale);
    virtual bool IsRunning() override;
    virtual void Render() override;
    virtual void Sync() override;
    ~SDL2Engine() override;
};