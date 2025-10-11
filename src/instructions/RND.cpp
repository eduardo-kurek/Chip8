#include "instructions/RND.h"
#include <cstdio>

void RND::DoExecute(Context& ctx) const{
    ctx.V[opCode.X()] = (rand() % 256) & opCode.NN();
}

std::string RND::GetName() const{ return "RND"; }
