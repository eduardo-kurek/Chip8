#include "instructions/DRW.h"
#include "VirtualMachine.h"
#include <cstdio>

void DRW::DoExecute(VirtualMachine& vm) const{
    uint8_t xCoord = vm.V[opCode.X()] % Display::WIDTH;
    uint8_t yCoord = vm.V[opCode.Y()] % Display::HEIGHT;
    uint8_t height = opCode.N();

    for(uint8_t row = 0; row < height; ++row){
        uint8_t spriteByte = vm.I + row;
        if(spriteByte >= 0xFFF) break;

        uint8_t spriteRow = *(reinterpret_cast<uint8_t*>(&vm) + spriteByte);
        for(uint8_t col = 0; col < 8; ++col){
            if((spriteRow & (0x80 >> col)) != 0){
                uint8_t x = (xCoord + col) % Display::WIDTH;
                uint8_t y = (yCoord + row) % Display::HEIGHT;
                if(vm.display.TogglePixel(x, y)){
                    vm.V[0xF] = 1;
                }
            }
        }
    }
}

std::string DRW::GetName() const{ return "DRW"; }
