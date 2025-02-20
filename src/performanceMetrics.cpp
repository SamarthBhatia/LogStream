#include "../include/performanceMetrics.hpp"

void PerformanceMetrics::startTimer(){
    startTime = std::chrono::high_resolution_clock::now();
}

void PerformanceMetrics::stopTimer(){
    endTime = std::chrono::high_resolution_clock::now();
}

double PerformanceMetrics::getElapsedTime(){
    return std::chrono::duration<double>(endTime-startTime).count();
}