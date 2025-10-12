#include "Context.h"
#include <cstdint>
#include <iostream>
#include <fstream>

std::ostream &operator<<(std::ostream& os, const Context& ctx){
    os << "Context State:\n";
    os << "PC: " << std::hex << ctx.programCounter.GetAddress() << "\n";
    os << "I: " << std::hex << ctx.I << "\n";
    os << "Registers: ";
    for(int i = 0; i < ctx.V.size(); ++i)
    os << std::hex << static_cast<int>(ctx.V[i]) << " ";
    os << "\n";
    os << "Stack: ";
    for(int i = 0; i < ctx.stack.size(); ++i)
    os << std::hex << ctx.stack[i] << " ";
    os << "SP: " << std::hex << static_cast<int>(ctx.stackPointer) << "\n";
    os << "\n";
    return os;
}
