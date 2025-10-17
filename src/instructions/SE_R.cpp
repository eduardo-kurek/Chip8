#include "instructions/SE_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SE_R::DoExecute(VirtualMachine& vm) const{
    if (vm.V[opCode.X()] == vm.V[opCode.Y()])
        vm.programCounter.IncrementAddress();
}

std::string SE_R::GetName() const{ return "SE_R"; }
