#pragma once

#include <cstdint>
#include "Display.h"

class GraphicEngine {
protected:
    uint8_t scale;
    const Display& display;

public:
    GraphicEngine(const Display& display, uint8_t scale) 
        : scale(scale), display(display) {}
    virtual bool IsRunning() = 0;
    virtual void Render() = 0;
    virtual void Sync() = 0;
    virtual ~GraphicEngine() = default;
};