#include "instructions/RET.h"
#include <iostream>

void RET::DoExecute(Context& ctx) const{
    ctx.programCounter.SetAddress(ctx.stack[ctx.stackPointer]);
}

std::string RET::GetName() const{ return "RET"; }