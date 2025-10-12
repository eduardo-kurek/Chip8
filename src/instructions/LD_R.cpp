#include "instructions/LD_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_R::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] = vm.V[opCode.Y()];
}

std::string LD_R::GetName() const{ return "LD_R"; }
