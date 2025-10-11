#include "instructions/SNE_R.h"
#include <cstdio>

void SNE_R::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] != ctx.V[opCode.Y()])
        ctx.programCounter.IncrementAddress();
}

std::string SNE_R::GetName() const{ return "SNE_R"; }
