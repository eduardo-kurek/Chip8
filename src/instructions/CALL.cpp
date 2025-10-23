#include "instructions/CALL.h"
#include "VirtualMachine.h"
#include <cstdio>

void CALL::DoExecute(VirtualMachine& vm) const{
    vm.stack[vm.stackPointer] = vm.pc;
    vm.stackPointer++;
    vm.pc = opCode.NNN();
}

std::string CALL::GetName() const{ return "CALL"; }
