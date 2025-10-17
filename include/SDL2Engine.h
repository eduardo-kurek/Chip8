#pragma once

#include <SDL.h>
#include <unordered_map>
#include <optional>
#include "GraphicEngine.h"
#include "VirtualMachine.h"

class SDL2Engine : public GraphicEngine {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    bool quitted = false;
    

    const std::unordered_map<SDL_KeyCode, uint8_t> keyMap = {
        {SDLK_1, 0x1}, {SDLK_2, 0x2}, {SDLK_3, 0x3}, {SDLK_4, 0xC},
        {SDLK_q, 0x4}, {SDLK_w, 0x5}, {SDLK_e, 0x6}, {SDLK_r, 0xD},
        {SDLK_a, 0x7}, {SDLK_s, 0x8}, {SDLK_d, 0x9}, {SDLK_f, 0xE},
        {SDLK_z, 0xA}, {SDLK_x, 0x0}, {SDLK_c, 0xB}, {SDLK_v, 0xF},
    };
    
    void Quit();
    SDL_KeyCode GetKeyCode(const SDL_Event& event);
    std::optional<uint8_t> GetKey(const SDL_KeyCode& code) const;
    
public:
    SDL2Engine(VirtualMachine& vm, uint8_t scale);
    virtual void HandleEvents() override;
    virtual void Render() override;
    virtual void Sync() override;
    virtual bool Quitted() override;
    ~SDL2Engine() override;
};