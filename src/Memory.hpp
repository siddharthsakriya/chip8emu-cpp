#pragma once
#include <cstdint>

class Memory {
    private:
        uint8_t memory[4096]; 
        uint16_t stack[16];
    public:
        // push value to stack
        void pushToStack(uint16_t value, uint8_t& sp){
            if (sp < 16) {
                stack[sp++] = value;
            };
        };

        // pop value from stack
        uint16_t popFromStack(uint8_t& sp) {
            if (sp > 0) {
                return stack[--sp];
            };
            return 0;
        }

        // read byte from memory
        uint8_t readByte(uint16_t address) {
            if (address < 4096) {
                return memory[address];
            }
            return 0;
        };

        // write byte to memory 
        void writeByte(uint16_t address, uint8_t value) {
            if (address < 4096) {
                memory[address] = value;
            }
        };
};