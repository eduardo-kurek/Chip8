#pragma once

#include <functional>
#include <memory>
#include <concepts>
#include "Chip8.h"
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
public:
    Instruction(const OpCode& opCode) : opCode(opCode) {}
    virtual void Execute(Chip8& vm) const = 0;

    template<InstructionLike T>
    static InstructionCreator GetFactoryOf() {
        return [](const OpCode& opcode) -> std::unique_ptr<Instruction> {
            return std::make_unique<T>(opcode);
        };
    }
};
