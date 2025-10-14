#include "instructions/SHL_R.h"
#include "VirtualMachine.h"
#include <cstdio>

void SHL_R::DoExecute(VirtualMachine& vm) const {
    vm.V[opCode.X()] = vm.V[opCode.Y()];

    uint8_t shiftedBit = vm.V[opCode.X()] & 0x80;

    vm.V[opCode.X()] = vm.V[opCode.X()] << 1;

    vm.V[0xF] = shiftedBit >> 7;
}

std::string SHL_R::GetName() const { return "SHL_R"; }
