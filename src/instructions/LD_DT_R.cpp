#include "instructions/LD_DT_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_DT_R::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    vm.V[x] = vm.delayTimer.GetValue();
}

std::string LD_DT_R::GetName() const{ return "LD_DT_R"; }
