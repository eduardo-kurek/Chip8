#include "instructions/SUBN_R.h"
#include <cstdio>

void SUBN_R::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.Y()] > ctx.V[opCode.X()])
        ctx.V[0xF] = 1;  
    else
        ctx.V[0xF] = 0;
        
    ctx.V[opCode.X()] = ctx.V[opCode.Y()] - ctx.V[opCode.X()];
}

std::string SUBN_R::GetName() const{ return "SUBN_R"; }
