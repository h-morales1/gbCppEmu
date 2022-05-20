//
// Created by holzel on 5/19/22.
//

#include "ram.h"
#include <vector>
#include <algorithm>

class mmu {
public:
    std::vector<ram> mem_slices;
    //std::vector<ram>::iterator it = mem_slices.begin();
    bool mem_contains(uint16_t addr);
    uint8_t mem_read(uint16_t addr);
    void mem_write(uint16_t addr, uint8_t val);
    //std::vector<ram>::iterator is_found = [it]() { *it->ram_contains()};
};