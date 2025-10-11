#include "instructions/LD_R.h"
#include <cstdio>

void LD_R::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] = ctx.V[opCode.Y()];
}

std::string LD_R::GetName() const{ return "LD_R"; }
