#include "../include/logger.hpp"
#include <iostream>

Logger::Logger(memorySimulator& memory, cacheCoherency& cache)
    : memory(memory), cache(cache) {}


    void Logger::traditionalLog(size_t address, uint8_t value) {
        memory.writeToNVM(address, value, true); // Force flush for traditional logging
        traditionalWrites++;
    }
    
    void Logger::efficientLog(size_t address, uint8_t value) {
        // Use the fixed-size vector: address is in [0, 1023]
        int count = efficientCounter[address];
    
        if (count % 2 == 0) {
            cache.setState(address, cacheState::MODIFIED);
            memory.writeToNVM(address, value, true);
            efficientWrites++;
            cache.transitionState(address, cacheState::SHARED);
            // (Remove debug prints for performance)
        }
        efficientCounter[address] = count + 1;
    }
    
    