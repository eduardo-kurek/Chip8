#include "VirtualMachine.h"
#include "Decoder.h"
#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>

std::ostream &operator<<(std::ostream& os, const VirtualMachine& vm){
    os << "Virtual Machine State:\n";
    os << "PC: " << std::hex << vm.programCounter.GetAddress() << "\n";
    os << "I: " << std::hex << vm.I << "\n";
    os << "Registers: ";
    for(int i = 0; i < vm.V.size(); ++i)
    os << std::hex << static_cast<int>(vm.V[i]) << " ";
    os << "\n";
    os << "Stack: ";
    for(int i = 0; i < vm.stack.size(); ++i)
    os << std::hex << vm.stack[i] << " ";
    os << "SP: " << std::hex << static_cast<int>(vm.stackPointer) << "\n";
    return os;
}

void VirtualMachine::ExecuteNextInstruction(){
    uint16_t address = programCounter.GetAddress();
    OpCode opCode(mem.FetchInstruction(address));
    programCounter.IncrementAddress();
    Execute(std::move(opCode));
}

void VirtualMachine::Execute(const OpCode& opCode){
    uint16_t address = programCounter.GetAddress();
    auto inst = decoder.Decode(opCode);
    if(inst)
        inst->Execute(*this);
    else
        std::cerr << "Unknown opcode: (" << std::hex << std::setfill('0') << 
        std::setw(4) << opCode.Code() << " at address " << address <<
        std::dec << std::setfill(' ') << ")" << std::endl;
}
