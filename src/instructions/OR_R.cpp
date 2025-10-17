#include "instructions/OR_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void OR_R::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] |= vm.V[opCode.Y()];
}

std::string OR_R::GetName() const{ return "OR_R"; }
