#ifndef CACHE_CONCURRENCY_HPP
#define CACHE_CONCURRENCY_HPP


#include <atomic>
#include <unordered_map>

enum class cacheState {MODIFIED, EXCLUSIVE, SHARED, INVALID};

class cacheCoherency{
    public:
        cacheCoherency();
        cacheState getState(size_t address);
        void setState(size_t address, cacheState state);

    private:
        std::unordered_map<size_t,std::atomic<cacheState>> cacheStateMap;
};


#endif