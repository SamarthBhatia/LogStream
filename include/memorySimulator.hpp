#ifndef MEMORY_SIMULATOR_HPP
#define MEMORY_SIMULATOR_HPP

#include <vector>
#include <atomic>
#include <cstddef>
#include <cstdint>


// class memorySimulator{
//     public:
//         memorySimulator(size_t nvm_size, size_t dram_size);
        
//         void writeToDRAM(size_t address, uint8_t value);
//         uint8_t readFromNVM(size_t address);
//         uint8_t readFromDRAM(size_t address);
//         void writeToNVM(size_t address, uint8_t value, bool forceFlush = false);
//         void flushNVM(size_t address);

    
//     private:
//         std::vector<uint8_t> nvm;
//         std::vector<uint8_t> dram;
// };
#ifdef __APPLE__
    #include "libpmem_stub.h"  // Ensure this file is in your include path.
#else
    #include <libpmem.h>
#endif

class memorySimulator {
public:
    // Constructor now takes the path to the persistent memory file and its size.
    memorySimulator(const char* pmemFile, size_t fileSize);
    ~memorySimulator();
    void writeToNVM(size_t address, uint8_t value, bool forceFlush = false);
    uint8_t readFromNVM(size_t address);
    
private:
    char* pmemAddr;       // Pointer to the persistent memory region.
    size_t mappedLen;     // Length of the mapped region.
    int is_pmem;          // Flag indicating if this region is true persistent memory.
};

#endif