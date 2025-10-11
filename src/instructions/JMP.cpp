#include "instructions/JMP.h"
#include <cstdio>

void JMP::DoExecute(Context& ctx) const{
    ctx.programCounter.SetAddress(opCode.NNN());
}

std::string JMP::GetName() const{ return "JMP"; }
