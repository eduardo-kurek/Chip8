#include "instructions/JMP.h"
#include "VirtualMachine.h"
#include <cstdio>

void JMP::DoExecute(VirtualMachine& vm) const{
    vm.pc = opCode.NNN();
}

std::string JMP::GetName() const{ return "JMP"; }
