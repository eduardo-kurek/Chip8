#pragma once

#include <cstdint>
#include "Display.h"
#include "VirtualMachine.h"

class GraphicEngine {
protected:
    uint8_t scale;
    VirtualMachine& vm;

public:
    GraphicEngine(VirtualMachine& vm, uint8_t scale) 
        : scale(scale), vm(vm) {}
    virtual void HandleEvents() = 0;
    virtual void Render() = 0;
    virtual void Sync() = 0;
    virtual bool Quitted() = 0;
    virtual ~GraphicEngine() = default;
};