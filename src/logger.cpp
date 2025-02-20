#include "../include/logger.hpp"

Logger::Logger(memorySimulator& memory, cacheCoherency& cache)
    : memory(memory), cache(cache) {}

void Logger::traditionalLog(size_t address, uint8_t value){
    memory.writeToNVM(address,value);
}

void Logger::efficientLog(size_t address, uint8_t value){
    if (cache.getState(address) == cacheState::MODIFIED){
        memory.writeToNVM(address,value);
    }
}