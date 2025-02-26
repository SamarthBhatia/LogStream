#ifndef LIBPMEM_STUB_H
#define LIBPMEM_STUB_H

#include <stdlib.h>
#include <stddef.h>

#ifndef PMEM_FILE_CREATE
#define PMEM_FILE_CREATE 1
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Simulate mapping a persistent memory file by allocating memory.
static inline void* pmem_map_file(const char* path, size_t len, int mode, int flags, size_t* mapped_len, int* is_pmem) {
    *mapped_len = len;
    *is_pmem = 0; // Indicate that this is not real persistent memory.
    return malloc(len);
}

// Simulate unmapping the persistent memory region.
static inline int pmem_unmap(void* addr, size_t len) {
    free(addr);
    return 0;
}

// Simulate persisting data (no-op on macOS).
static inline void pmem_persist(const void* addr, size_t len) {
    // No-op: data is not truly persistent.
}

#ifdef __cplusplus
}
#endif

#endif // LIBPMEM_STUB_H
