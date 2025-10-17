#include "instructions/SUBN_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SUBN_R::DoExecute(VirtualMachine& vm) const{
    uint16_t sub = vm.V[opCode.Y()] - vm.V[opCode.X()];

    uint8_t notBorrowFlag = (vm.V[opCode.Y()] >= vm.V[opCode.X()]) ? 1 : 0;

    vm.V[opCode.X()] = (uint8_t)sub;

    vm.V[0xF] = notBorrowFlag;
}

std::string SUBN_R::GetName() const{ return "SUBN_R"; }
