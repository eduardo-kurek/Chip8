#include "instructions/LD_B.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_B::DoExecute(VirtualMachine& vm) const{
    auto h = vm.V[opCode.X()] / 100;
    auto t = (vm.V[opCode.X()] - h * 100) / 10;
    auto o = vm.V[opCode.X()] - h * 100 - t * 10;

    vm.mem.WriteMem(vm.I, h);
    vm.mem.WriteMem(vm.I + 1, t);
    vm.mem.WriteMem(vm.I + 2, o);
}

std::string LD_B::GetName() const{ return "LD_B"; }
