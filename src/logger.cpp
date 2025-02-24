#include "../include/logger.hpp"
#include <iostream>

Logger::Logger(memorySimulator& memory, cacheCoherency& cache)
    : memory(memory), cache(cache) {}



    void Logger::traditionalLog(size_t address, uint8_t value){
        memory.writeToNVM(address, value, true); 
        traditionalWrites++;
    }
    

    void Logger::efficientLog(size_t address, uint8_t value){
        cacheState currentState = cache.getState(address);
    
        // If the cache state is INVALID, move it to MODIFIED
        if (currentState == cacheState::INVALID) {
            cache.setState(address, cacheState::MODIFIED);
        }
    
        // Debugging: Print updated cache state
        currentState = cache.getState(address);
        std::cout << "Efficient Log - Address: " << address << " | New State: ";
        switch (currentState) {
            case cacheState::MODIFIED: std::cout << "MODIFIED\n"; break;
            case cacheState::EXCLUSIVE: std::cout << "EXCLUSIVE\n"; break;
            case cacheState::SHARED: std::cout << "SHARED\n"; break;
            case cacheState::INVALID: std::cout << "INVALID\n"; break;
        }
    
        // Now, if the address is in MODIFIED state, write to NVM
        if (currentState == cacheState::MODIFIED) {
            memory.writeToNVM(address, value, true);
            efficientWrites++;
            cache.transitionState(address, cacheState::SHARED); // Move to SHARED
        }
    }
    