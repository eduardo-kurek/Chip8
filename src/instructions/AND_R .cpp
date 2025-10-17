#include "instructions/AND_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void AND_R::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] &= vm.V[opCode.Y()];
}

std::string AND_R::GetName() const{ return "AND_R"; }
