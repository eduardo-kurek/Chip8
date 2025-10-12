#include "instructions/SUBN_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SUBN_R::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.Y()] > vm.V[opCode.X()])
        vm.V[0xF] = 1;  
    else
        vm.V[0xF] = 0;
        
    vm.V[opCode.X()] = vm.V[opCode.Y()] - vm.V[opCode.X()];
}

std::string SUBN_R::GetName() const{ return "SUBN_R"; }
