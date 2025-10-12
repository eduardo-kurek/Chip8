#include "instructions/CLS.h"
#include "VirtualMachine.h"
#include <cstdio>

void CLS::DoExecute(VirtualMachine& vm) const{
    vm.display.Clear();
}

std::string CLS::GetName() const{ return "CLS"; }
