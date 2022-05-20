//
// Created by holzel on 5/19/22.
//

#include "../include/ram.h"
#include <iostream>
#include <iomanip>

ram::ram(uint16_t size, uint16_t ra_start)
{
    start = ra_start;
    bytes = new uint8_t[size];
    is_boot = false;
    enabled = false; // doesnt matter since its not a boot rom
}

ram::ram(std::string filename)
{
// load boot rom
    start = 0;
    is_boot = true;

    std::fstream  file (filename, std::ios::in | std::ios::binary | std::ios::out);

    if(!file)
    {
        perror("Error: Could not open boot rom");
        exit(1);
    }

    //get file size
    file.seekg(0L, std::ios::end);
    long int filesize = file.tellg();
    bytes = new uint8_t[filesize]; // create ram slice to fit boot rom
    file.seekg(0L, std::ios::beg);
    file.read((char*)bytes,filesize); // copy rom into ram slice
    file.close();
}
void ram::set_start_addr(uint16_t val)
{
    start = val;
}
void ram::set_bt_reg(uint8_t val)
{
    reg = val;
}
void ram::set_bt_enable(bool val)
{
    enabled = val;
}
void ram::set_is_boot(bool val)
{
    is_boot = val;
}
uint8_t ram::read_ram(uint16_t addr)
{
    std::cout << "RAM CONTENT: " << std::hex << bytes[addr - start] << std::endl;
    return bytes[addr - start];
}
void ram::write_to_ram(uint16_t addr, uint8_t val)
{
    bytes[addr - start] = val;
}
bool ram::ram_contains(uint16_t addr)
{
    if((addr >= start) && (addr < (start+sizeof(bytes))))
    {
        return true;
    }
    return false;
}
bool ram::boot_contains(uint16_t addr)
{
    if((addr == 0xFF50) || (enabled && ram_contains(addr)))
    {
        return true;
    }
    return false;
}
uint8_t ram::read_boot(uint16_t addr)
{
    if(addr == 0xFF50)
    {
        return reg; // boot register
    }
    return read_ram(addr);
}
void ram::write_to_boot(uint16_t addr, uint8_t val)
{
    if(addr == 0xFF50)
    {
        reg = val;
        enabled = false; // writing to boot rom is not permitted
    }
}
uint16_t ram::get_start_addr()
{
    return start;
}
uint8_t ram::get_bt_reg()
{
    return reg;
}
bool ram::bt_enabled()
{
    return enabled;
}
bool ram::is_bt()
{
    return is_boot;
}
