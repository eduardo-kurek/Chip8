#include "instructions/LD_B.h"
#include "VirtualMachine.h"
#include <cstdio>

void LD_B::DoExecute(VirtualMachine& vm) const{
    auto x = opCode.X();
    auto vx = vm.V[x];
    auto i = vm.I;

    auto h = vx / 100;
    auto t = (vx - h * 100) / 10;
    auto o = vx - h * 100 - t * 10;

    vm.mem.WriteMem(i, h);
    vm.mem.WriteMem(i + 1, t);
    vm.mem.WriteMem(i + 2, o);
}

std::string LD_B::GetName() const{ return "LD_B"; }
