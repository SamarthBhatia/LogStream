# **LogStream**  
**Efficient Logging in Non-Volatile Memory by Exploiting Cache Coherency Protocols**

---

## **Table of Contents**
1. [Introduction](#introduction)
2. [Features](#features)
3. [Technologies Used](#technologies-used)
4. [Installation](#installation)
5. [Usage](#usage)
6. [Performance Metrics](#performance-metrics)
7. [Contributing](#contributing)
8. [License](#license)
9. [Acknowledgements](#acknowledgements)

---

## **Introduction**
**LogStream** is a C++ project that simulates an efficient logging mechanism for **Non-Volatile Memory (NVM)** by leveraging **cache coherency protocols**. Traditional logging mechanisms in NVM systems often introduce significant overhead due to frequent writes. LogStream addresses this by exploiting cache coherency protocols (e.g., MESI) to minimize logging operations, thereby improving performance and energy efficiency.

This project is inspired by the paper **"Efficient Logging in Non-Volatile Memory by Exploiting Coherency Protocols"** and provides a practical implementation of the concepts discussed.

---

## **Features**
- **NVM and DRAM Simulation**: Simulates Non-Volatile Memory and Volatile Memory (DRAM) for persistent and temporary storage.
- **Cache Coherency Protocol**: Implements a simplified MESI (Modified, Exclusive, Shared, Invalid) protocol to manage memory consistency.
- **Efficient Logging**: Reduces logging overhead by leveraging cache coherency to track writes.
- **Multi-threaded Environment**: Demonstrates the benefits of efficient logging in a multi-core system.
- **Performance Metrics**: Compares the performance of traditional logging vs. efficient logging in terms of latency, throughput, and energy efficiency.

---

## **Technologies Used**
- **Programming Language**: C++
- **Libraries**:
  - `<thread>` for multi-threading.
  - `<atomic>` for thread-safe operations.
  - `<chrono>` for performance measurement.
  - `<vector>` for memory simulation.
- **Tools**:
  - GCC/Clang for compilation.
  - CMake for build automation (optional).

---

## **Installation**
### **Prerequisites**
- C++ compiler (GCC/Clang)
- CMake (optional, for build automation)

### **Steps**
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/LogStream.git
   cd LogStream
   ```
2. Compile the project:
   ```bash
   mkdir build && cd build && cmake .. && make && MallocNanoZone=0 
   ```
3. Run the executable:
   ```bash
   ./LogStream
   ```

---

## **Usage**
LogStream provides a simulation of efficient logging in NVM. Here's how to use it:

1. **Simulate Memory Writes**:
   - The program simulates multiple threads writing to shared memory.
   - Efficient logging is performed using the cache coherency protocol.

2. **Compare Performance**:
   - The program outputs the elapsed time for both traditional and efficient logging mechanisms.

3. **Customize Parameters**:
   - Modify `NVM_SIZE`, `DRAM_SIZE`, and `NUM_THREADS` in `main.cpp` to test different configurations.

---

## **Performance Metrics**
LogStream measures and compares the performance of traditional and efficient logging mechanisms. Key metrics include:
- **Elapsed Time**: Time taken to complete logging operations.
- **Write Count**: Number of writes to NVM.
- **Throughput**: Operations per second.

Example output:
```
Traditional Logging:
- Elapsed Time: 0.45 seconds
- Writes to NVM: 1000000

Efficient Logging:
- Elapsed Time: 0.25 seconds
- Writes to NVM: 500000
```

---

## **Contributing**
We welcome contributions to LogStream! Here's how you can help:
1. Fork the repository.
2. Create a new branch for your feature or bugfix:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add your feature or fix"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/your-feature-name
   ```
5. Open a pull request.

---

## **License**
This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

## **Acknowledgements**
- Inspired by the paper **"Efficient Logging in Non-Volatile Memory by Exploiting Coherency Protocols" by NACHSHON COHEN, MICHAL FRIEDMAN, Technion
JAMES R. LARUS, EPFL**.
- Thanks to the C++ community for providing excellent resources and libraries.

---
