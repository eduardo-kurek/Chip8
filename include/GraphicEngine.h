#pragma once

#include <cstdint>

class GraphicEngine {
protected:
    uint16_t width;
    uint16_t height;
    uint8_t scale;

public:
    GraphicEngine(uint16_t width, uint16_t height, uint8_t scale)
        : width(width), height(height), scale(scale) {}
    virtual bool IsRunning() = 0;
    virtual void Render(uint8_t display[64][32]) = 0;
    virtual void Sync() = 0;
    virtual ~GraphicEngine() = default;
};