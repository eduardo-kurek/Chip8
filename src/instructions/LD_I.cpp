#include "instructions/LD_I.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_I::DoExecute(VirtualMachine& vm) const{
    vm.I = opCode.NNN();
}

std::string LD_I::GetName() const{ return "LD_I"; }
