#include "../include/memorySimulator.hpp"

memorySimulator::memorySimulator(size_t nvm_size, size_t dram_size)
    : nvm(nvm_size,0), dram(dram_size,0){}

void memorySimulator::writeToNVM(size_t address, uint8_t value){
    nvm[address]=value;
}

void memorySimulator::writeToDRAM(size_t address, uint8_t value) {
    dram[address] = value;
}

uint8_t memorySimulator::readFromNVM(size_t address) {
    return nvm[address];
}

uint8_t memorySimulator::readFromDRAM(size_t address) {
    return dram[address];
}