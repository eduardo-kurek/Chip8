#pragma once

#include <functional>
#include <memory>
#include <concepts>
#include "Context.h"
#include "OpCode.h"

class Instruction;
using InstructionCreator = std::function<std::unique_ptr<Instruction>(const OpCode&)>;

template<typename T>
concept InstructionLike = 
    std::derived_from<T, Instruction> &&
    std::constructible_from<T, const OpCode&>;

class Instruction {
protected:
    OpCode opCode;
    virtual void DoExecute(Context& ctx) const = 0;
    void PrintExecutionDebugInfo(const Context& ctx) const;

public:
    Instruction(const OpCode& opCode) : opCode(opCode) {}
    void Execute(Context& ctx) const;
    virtual std::string GetName() const;

    template<InstructionLike T>
    static InstructionCreator GetFactoryOf() {
        return [](const OpCode& opcode) -> std::unique_ptr<Instruction> {
            return std::make_unique<T>(opcode);
        };
    }
};
