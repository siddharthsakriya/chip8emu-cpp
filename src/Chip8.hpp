#pragma once
#include <cstdint>
#include <string>

using Instruction = uint16_t;

class Chip8 {
private:
    // memory: 4KB of memory
    
public:
    Chip8();
    void initialize();
    void execute();
    void loadGame(const std::string& filename);
    void emulateCycle();
};