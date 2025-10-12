#include "instructions/SHR_R.h"
#include <cstdio>

void SHR_R::DoExecute(Context& ctx) const {
    ctx.V[0xF] = ctx.V[opCode.X()] & 0x1;
    ctx.V[opCode.X()] = ctx.V[opCode.X()] >> 1;
}

std::string SHR_R::GetName() const { return "SHR_R"; }
