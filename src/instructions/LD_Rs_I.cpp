#include "instructions/LD_Rs_I.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_Rs_I::DoExecute(VirtualMachine& vm) const{
    for (int i = 0; i < opCode.X(); i++)
        vm.V[i] = vm.mem.GetMem(vm.I + i);
}

std::string LD_Rs_I::GetName() const{ return "LD_Rs_I"; }
