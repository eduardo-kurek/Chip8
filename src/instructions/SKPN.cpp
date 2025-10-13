#include "instructions/SKPN.h"
#include "VirtualMachine.h"
#include <iostream>

void SKPN::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    auto vx = vm.V[x];
    auto key = vm.keys[vx];
    if(!key)
        vm.programCounter.IncrementAddress();
}

std::string SKPN::GetName() const{ return "SKPN"; }