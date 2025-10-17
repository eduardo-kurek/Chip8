#include "instructions/LD_N.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_N::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] = opCode.NN();
}

std::string LD_N::GetName() const{ return "LD_N"; }
