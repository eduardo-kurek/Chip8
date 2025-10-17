#include "instructions/DRW.h"
#include "VirtualMachine.h"
#include <cstdio>

void DRW::DoExecute(VirtualMachine& vm) const{

    /*
        antes de chamar a draw salva a imagem em I

        DRW = DXYN

        N = a altura da sprite, ou quantos bits tem de serem lidos de I a partir de I[0]

        X = offset no eixo x

        Y = offset no eixo y
    */ 

    uint8_t xCoord = vm.V[opCode.X()] % Display::WIDTH;
    uint8_t yCoord = vm.V[opCode.Y()] % Display::HEIGHT;
    uint8_t height = opCode.N();
    vm.V[0xF] = 0;

    for(uint8_t row = 0; row < height; row++){
        uint16_t spriteAddress = vm.I + row;
        if(spriteAddress >= 0xFFF) break;

    
        uint8_t spriteRow = vm.mem.At(spriteAddress);
        for(uint8_t col = 0; col < 8; ++col){
            bool currentBit = (spriteRow & (0x80 >> col));
            if(currentBit != 0){
                uint8_t x = (xCoord + col) % Display::WIDTH;
                uint8_t y = (yCoord + row) % Display::HEIGHT;
                
                if(vm.display.TogglePixelAndCheckCollision(x, y)){
                    vm.V[0xF] = 1;
                }
            }
        }
    }
}

std::string DRW::GetName() const{ return "DRW"; }
