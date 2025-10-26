#include "VirtualMachine.h"
#include "Decoder.h"
#include <exception>
#include <cstdint>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>

std::ostream &operator<<(std::ostream& os, const VirtualMachine& vm){
    os << "Virtual Machine State:\n";
    os << "PC: " << std::hex << vm.pc << "\n";
    os << "I: " << std::hex << vm.I << "\n";
    os << "Registers: ";
    for(int i = 0; i < vm.V.size(); ++i)
    os << std::hex << static_cast<int>(vm.V[i]) << " ";
    os << "\n";
    os << "Stack: ";
    for(int i = 0; i < vm.stack.size(); ++i)
    os << std::hex << vm.stack[i] << " ";
    os << "SP: " << std::hex << static_cast<int>(vm.stackPointer) << "\n" << std::dec;
    return os;
}

VirtualMachine::VirtualMachine(std::string romPath, uint16_t initAddress)
    : mem(romPath), pc(initAddress), decoder(Decoder::Instance()) {
    std::srand(std::time(0));
}

void VirtualMachine::ExecuteNextInstruction(){
    uint16_t nextInstruction = mem.FetchInstruction(pc++);
    OpCode opCode(nextInstruction);
    Execute(opCode);
}

void VirtualMachine::Execute(const OpCode& opCode){
    uint16_t address = pc;
    auto inst = decoder.Decode(opCode);
    if(inst)
        inst->Execute(*this);
    else
        std::cerr << "Unknown opcode: (" << std::hex << std::setfill('0') << 
        std::setw(4) << opCode.Code() << " at address " << address <<
        std::dec << std::setfill(' ') << ")" << std::endl;
}

void VirtualMachine::PressKey(uint8_t key){
    if(key > 15)
        throw std::out_of_range("Key out of range");
    #ifdef DEBUG
        std::cout << "Key pressed: " << (int)key << std::endl;
    #endif
    keys[key] = true;
}

void VirtualMachine::ReleaseKey(uint8_t key){
    if(key > 15)
    throw std::out_of_range("Key out of range");
    #ifdef DEBUG
    std::cout << "Key released: " << (int)key << std::endl;
    #endif
    keys[key] = false;
    
    if(waitingForInput)
        InputReceived(key);
}

void VirtualMachine::WaitForInput(OnInputReceived callback){
    this->waitingForInput = true;
    this->callback = callback;
}

bool VirtualMachine::NotWaitingForInput() const{ return !waitingForInput; }

void VirtualMachine::DecrementTimers(){
    delayTimer.Decrement();
    soundTimer.Decrement();
}

void VirtualMachine::InputReceived(uint8_t key){
    waitingForInput = false;
    if(callback)
        callback(key);
    callback = nullptr;
}
