#include "instructions/RET.h"
#include "VirtualMachine.h"
#include <iostream>

void RET::DoExecute(VirtualMachine& vm) const{
    vm.stackPointer--;
    vm.pc = vm.stack[vm.stackPointer];
}

std::string RET::GetName() const{ return "RET"; }