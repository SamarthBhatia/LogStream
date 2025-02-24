#ifndef MEMORY_SIMULATOR_HPP
#define MEMORY_SIMULATOR_HPP

#include <vector>
#include <atomic>

class memorySimulator{
    public:
        memorySimulator(size_t nvm_size, size_t dram_size);
        
        void writeToDRAM(size_t address, uint8_t value);
        uint8_t readFromNVM(size_t address);
        uint8_t readFromDRAM(size_t address);
        void writeToNVM(size_t address, uint8_t value, bool forceFlush = false);
        void flushNVM(size_t address);

    
    private:
        std::vector<uint8_t> nvm;
        std::vector<uint8_t> dram;
};

#endif