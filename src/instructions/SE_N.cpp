#include "instructions/SE_N.h"
#include "VirtualMachine.h"
#include <cstdio>

void SE_N::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] == opCode.NN())
        vm.pc++;
}

std::string SE_N::GetName() const{ return "SE_N"; }
