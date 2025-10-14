#include "instructions/ADD_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void ADD_R::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] + vm.V[opCode.Y()] > 0xFF)
        vm.V[0xF] = 1;  
    else
        vm.V[0xF] = 0;

    uint16_t sum = vm.V[opCode.X()] + vm.V[opCode.Y()];
    vm.V[opCode.X()] = (uint8_t)sum;
}

std::string ADD_R::GetName() const{ return "ADD_R"; }
