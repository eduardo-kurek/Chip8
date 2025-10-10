#include "instructions/CLS.h"
#include <iostream>

void CLS::Execute(Chip8 &vm) const{
    vm.clearDisplay();
}