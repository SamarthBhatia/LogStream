#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "./memorySimulator.hpp"
#include "./cacheCoherency.hpp"

class Logger{
    public:
        Logger(memorySimulator& memory, cacheCoherency& cache);
        void traditionalLog(size_t address, uint8_t value);
        void efficientLog(size_t address, uint8_t value);
    
    private:
        memorySimulator& memory;
        cacheCoherency& cache;
};


#endif
