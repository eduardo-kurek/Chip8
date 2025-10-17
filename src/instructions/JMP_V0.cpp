#include "instructions/JMP_V0.h"
#include "VirtualMachine.h"
#include <cstdio>

void JMP_V0::DoExecute(VirtualMachine& vm) const{
    vm.programCounter.SetAddress(opCode.NNN() + vm.V[0x0]);
}

std::string JMP_V0::GetName() const{ return "JMP_V0"; }
