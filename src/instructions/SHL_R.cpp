#include "instructions/SHL_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SHL_R::DoExecute(VirtualMachine& vm) const {
    vm.V[0xF] = (vm.V[opCode.X()] & 0x80);
    vm.V[opCode.X()] = vm.V[opCode.X()] << 1;
}

std::string SHL_R::GetName() const { return "SHL_R"; }
