#include "instructions/OR_R.h"
#include <cstdio>

void OR_R::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] |= ctx.V[opCode.Y()];
}

std::string OR_R::GetName() const{ return "OR_R"; }
