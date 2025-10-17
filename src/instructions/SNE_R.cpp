#include "instructions/SNE_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SNE_R::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] != vm.V[opCode.Y()])
        vm.programCounter.IncrementAddress();
}

std::string SNE_R::GetName() const{ return "SNE_R"; }
