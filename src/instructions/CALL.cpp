#include "instructions/CALL.h"
#include "VirtualMachine.h"
#include <cstdio>

void CALL::DoExecute(VirtualMachine& vm) const{
    vm.stackPointer++;
    vm.stack[vm.stackPointer] = vm.programCounter.GetAddress();
    vm.programCounter.SetAddress(opCode.NNN());
}

std::string CALL::GetName() const{ return "CALL"; }
