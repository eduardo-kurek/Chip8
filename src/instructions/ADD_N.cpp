#include "instructions/ADD_N.h"
#include <cstdio>

void ADD_N::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] += opCode.NN();
}

std::string ADD_N::GetName() const{ return "ADD_N"; }
