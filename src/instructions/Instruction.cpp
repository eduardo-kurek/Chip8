#include "instructions/Instruction.h"
#include <iomanip>

void Instruction::Execute(Context& ctx) const{
    DoExecute(ctx);
    PrintExecutionDebugInfo(ctx);
}

void Instruction::PrintExecutionDebugInfo(const Context& ctx) const{
    #ifdef DEBUG
        std::cout << "Executed " << GetName() << " (";
        std::cout << std::hex << std::setfill('0');
        std::cout << std::setw(4) << opCode.Code();
        std::cout << " at address ";
        std::cout << std::setw(4) << ctx.programCounter.GetAddress();
        std::cout << ")" << std::endl;
        std::cout << std::setfill(' ') << std::dec;
    #endif
}

std::string Instruction::GetName() const{ return "Unnamed"; }
