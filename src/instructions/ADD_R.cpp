#include "instructions/ADD_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void ADD_R::DoExecute(VirtualMachine& vm) const{
    uint16_t sum = vm.V[opCode.X()] + vm.V[opCode.Y()];

    uint8_t carryFlag = (sum > 0xFF) ? 1 : 0; 

    vm.V[opCode.X()] = (uint8_t)sum;
    
    vm.V[0xF] = carryFlag;
}


std::string ADD_R::GetName() const{ return "ADD_R"; }
