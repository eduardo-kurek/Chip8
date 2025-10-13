#include "instructions/LD_R_ST.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_R_ST::DoExecute(VirtualMachine& vm) const{
    vm.soundTimer.SetValue(vm.V[opCode.X()]);
}

std::string LD_R_ST::GetName() const{ return "LD_R_ST"; }
