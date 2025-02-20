#include "../include/cacheCoherency.hpp"

cacheCoherency::cacheCoherency() {}

cacheState cacheCoherency::getState(size_t address){
    return cacheStateMap[address].load();
}

void cacheCoherency::setState(size_t address, cacheState state){
    cacheStateMap[address].store(state);
}