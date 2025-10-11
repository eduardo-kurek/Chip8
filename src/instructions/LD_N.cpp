#include "instructions/LD_N.h"
#include <cstdio>

void LD_N::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] = opCode.NN();
}

std::string LD_N::GetName() const{ return "LD_N"; }
