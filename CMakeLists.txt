cmake_minimum_required(VERSION 3.10)
project(LogStream)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_library(PMEM_LIB pmem)
if(PMEM_LIB)
  message(STATUS "Found libpmem: ${PMEM_LIB}")
else()
  message(WARNING "libpmem not found, PMDK functionality will be disabled. Persistent memory functions will be simulated using a stub.")
endif()

add_executable(LogStream 
    main.cpp 
    src/cacheCoherency.cpp 
    src/logger.cpp 
    src/memorySimulator.cpp 
    src/performanceMetrics.cpp
)

target_link_libraries(LogStream pthread)
if(PMEM_LIB)
  target_link_libraries(LogStream ${PMEM_LIB})
endif()
