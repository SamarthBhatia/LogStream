#include "../include/cacheCoherency.hpp"
#include <mutex>
cacheCoherency::cacheCoherency() {}


cacheState cacheCoherency::getState(size_t address) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    if (cacheStateMap.find(address) == cacheStateMap.end()) {
        cacheStateMap[address] = cacheState::INVALID;
    }
    return cacheStateMap[address].load();
}

void cacheCoherency::setState(size_t address, cacheState state) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    cacheStateMap[address].store(state);
}