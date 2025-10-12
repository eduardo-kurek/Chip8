#include "instructions/ADD_R.h"
#include <cstdio>

void ADD_R::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] + ctx.V[opCode.Y()] > 0xFF)
        ctx.V[0xF] = 1;  
    else
        ctx.V[0xF] = 0;

    ctx.V[opCode.X()] += ctx.V[opCode.Y()];
}

std::string ADD_R::GetName() const{ return "ADD_R"; }
