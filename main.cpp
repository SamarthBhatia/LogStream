#include <iostream>
#include <thread>
#include <vector>
#include "./include/memorySimulator.hpp"
#include "./include/cacheCoherency.hpp"
#include "./include/logger.hpp"
#include "./include/performanceMetrics.hpp"

void simulateWorkload(Logger& logger, size_t startAddress, size_t endAddress) {
    for (size_t i = startAddress; i < endAddress; i++) {
        logger.efficientLog(i, i % 256); // Simulate efficient logging
    }
}

int main() {
    const size_t NVM_SIZE = 256 * 1024; // 256 KB NVM
    const size_t DRAM_SIZE = 256 * 1024; // 256 KB DRAM

    const size_t NUM_THREADS = 4;
    const size_t WORKLOAD_SIZE = NVM_SIZE / NUM_THREADS;

    memorySimulator memory(NVM_SIZE, DRAM_SIZE);
    cacheCoherency cache;
    Logger logger(memory, cache);
    PerformanceMetrics metrics;

    std::vector<std::thread> threads;

    metrics.startTimer();
    for (size_t i = 0; i < NUM_THREADS; i++) {
        threads.emplace_back(simulateWorkload, std::ref(logger), i * WORKLOAD_SIZE, (i + 1) * WORKLOAD_SIZE);
    }
    for (auto& thread : threads) {
        thread.join();
    }
    metrics.stopTimer();

    std::cout << "Elapsed Time: " << metrics.getElapsedTime() << " seconds" << std::endl;
    return 0;
}