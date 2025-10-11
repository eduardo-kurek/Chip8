#include "instructions/SE_R.h"
#include <cstdio>

void SE_R::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] == ctx.V[opCode.Y()])
        ctx.programCounter.IncrementAddress();
}

std::string SE_R::GetName() const{ return "SE_R"; }
