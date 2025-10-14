#include "Timer.h"

Timer::Timer() : value(0){
    lastUpdate = std::chrono::high_resolution_clock::now();
}

uint8_t Timer::GetValue() const{ return value; }
void Timer::SetValue(uint8_t value){ this->value = value; }

void Timer::Update() {
    auto now = std::chrono::high_resolution_clock::now();

    auto elapsed = now - lastUpdate;

    while (elapsed >= tickDuration) {
        
        if (value > 0) value--;
        
        lastUpdate += tickDuration;
        
        elapsed = now - lastUpdate;
    }
}