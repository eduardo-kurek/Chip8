#include "instructions/RET.h"
#include <iostream>

void RET::Execute(Chip8 &vm) const{
    std::cout << "RET" << std::endl;
}