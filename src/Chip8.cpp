#include "Chip8.hpp"

Chip8::Chip8() {
    initialise();
}

void Chip8::initialise() {
    I = 0;
    DT = 0, ST = 0;
    PC = 0x0200, SP = 0;
}





    


