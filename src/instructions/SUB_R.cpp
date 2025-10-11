#include "instructions/SUB_R.h"
#include <cstdio>

void SUB_R::DoExecute(Context& ctx) const{
    if (ctx.V[opCode.X()] > ctx.V[opCode.Y()])
        ctx.V[0xF] = 1;  
    else
        ctx.V[0xF] = 0;
        
    ctx.V[opCode.X()] -= ctx.V[opCode.Y()];
}

std::string SUB_R::GetName() const{ return "SUB_R"; }
