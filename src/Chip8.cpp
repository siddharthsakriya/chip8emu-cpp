#include "Chip8.hpp"

Chip8::Chip8() {
    initialise();
}

void Chip8::initialise() {
    I = 0;
    DT = 0, ST = 0;
    PC = 0x0200, SP = 0;
}

Instruction Chip8::readInstruction() {
    uint8_t byte1 = memory.readByte(PC);
    uint8_t byte2 = memory.readByte(PC);

    PC += 2; 
    
    return (static_cast<Instruction>(byte1) << 8) | static_cast<Instruction>(byte2);
}

void Chip8::decodeAndExecute(Instruction instruction) {
    
    // bitmask to get opcode, nnn, x, kk
    uint16_t opcode = instruction & 0xF000; 
    uint16_t nnn = instruction & 0x0FFF;   
    uint8_t x = (instruction & 0x0F00) >> 8;
    uint8_t y = (instruction & 0x00F0) >> 4;
    uint8_t kk = instruction & 0x00FF;      
    uint8_t n = instruction & 0x000F;       

    // match on opcode, and then provide logic, or call to function 
    switch (opcode) {
        case 0x0000: 
            break;
        case 0x1000:            
            break;
        case 0x2000:
            break;
        case 0x3000:
            break;
        case 0x4000:
            break;
        case 0x5000:
            break;
        case 0x6000:
            break;
        case 0x7000:
            break;
        case 0x8000:
            break;  
        case 0x9000:
            break;
        case 0xA000:
            break;
        case 0xB000:
            break;
        case 0xC000:
            break;
        case 0xD000:
            break;
        case 0xE000:
            break;
    }
}

void Chip8::emulateCycle() {
    // read instruction from memory 
    Instruction instruction = readInstruction();    
    decodeAndExecute(instruction);
    
    // decode and execute instruction
}




    


