#include "instructions/LD_K.h"
#include "VirtualMachine.h"
#include <cstdio>
#include <cstdio>

void LD_K::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    VirtualMachine::OnInputReceived callback = [x, &vm](uint8_t key){
        vm.V[x] = key;
    };
    vm.WaitForInput(callback);
}

std::string LD_K::GetName() const{ return "LD_K"; }
