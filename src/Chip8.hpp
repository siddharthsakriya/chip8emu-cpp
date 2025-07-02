#pragma once
#include "Memory.hpp"

#include <cstdint>
#include <string>
using Instruction = uint16_t;

class Chip8 {
private:
    // general purpose registers
    uint8_t V[16];

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

public:
    Chip8();
    void initialize();
    void execute();
    void loadGame(const std::string& filename);
    void emulateCycle();
};