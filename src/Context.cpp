#include "Context.h"
#include <cstdint>
#include <iostream>
#include <fstream>

std::ostream &operator<<(std::ostream& os, const Context& ctx){
    os << "Context State:\n";
    os << "PC: " << std::hex << ctx.programCounter.GetAddress() << "\n";
    os << "I: " << std::hex << ctx.I << "\n";
    os << "SP: " << std::hex << static_cast<int>(ctx.stackPointer) << "\n";
    os << "Registers: ";
    for(int i = 0; i < ctx.V.size(); ++i)
        os << std::hex << static_cast<int>(ctx.V[i]) << " ";
    os << "\n";
    return os;
}
