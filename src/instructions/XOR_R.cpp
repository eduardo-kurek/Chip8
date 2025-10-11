#include "instructions/XOR_R.h"
#include <cstdio>

void XOR_R::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] ^= ctx.V[opCode.Y()];
}

std::string XOR_R::GetName() const{ return "XOR_R"; }
