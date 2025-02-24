#include "../include/cacheCoherency.hpp"
#include <mutex>
#include <iostream>

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
    cacheStateMap[address] = state;
    
   
    switch (state) {
        case cacheState::MODIFIED: break;
        case cacheState::EXCLUSIVE:  break;
        case cacheState::SHARED:  break;
        case cacheState::INVALID:  break;
    }
}



void cacheCoherency::transitionState(size_t address, cacheState newState) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    
    if (cacheStateMap.find(address) == cacheStateMap.end()) {
        cacheStateMap[address] = cacheState::INVALID;
    }
    cacheState currentState = cacheStateMap[address].load();
    
    
    if (currentState == newState) {
        return;
    }

    cacheStateMap[address].store(newState);
   
}




