#include "instructions/Instruction.h"
#include "VirtualMachine.h"
#include <iomanip>

void Instruction::Execute(VirtualMachine& vm) const{
    DoExecute(vm);
    PrintExecutionDebugInfo(vm);
}

void Instruction::PrintExecutionDebugInfo(const VirtualMachine& vm) const{
    #ifdef DEBUG
        std::cout << "Executed " << GetName() << " (";
        std::cout << std::hex << std::setfill('0');
        std::cout << std::setw(4) << opCode.Code();
        std::cout << " at address ";
        std::cout << std::setw(4) << vm.programCounter.GetAddress();
        std::cout << ")" << std::endl;
        std::cout << std::setfill(' ') << std::dec;
    #endif
}

std::string Instruction::GetName() const{ return "Unnamed"; }
