#include "../include/memorySimulator.hpp"
#include <iostream>
memorySimulator::memorySimulator(size_t nvm_size, size_t dram_size) {
    try {
        nvm.resize(nvm_size, 0);
        dram.resize(dram_size, 0);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}


void memorySimulator::writeToNVM(size_t address, uint8_t value) {
        if (address >= nvm.size()) {
            std::cerr << "Error: NVM write out of bounds: " << address << std::endl;
            return;
        }
        nvm[address] = value;
    }
    


void memorySimulator::writeToDRAM(size_t address, uint8_t value) {
    dram[address] = value;
}

uint8_t memorySimulator::readFromNVM(size_t address) {
    if (address >= nvm.size()) {
        std::cerr << "Error: NVM read out of bounds: " << address << std::endl;
        return 0;
    }
    return nvm[address];
}

uint8_t memorySimulator::readFromDRAM(size_t address) {
    if (address >= dram.size()) {
        std::cerr << "Error: DRAM read out of bounds: " << address << std::endl;
        return 0;
    }
    return dram[address];
}
