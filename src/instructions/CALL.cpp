#include "instructions/CALL.h"
#include <cstdio>

void CALL::DoExecute(Context& ctx) const{
    ctx.stackPointer++;
    ctx.stack[ctx.stackPointer] = ctx.programCounter.GetAddress();
    ctx.programCounter.SetAddress(opCode.NNN());
}

std::string CALL::GetName() const{ return "CALL"; }
