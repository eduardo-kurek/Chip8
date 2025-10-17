#include "instructions/XOR_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void XOR_R::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] ^= vm.V[opCode.Y()];
}

std::string XOR_R::GetName() const{ return "XOR_R"; }
