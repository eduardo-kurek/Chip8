#include <stdexcept>
#include "Display.h"

void Display::Clear(){ pixels.fill({}); }

uint8_t Display::At(uint8_t x, uint8_t y) const{ return pixels[x][y]; }

void Display::SetPixel(uint8_t x, uint8_t y){ pixels[x][y] = 1; }

void Display::ResetPixel(uint8_t x, uint8_t y){ pixels[x][y] = 0; }

bool Display::TogglePixel(uint8_t x, uint8_t y){
    pixels[x][y] = !pixels[x][y];
    return pixels[x][y];
}
