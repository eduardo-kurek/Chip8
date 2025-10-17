#include "instructions/ADD_I.h"
#include "VirtualMachine.h"
#include <cstdio>

void ADD_I::DoExecute(VirtualMachine& vm) const{
    vm.I += vm.V[opCode.X()];
}

std::string ADD_I::GetName() const{ return "ADD_I"; }
