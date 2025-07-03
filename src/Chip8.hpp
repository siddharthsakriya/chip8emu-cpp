#pragma once
#include "Memory.hpp"

#include <array>
#include <cstdint>
#include <string>

using Instruction = uint16_t;

class Chip8 {
public:
    Chip8();
    void initialise();
    void loadGame(const std::string& filename);
    void emulateCycle();    
    Instruction readInstruction();

private:
    // general purpose registers
    std::array<uint16_t, 16> V{};

    // index register
    uint16_t I; 
    
    // time + sound registers
    uint8_t DT;
    uint8_t ST;

    // pc and sp 
    uint16_t PC; 
    uint8_t SP; 

    // memory + stack
    Memory memory;
    void decodeAndExecute(Instruction instruction);
    void handle0group(uint16_t nnn);
    void handle8group(uint8_t n, uint8_t x, uint8_t y);
};