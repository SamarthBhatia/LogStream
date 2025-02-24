#include <iostream>
#include "./include/logger.hpp"
#include "./include/performanceMetrics.hpp"
#include "./include/memorySimulator.hpp"

int main() {
    size_t nvmSize = 1024 * 1024;  // Define NVM size
    size_t dramSize = 1024 * 1024; // Define DRAM size
    memorySimulator memory(nvmSize, dramSize);
    cacheCoherency cache;
    Logger logger(memory, cache);
    PerformanceMetrics timer;

    size_t logCount = 1000000;  // Number of log entries

    
    timer.startTimer();
    for (size_t i = 0; i < logCount; i++) {
        size_t address = i % 1024; // Spread writes over 1024 addresses
        logger.traditionalLog(address, static_cast<uint8_t>(i % 256));
        
    }
    timer.stopTimer();
    double traditionalTime = timer.getElapsedTime();
    size_t traditionalWrites = logger.getTraditionalWrites();

   
    timer.startTimer();
    for (size_t i = 0; i < logCount; i++) {
        size_t address = i % 1024; // Spread writes across 1024 addresses
        logger.efficientLog(address, static_cast<uint8_t>(i % 256));
        
    }
    timer.stopTimer();
    double efficientTime = timer.getElapsedTime();
    size_t efficientWrites = logger.getEfficientWrites();

    // === Final Output ===
   
    std::cout << "- Elapsed Time: " << traditionalTime << " seconds\n";
    std::cout << "- Writes to NVM: " << traditionalWrites << "\n";

    std::cout << "\nEfficient Logging:\n";
    std::cout << "- Elapsed Time: " << efficientTime << " seconds\n";
    std::cout << "- Writes to NVM: " << efficientWrites << "\n";

    return 0;
}