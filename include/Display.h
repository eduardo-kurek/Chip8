#pragma once

#include <cstdint>
#include <array>

class Display {
public:
    static const uint8_t WIDTH = 64;
    static const uint8_t HEIGHT = 32;

protected:
    std::array<std::array<uint8_t, HEIGHT>, WIDTH> pixels{};

public:
    void Clear();
    uint8_t At(uint8_t x, uint8_t y) const;
    void SetPixel(uint8_t x, uint8_t y);
    void ResetPixel(uint8_t x, uint8_t y);
    bool TogglePixelAndCheckCollision(uint8_t x, uint8_t y);
};