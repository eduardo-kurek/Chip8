#include "instructions/LD_I_Rs.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_I_Rs::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    for (int i = 0; i <= x; i++){
        vm.mem.WriteMem(vm.I + i, vm.V[i]);
    }

    vm.I += (x + 1); 
}

std::string LD_I_Rs::GetName() const{ return "LD_I_Rs"; }
