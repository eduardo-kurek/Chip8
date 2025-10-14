#include "instructions/LD_Rs_I.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_Rs_I::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    for (int i = 0; i <= x; i++)
        vm.V[i] = vm.mem.GetMem(vm.I + i);

    vm.I += (x + 1); 
}

std::string LD_Rs_I::GetName() const{ return "LD_Rs_I"; }
