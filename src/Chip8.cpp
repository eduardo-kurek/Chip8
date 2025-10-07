#pragma once 

#include <../include/Chip8.h>
#include <cstdint>
#include <PC.cpp>

Chip8::Chip8(){

}

bool Chip8::loadROM(const char* filepath){
 return true;
}

uint16_t Chip8::fetchOpCode() {
    uint16_t address = m_Pc.getAddress();
    
    uint8_t high_byte = RAM.readByte(address);
    uint8_t low_byte  = RAM.readByte(address + 1);
    
    uint16_t opcode = (static_cast<uint16_t>(high_byte) << 8) | low_byte; 
    
    return opcode;
}

void Chip8::execute(uint16_t opCode){
    uint8_t group = opCode >> 12;
    uint8_t X = (opCode & 0x0F00) >> 8;
    uint8_t Y = (opCode & 0x00F0) >> 4;
    uint8_t N = (opCode & 0x000F);
    uint8_t N = (opCode & 0x00FF);
    uint8_t N = (opCode & 0x0FFF);

    

    return;
}

void Chip8::run(){
    while ( true ){
        uint16_t opCode = Chip8::fetchOpCode();

        Chip8::execute(opCode);
    }
}