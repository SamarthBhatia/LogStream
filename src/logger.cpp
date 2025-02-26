#include "../include/logger.hpp"
#include <iostream>
#include <algorithm>

// Logger::Logger(memorySimulator& memory, cacheCoherency& cache)
//     : memory(memory), cache(cache) {}


//     void Logger::traditionalLog(size_t address, uint8_t value) {
//         memory.writeToNVM(address, value, true); // Force flush for traditional logging
//         traditionalWrites++;
//     }
    
//     void Logger::efficientLog(size_t address, uint8_t value) {
//         // Use the fixed-size vector: address is in [0, 1023]
//         int count = efficientCounter[address];
    
//         if (count % 2 == 0) {
//             cache.setState(address, cacheState::MODIFIED);
//             memory.writeToNVM(address, value, true);
//             efficientWrites++;
//             cache.transitionState(address, cacheState::SHARED);
//             // (Remove debug prints for performance)
//         }
//         efficientCounter[address] = count + 1;
//     }
    

Logger::Logger(memorySimulator& memory, cacheCoherency& cache)
    : memory(memory), cache(cache), rripCounters(1024, 0)  // initialize 1024 counters to 0
{}

void Logger::traditionalLog(size_t address, uint8_t value) {
    memory.writeToNVM(address, value, true); // Force flush for traditional logging
    traditionalWrites++;
}

void Logger::efficientLog(size_t address, uint8_t value) {
    const int MAX_RRIP = 7;  // Maximum RRIP counter value (for a 3-bit counter)
    // Get the RRIP counter for this address (address assumed to be within 0..1023)
    int& rrip = rripCounters[address];
    
    if (rrip >= MAX_RRIP) {
        // If the counter has reached the maximum, flush to NVM and reset the counter.
        cache.setState(address, cacheState::MODIFIED);
        memory.writeToNVM(address, value, true);
        efficientWrites++;
        cache.transitionState(address, cacheState::SHARED);
        rrip = 0;  // Reset counter after flushing
        
    } else {
        // Otherwise, update the memory without a forced flush and increment the counter.
        memory.writeToNVM(address, value, false);
        
        rrip = std::min(rrip + 1, MAX_RRIP);
    }
}
    