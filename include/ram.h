//
// Created by holzel on 5/19/22.
//

#include <cstdint>
#include <string>
#include <fstream>


class ram {
private:
    uint8_t *bytes;
    uint16_t start; // where it begins in memory
    uint8_t  reg; // boot register
    bool enabled; // is boot enabled
    bool is_boot; // is this boot or other type or ram
public:
    ram(uint16_t size, uint16_t start);
    ram(std::string filename);
    void set_start_addr(uint16_t val);
    void set_bt_reg(uint8_t val);
    void set_bt_enable(bool val);
    void set_is_boot(bool val);
    uint8_t read_ram(uint16_t addr);
    void write_to_ram(uint16_t addr, uint8_t val);
    bool ram_contains(uint16_t addr);
    bool boot_contains(uint16_t addr);
    uint8_t read_boot(uint16_t addr);
    void write_to_boot(uint16_t addr, uint8_t val);
    uint16_t get_start_addr();
    uint8_t get_bt_reg();
    bool bt_enabled();
    bool is_bt();
};