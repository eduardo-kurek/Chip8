#include "instructions/LD_I_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_I_R::DoExecute(VirtualMachine& vm) const{
    vm.I = (opCode.X() * 0x05);
}

std::string LD_I_R::GetName() const{ return "LD_I_R"; }
