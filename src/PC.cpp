#include <cstdint>
#include "PC.h"

uint16_t PC::getAddress() const { 
    return m_address;
}

void PC::setAddress(uint16_t newAddress) {
    m_address = newAddress;
}

void PC::incrementAdress() {
    m_address += 2;
}