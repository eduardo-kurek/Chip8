#include "instructions/JMP_V0.h"
#include <cstdio>

void JMP_V0::DoExecute(Context& ctx) const{
    ctx.programCounter.SetAddress(opCode.NNN() + ctx.stack[0x0]);
}

std::string JMP_V0::GetName() const{ return "JMP_V0"; }
