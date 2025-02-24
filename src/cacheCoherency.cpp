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
    
    // Debug: Print state transition
    std::cout << "Cache State Updated - Address: " << address << " | New State: ";
    switch (state) {
        case cacheState::MODIFIED: std::cout << "MODIFIED\n"; break;
        case cacheState::EXCLUSIVE: std::cout << "EXCLUSIVE\n"; break;
        case cacheState::SHARED: std::cout << "SHARED\n"; break;
        case cacheState::INVALID: std::cout << "INVALID\n"; break;
    }
}



void cacheCoherency::transitionState(size_t address, cacheState newState) {
    std::lock_guard<std::mutex> lock(cacheMutex);
    cacheState currentState = getState(address);

    if (newState == cacheState::MODIFIED && currentState != cacheState::MODIFIED) {
        cacheStateMap[address].store(cacheState::MODIFIED);
    } else if (newState == cacheState::SHARED && currentState == cacheState::MODIFIED) {
        cacheStateMap[address].store(cacheState::SHARED);
    } else if (newState == cacheState::INVALID) {
        cacheStateMap[address].store(cacheState::INVALID);
    }
}

