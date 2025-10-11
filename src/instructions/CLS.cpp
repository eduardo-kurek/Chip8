#include "instructions/CLS.h"
#include <cstdio>

void CLS::DoExecute(Context& ctx) const{
    ctx.DISPLAY.fill(0);
}

std::string CLS::GetName() const{ return "CLS"; }
