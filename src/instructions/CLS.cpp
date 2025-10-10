#include "instructions/CLS.h"

void CLS::Execute(Chip8 &vm) const{
    vm.clearDisplay();
}