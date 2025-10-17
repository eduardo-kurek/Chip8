#include "instructions/ADD_N.h"
#include "VirtualMachine.h"
#include <cstdio>

void ADD_N::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] += opCode.NN();
}

std::string ADD_N::GetName() const{ return "ADD_N"; }
