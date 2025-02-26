#include <iostream>
#include "./include/logger.hpp"
#include "./include/performanceMetrics.hpp"
#include "./include/memorySimulator.hpp"

int main() {
    const char* pmemFile = "pmem_region"; // Path to persistent file
    size_t fileSize = 1024 * 1024;         // 1MB persistent region

    memorySimulator memory(pmemFile, fileSize);
    cacheCoherency cache;
    Logger logger(memory, cache);
    PerformanceMetrics timer;

    size_t logCount = 1000000;  // Number of log entries

    // Traditional Logging
    std::cout << "Starting Traditional Logging...\n";
    timer.startTimer();
    for (size_t i = 0; i < logCount; i++) {
        size_t address = i % 1024;
        logger.traditionalLog(address, static_cast<uint8_t>(i % 256));
    }
    timer.stopTimer();
    double traditionalTime = timer.getElapsedTime();
    size_t traditionalWrites = logger.getTraditionalWrites();

    // Efficient Logging
    std::cout << "\nStarting Efficient Logging...\n";
    timer.startTimer();
    for (size_t i = 0; i < logCount; i++) {
        size_t address = i % 1024;
        logger.efficientLog(address, static_cast<uint8_t>(i % 256));
    }
    timer.stopTimer();
    double efficientTime = timer.getElapsedTime();
    size_t efficientWrites = logger.getEfficientWrites();

    // Final Output
    std::cout << "\nTraditional Logging:\n";
    std::cout << "- Elapsed Time: " << traditionalTime << " seconds\n";
    std::cout << "- Writes to NVM: " << traditionalWrites << "\n";

    std::cout << "\nEfficient Logging:\n";
    std::cout << "- Elapsed Time: " << efficientTime << " seconds\n";
    std::cout << "- Writes to NVM: " << efficientWrites << "\n";

    return 0;
}