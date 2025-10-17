#include "instructions/RND.h"
#include "VirtualMachine.h"
#include <cstdio>

void RND::DoExecute(VirtualMachine& vm) const{
    vm.V[opCode.X()] = (rand() % 256) & opCode.NN();
}

std::string RND::GetName() const{ return "RND"; }
