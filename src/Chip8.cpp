#include "Chip8.h"
#include <cstdint>
#include <iostream>

Chip8::Chip8(){

}

bool Chip8::loadROM(const char* filepath){
 return true;
}

uint16_t Chip8::fetchOpCode() {
    uint16_t address = m_programCounter.getAddress();
    
    uint8_t high_byte = RAM.readByte(address);
    uint8_t low_byte  = RAM.readByte(address + 1);
    
    uint16_t opcode = (static_cast<uint16_t>(high_byte) << 8) | low_byte; 
    
    return opcode;
}

void Chip8::execute(uint16_t opCode){

    return;
}

void Chip8::run(){
    while ( true ){
        uint16_t opCode = Chip8::fetchOpCode();

        Chip8::execute(opCode);
    }
}

void Chip8::print(){
    std::cout << "Registers:" << std::endl;
    for (int i = 0; i < 16; ++i) {
        std::cout << "V[" << i << "] = " << std::hex << static_cast<int>(m_Vx[i]) << std::endl;
    }
    std::cout << "I = " << std::hex << m_I << std::endl;
    std::cout << "PC = " << std::hex << m_programCounter.getAddress() << std::endl;
    std::cout << "SP = " << std::hex << static_cast<int>(m_stackPointer) << std::endl;
}

void Chip8::clearDisplay(){
    m_DISPLAY.fill(0);
}