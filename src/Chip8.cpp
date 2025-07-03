#include "Chip8.hpp"
#include <iostream>

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
            handle0group(nnn);
            break;

        case 0x1000: 
            // JP addr
            PC = nnn;
            break;
       
        case 0x2000:
            // CALL addr
            memory.pushToStack(PC, SP);
            PC = nnn;
            break;

        case 0x3000:
            // SE Vx, byte
            if (V[x] == kk) {
                PC += 2; // skip next instruction
            }
            break;

        case 0x4000:
            // SNE Vx, byte
            if (V[x] != kk) {
                PC += 2; // skip next instruction
            }
            break;
        
        case 0x5000:
            // SE Vx, Vy
            if (V[x] == V[y]) {
                PC += 2; // skip next instruction
            }
            break;
        
        case 0x6000:
            // LD Vx, byte
            V[x] = kk; 
            break;
        
        case 0x7000:
            // ADD Vx, byte
            V[x] += kk;
            break;

        case 0x8000:
            handle8group(n, x, y);
            break;
        
        case 0x9000:
            // SNE Vx, Vy
            if (V[x] != V[y]) {
                PC += 2; // skip next instruction
            }
            break;
        
        case 0xA000:
            // LD I, addr
            I = nnn; 
            break;

        case 0xB000:
            // JP V0, addr
            uint16_t target = nnn + V[0]; 
            PC = target;
            break;
        
        case 0xC000:
            // RND Vx, byte
            V[x] = (rand() % 256) & kk; 
            break;

        case 0xD000:
            // DRW Vx, Vy, nibble
            break;

        case 0xE000:
            // handle E group opcodes
            break;
        
        case 0xF000:
            break;
        
        default:
            std::cerr << "Unknown opcode: " << std::hex << instruction << std::dec << std::endl;
            break;
    }
}

void Chip8::handle0group(uint16_t nnn) {
    switch (nnn) {
        case 0x00E0: 
            // CLS
            break;

        case 0x00EE:
            // RET
            break;

        default:
            // SYS addr
            break;
    }
}

void Chip8::handle8group(uint8_t n, uint8_t x, uint8_t y) {
    switch (n)
    {
    case 0x0:
        // LD Vx, Vy
        V[x] = V[y];
        break;
    
    case 0x1:
        // OR Vx, Vy
        V[x] |= V[y];
        break;
    
    case 0x2:
        // AND Vx, Vy
        V[x] &= V[y];
        break;
    
    case 0x3:
        // XOR Vx, Vy
        V[x] ^= V[y];
        break;
    
    case 0x4:
        // ADD Vx, Vy
        // TODO: flag setting
        V[x] += V[y];
    
    case 0x5:
        // SUB Vx, Vy
        // TODO: flag setting
        V[x] -= V[y];
    
    case 0x6:
        // SHR Vx {, Vy}
        V[x] >>= 1;
    
    case 0x7:
        // SUBN Vx, Vy
        V[x] = V[y] - V[x];
    case 0xE:
        // SHL Vx {, Vy}
        V[x] <<= 1;
        break;
    default:
        break;
    }
}

void Chip8::emulateCycle() {
    // read instruction from memory 
    Instruction instruction = readInstruction();    
    decodeAndExecute(instruction);
    
    // decode and execute instruction
}




    


