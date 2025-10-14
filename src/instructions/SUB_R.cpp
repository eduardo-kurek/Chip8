#include "instructions/SUB_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SUB_R::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] > vm.V[opCode.Y()])
        vm.V[0xF] = 1;  
    else
        vm.V[0xF] = 0;
    
    uint16_t sub = vm.V[opCode.X()] - vm.V[opCode.Y()];
    vm.V[opCode.X()] = (uint8_t)sub;
}

std::string SUB_R::GetName() const{ return "SUB_R"; }
