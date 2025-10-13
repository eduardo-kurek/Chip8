#pragma once

#include <cstdint>

class Timer {
    uint8_t value;
    
public:
    Timer() = default;
    uint8_t GetValue() const;
    void SetValue(uint8_t value);
};