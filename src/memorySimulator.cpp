// #include "../include/memorySimulator.hpp"
// #include <iostream>
// #include <atomic>

// memorySimulator::memorySimulator(size_t nvm_size, size_t dram_size) {
//     try {
//         nvm.resize(nvm_size, 0);
//         dram.resize(dram_size, 0);
//     } catch (const std::bad_alloc& e) {
//         std::cerr << "Memory allocation failed: " << e.what() << std::endl;
//         exit(EXIT_FAILURE);
//     }
// }

// void memorySimulator::writeToNVM(size_t address, uint8_t value, bool forceFlush) {
//     nvm[address] = value;
//     if (forceFlush) {
//         flushNVM(address);
//     }
// }



// void memorySimulator::flushNVM(size_t address) {
//     std::atomic_thread_fence(std::memory_order_release);
// }



// void memorySimulator::writeToDRAM(size_t address, uint8_t value) {
//     dram[address] = value;
// }

// uint8_t memorySimulator::readFromNVM(size_t address) {
//     if (address >= nvm.size()) {
//         std::cerr << "Error: NVM read out of bounds: " << address << std::endl;
//         return 0;
//     }
//     return nvm[address];
// }

// uint8_t memorySimulator::readFromDRAM(size_t address) {
//     if (address >= dram.size()) {
//         std::cerr << "Error: DRAM read out of bounds: " << address << std::endl;
//         return 0;
//     }
//     return dram[address];
// }

#include "../include/memorySimulator.hpp"
#include <cstdio>
#include <cstdlib>
#include <cstring>

memorySimulator::memorySimulator(const char* pmemFile, size_t fileSize) {
    // Map a persistent memory file using PMDK (or our stub on macOS)
    pmemAddr = (char*) pmem_map_file(pmemFile, fileSize, PMEM_FILE_CREATE, 0666, &mappedLen, &is_pmem);
    if (pmemAddr == nullptr) {
        perror("pmem_map_file");
        exit(1);
    }
}

memorySimulator::~memorySimulator() {
    if (pmemAddr)
        pmem_unmap(pmemAddr, mappedLen);
}

void memorySimulator::writeToNVM(size_t address, uint8_t value, bool forceFlush) {
    pmemAddr[address] = value;
    if (forceFlush) {
        pmem_persist(&pmemAddr[address], sizeof(uint8_t));
    }
}

uint8_t memorySimulator::readFromNVM(size_t address) {
    return pmemAddr[address];
}
