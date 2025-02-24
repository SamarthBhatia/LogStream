#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "./memorySimulator.hpp"
#include "./cacheCoherency.hpp"
#include <unordered_map>

class Logger{
    public:
        Logger(memorySimulator& memory, cacheCoherency& cache);
        void traditionalLog(size_t address, uint8_t value);
        void efficientLog(size_t address, uint8_t value);
        size_t getTraditionalWrites() const { return traditionalWrites; }
        size_t getEfficientWrites() const { return efficientWrites; }

    
    private:
        memorySimulator& memory;
        cacheCoherency& cache;
        
        size_t traditionalWrites = 0;
        size_t efficientWrites = 0;
        std::vector<int> efficientCounter = std::vector<int>(1024, 0);

};


#endif
