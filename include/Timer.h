#pragma once

#include <cstdint>
#include <chrono>

class Timer {
    using Clock = std::chrono::high_resolution_clock;
    uint8_t value;
    Clock::time_point lastUpdate;
    const Clock::duration tickDuration = std::chrono::duration_cast<Clock::duration>(std::chrono::milliseconds(1000) / 60);

public:
    Timer();
    uint8_t GetValue() const;
    void SetValue(uint8_t value);
    void Update();
};