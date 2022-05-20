//
// Created by holzel on 5/20/22.
//

#include "../include/cpu.h"

cpu::cpu()
{
    ram boot_rom = ram("DMG_ROM.bin"); //
    ram n_ram = ram(0x8000, (0xFFFF - 0x8000));
    A = 0x0;
    F = 0x0;
    B = 0x0;
    C = 0x0;
    D = 0x0;
    E = 0x0;
    H = 0x0;
    L = 0x0;

    flag_C = 0x10;
    flag_H = 0x20;
    flag_N = 0x40;
    flag_Z = 0x80;

    PC = 0x0;
    SP = 0x0;

    memU.mem_slices.push_back(boot_rom);
    memU.mem_slices.push_back(n_ram);
}

void cpu::set_regX(uint8_t *regX, uint8_t val)
{
    *regX = val;
}
void cpu::set_regXY(uint8_t *regX, uint8_t *regY, uint16_t val)
{
    *regX = (val & 0xFF00) >> 8;
    *regY = (val & 0xFF);
}
void cpu::set_PC(uint16_t val)
{
    PC = val;
}
void cpu::set_SP(uint16_t val)
{
    SP = val;
}
void cpu::increment_PC(uint16_t val)
{
    PC += val;
}
void cpu::increment_SP(uint16_t val)
{
    SP += val;
}
void cpu::decrement_PC(uint16_t val)
{
    PC -= val;
}
void cpu::decrement_SP(uint16_t val)
{
    SP -= val;
}
uint8_t cpu::get_regX(uint8_t *regX)
{
    return *regX;
}
uint16_t cpu::get_regXY(uint8_t *regX, uint8_t *regY)
{
    uint8_t byte1 = get_regX(regX);
    uint8_t byte2 = get_regX(regY);
    uint16_t combined = (byte1 << 8) | byte2;
    return combined;
}
uint16_t cpu::get_PC()
{
    return PC;
}
uint16_t cpu::get_SP()
{
    return SP;
}
void cpu::emulate()
{
    uint8_t opcode = memU.mem_read(PC);
    increment_PC(1);
    uint8_t first_byte = memU.mem_read(PC);
    std::cout << "OPCODE Combo: " << (int)((opcode << 8) | first_byte) << std::endl;
    std::cout << "OPCODE: " << (int)((opcode)) << std::endl;
    switch(opcode)
    {
        case 0x31: std::cout << "IMPLEMENT LD SP, d16" << std::endl;  increment_PC(2); break;
        default: std::cout << "Error: Opcode: " << (int)opcode << " not yet implemented!" << std::endl; exit(2);
    }
}