#include "instructions/CALL.h"
#include "VirtualMachine.h"
#include <cstdio>

void CALL::DoExecute(VirtualMachine& vm) const{
    vm.stack[vm.stackPointer] = vm.programCounter.GetAddress();
    vm.stackPointer++;
    vm.programCounter.SetAddress(opCode.NNN());
}

std::string CALL::GetName() const{ return "CALL"; }
