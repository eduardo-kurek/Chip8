#include "instructions/LD_I.h"
#include <cstdio>

void LD_I::DoExecute(Context& ctx) const{
    ctx.I = ctx.V[opCode.NNN()];
}

std::string LD_I::GetName() const{ return "LD_I"; }
