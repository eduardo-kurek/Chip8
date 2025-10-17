#include <cstdint>
#include "PC.h"

uint16_t PC::GetAddress() const {
    return address;
}

void PC::SetAddress(uint16_t newAddress){
    address = newAddress;
}

void PC::IncrementAddress(){
    address += 2;
}