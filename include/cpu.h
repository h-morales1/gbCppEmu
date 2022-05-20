//
// Created by holzel on 5/20/22.
//

//#include "ram.h"
#include "mmu.h"
#include <iostream>

class cpu {
private:
    uint8_t A; // registers
    uint8_t F;
    uint8_t B;
    uint8_t C;
    uint8_t D;
    uint8_t E;
    uint8_t H;
    uint8_t L;
    // flags
    uint8_t flag_C;
    uint8_t flag_H;
    uint8_t flag_N;
    uint8_t flag_Z;
    // program counter and stack pointer
    uint16_t PC;
    uint16_t SP;
    mmu memU;
    //ram boot_rom;
public:
    cpu();
    void set_regX(uint8_t *regX, uint8_t val);
    void set_regXY(uint8_t *regX, uint8_t *regY, uint16_t val);
    void set_PC(uint16_t val);
    void set_SP(uint16_t val);
    void increment_PC(uint16_t val);
    void increment_SP(uint16_t val);
    void decrement_PC(uint16_t val);
    void decrement_SP(uint16_t val);
    uint8_t get_regX(uint8_t *regX);
    uint16_t get_regXY(uint8_t *regX, uint8_t *regY);
    uint16_t get_PC();
    uint16_t get_SP();
    void emulate();
};