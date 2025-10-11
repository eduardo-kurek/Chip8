#include "instructions/AND_R.h"
#include <cstdio>

void AND_R::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] &= ctx.V[opCode.Y()];
}

std::string AND_R::GetName() const{ return "AND_R"; }
