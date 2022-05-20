//
// Created by holzel on 5/20/22.
//

#include "../include/mmu.h"

bool mmu::mem_contains(uint16_t addr)
{
    // check if any of the mem slices in vector contain the addr passed in
    auto it = std::find_if(mem_slices.begin(), mem_slices.end(), [addr](ram &obj) { return obj.ram_contains(addr); });
    if(it == mem_slices.end())
    {
        //it reached the end so not found
        return false;
    }
    return true;

}
uint8_t mmu::mem_read(uint16_t addr)
{
    if(mem_contains(addr))
    {
        auto it = std::find_if(mem_slices.begin(), mem_slices.end(), [addr](ram &obj) { return obj.ram_contains(addr); });
        return it->read_ram(addr);
    }
    return 0xFF;
}
void mmu::mem_write(uint16_t addr, uint8_t val)
{
    if(mem_contains(addr))
    {
        //
        auto it = std::find_if(mem_slices.begin(), mem_slices.end(), [addr](ram &obj) { return obj.ram_contains(addr); });
        it->write_to_ram(addr, val);
    }
}
