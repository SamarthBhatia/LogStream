#ifndef CACHE_CONCURRENCY_HPP
#define CACHE_CONCURRENCY_HPP


#include <atomic>
#include <unordered_map>
#include <mutex>

enum class cacheState {MODIFIED, EXCLUSIVE, SHARED, INVALID};

class cacheCoherency{
    public:
        cacheCoherency();
        cacheState getState(size_t address);
        void setState(size_t address, cacheState state);
        void transitionState(size_t address, cacheState newState);


    private:
        std::unordered_map<size_t,std::atomic<cacheState>> cacheStateMap;
        std::mutex cacheMutex;
};


#endif