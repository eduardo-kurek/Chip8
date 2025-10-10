#include "instructions/CLS.h"
#include <cstdio>

void CLS::Execute(Chip8 &vm) const{
    printf("CLS\n");
    vm.clearDisplay();
}