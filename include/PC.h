#pragma once

#include <cstdint>

class PC {
private:
    uint16_t m_address = 0x200;

public:
    uint16_t getAddress() const;

    void setAddress(uint16_t newAddress);
    
    void incrementAdress();
};