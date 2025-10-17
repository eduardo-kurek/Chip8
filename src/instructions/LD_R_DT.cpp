#include "instructions/LD_R_DT.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_R_DT::DoExecute(VirtualMachine& vm) const{
    vm.delayTimer.SetValue(vm.V[opCode.X()]);
}

std::string LD_R_DT::GetName() const{ return "LD_R_DT"; }
