#include "instructions/SE_N.h"
#include <cstdio>

void SE_N::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] == opCode.NN())
        ctx.programCounter.IncrementAddress();
}

std::string SE_N::GetName() const{ return "SE_N"; }
