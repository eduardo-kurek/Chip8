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
    virtual void PrepareSync() = 0;
    virtual void DoSync() = 0;
    virtual bool IsRunning() = 0;
    virtual void PlaySound() = 0;
    virtual void PauseSound() = 0;
    virtual ~GraphicEngine() = default;
};