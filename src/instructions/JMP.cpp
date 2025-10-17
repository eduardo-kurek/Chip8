#include "instructions/JMP.h"
#include "VirtualMachine.h"
#include <cstdio>

void JMP::DoExecute(VirtualMachine& vm) const{
    vm.programCounter.SetAddress(opCode.NNN());
}

std::string JMP::GetName() const{ return "JMP"; }
