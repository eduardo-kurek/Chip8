#pragma once

#include <functional>
#include <memory>
#include <concepts>
#include "OpCode.h"

class VirtualMachine;
class Instruction;

using InstructionCreator = std::function<std::unique_ptr<Instruction>(const OpCode&)>;

template<typename T>
concept InstructionLike = 
    std::derived_from<T, Instruction> &&
    std::constructible_from<T, const OpCode&>;

class Instruction {
protected:
    OpCode opCode;
    virtual void DoExecute(VirtualMachine& vm) const = 0;
    void PrintExecutionDebugInfo(const VirtualMachine& vm) const;

public:
    Instruction(const OpCode& opCode) : opCode(opCode) {}
    void Execute(VirtualMachine& vm) const;
    virtual std::string GetName() const;

    template<InstructionLike T>
    static InstructionCreator GetFactoryOf() {
        return [](const OpCode& opcode) -> std::unique_ptr<Instruction> {
            return std::make_unique<T>(opcode);
        };
    }
};
