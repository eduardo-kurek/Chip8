#include "instructions/SNE_N.h"
#include <cstdio>

void SNE_N::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] != opCode.NN())
        ctx.programCounter.IncrementAddress();
}

std::string SNE_N::GetName() const{ return "SNE_N"; }
