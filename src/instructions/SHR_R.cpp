#include "instructions/SHR_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SHR_R::DoExecute(VirtualMachine& vm) const {
    vm.V[opCode.X()] = vm.V[opCode.Y()];

    uint8_t shiftedBit = vm.V[opCode.X()] & 0x1;

    vm.V[opCode.X()] = vm.V[opCode.X()] >> 1;

    vm.V[0xF] = shiftedBit;
}

std::string SHR_R::GetName() const { return "SHR_R"; }
