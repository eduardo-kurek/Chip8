#include "instructions/SNE_N.h"
#include "VirtualMachine.h"
#include <cstdio>

void SNE_N::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] != opCode.NN())
        vm.pc++;
}

std::string SNE_N::GetName() const{ return "SNE_N"; }
