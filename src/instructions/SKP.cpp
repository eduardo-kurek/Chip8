#include "instructions/SKP.h"
#include "VirtualMachine.h"
#include <iostream>

void SKP::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    auto vx = vm.V[x];
    auto key = vm.keys[vx];
    if(key)
        vm.programCounter.IncrementAddress();
}

std::string SKP::GetName() const{ return "SKP"; }