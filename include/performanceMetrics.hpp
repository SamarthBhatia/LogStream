#ifndef PERFORMANCE_METRICS_HPP
#define PERFORMANCE_METRICS_HPP


#include <chrono>

class PerformanceMetrics{
    public:
        void startTimer();
        void stopTimer();
        double getElapsedTime();
    
    private:
        std::chrono::high_resolution_clock::time_point startTime, endTime;
};

#endif