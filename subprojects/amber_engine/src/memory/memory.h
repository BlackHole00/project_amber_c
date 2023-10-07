#pragma once
#include "library_definitions.h"

#include <amber_engine/common/types.h>
#include <amber_engine/memory/allocator.h>

extern ae_Allocator AE_CURRENT_ALLOCATOR;

void ae_defaultallocator_init(void);
void ae_defaultallocator_deinit(void);

ae_Allocator* ae_get_defaultallocator(void);

static inline void* ae_alloc(usize size) {
	return AE_CURRENT_ALLOCATOR.alloc(size);
}

static inline void ae_free(void* ptr) {
	AE_CURRENT_ALLOCATOR.free(ptr);
}

static inline void* ae_realloc(void* ptr, usize size) {
	return AE_CURRENT_ALLOCATOR.realloc(ptr, size);
}

static inline char* ae_strdup(const char* s) {
	return AE_CURRENT_ALLOCATOR.strdup(s);
}

static inline char* ae_strndup(const char* s, usize size) {
	return AE_CURRENT_ALLOCATOR.strndup(s, size);
}

static inline void ae_memory_report(void) {
	AE_CURRENT_ALLOCATOR.report();
}

