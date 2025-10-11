#include "instructions/SHL_R.h"
#include <cstdio>

void SHL_R::DoExecute(Context& ctx) const {
    ctx.V[0xF] = (ctx.V[opCode.X()] & 0x80);
    ctx.V[opCode.X()] = ctx.V[opCode.X()] << 1;
}

std::string SHL_R::GetName() const { return "SHL_R"; }
