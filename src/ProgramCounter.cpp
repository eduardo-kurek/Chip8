#include "ProgramCounter.h"

ProgramCounter::ProgramCounter(uint16_t address) 
    : address(address) {}

ProgramCounter::operator uint16_t() const{
    return address;
}

ProgramCounter &ProgramCounter::operator=(uint16_t newAddress){
    address = newAddress;
    return *this;
}

ProgramCounter& ProgramCounter::operator++(){
    address += 2;
    return *this;
}

ProgramCounter ProgramCounter::operator++(int){
    ProgramCounter temp = *this;
    address += 2;
    return temp;
}
