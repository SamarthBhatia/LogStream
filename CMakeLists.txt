cmake_minimum_required(VERSION 3.10)
project(LogStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(LogStream 
    main.cpp 
    src/cacheCoherency.cpp 
    src/logger.cpp 
    src/memorySimulator.cpp 
    src/performanceMetrics.cpp
)

target_link_libraries(LogStream pthread)