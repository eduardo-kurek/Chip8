#include "instructions/LD_I_Rs.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_I_Rs::DoExecute(VirtualMachine& vm) const{
    for (int i = 0; i < opCode.X(); i++)
        vm.mem.WriteMem(vm.I + i, vm.V[i]);
}

std::string LD_I_Rs::GetName() const{ return "LD_I_Rs"; }
