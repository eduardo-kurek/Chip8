#include "instructions/SUB_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SUB_R::DoExecute(VirtualMachine& vm) const{
    uint16_t sub = vm.V[opCode.X()] - vm.V[opCode.Y()];
    
    uint8_t notBorrowFlag = (vm.V[opCode.X()] >= vm.V[opCode.Y()]) ? 1 : 0;

    vm.V[opCode.X()] = (uint8_t)sub;

    vm.V[0xF] = notBorrowFlag;
}

std::string SUB_R::GetName() const{ return "SUB_R"; }
