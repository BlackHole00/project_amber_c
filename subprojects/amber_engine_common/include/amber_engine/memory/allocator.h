#pragma once

#include <amber_engine/common/functions.h>
#include <amber_engine/common/types.h>

typedef void* (*ae_AllocatorAllocProc)(usize size);
typedef void* (*ae_AllocatorCallocProc)(usize n, usize size);
typedef void  (*ae_AllocatorFreeProc)(void* ptr);
typedef void* (*ae_AllocatorReallocProc)(void* ptr, usize size);
typedef void  (*ae_AllocatorDebugReportProc)(void);
typedef char* (*ae_AllocatorStrdupProc)(const char* s);
typedef char* (*ae_AllocatorStrndupProc)(const char* s, usize size);

typedef struct {
	ae_AllocatorAllocProc alloc;
	ae_AllocatorCallocProc calloc;
	ae_AllocatorFreeProc free;
	ae_AllocatorReallocProc realloc;

	ae_AllocatorStrdupProc strdup;
	ae_AllocatorStrndupProc strndup;
	
	ae_AllocatorDebugReportProc report;
} ae_Allocator;

ae_inline void* ae_allocator_alloc(ae_Allocator* allocator, usize size) {
  return allocator->alloc(size);
}

ae_inline void ae_allocator_free(ae_Allocator* allocator, void* ptr) {
	allocator->free(ptr);
}

ae_inline void* ae_allocator_realloc(ae_Allocator* allocator, void* ptr, usize size) {
	return allocator->realloc(ptr, size);
}

ae_inline char* ae_allocator_strdup(ae_Allocator* allocator, const char* s) {
	return allocator->strdup(s);
}

ae_inline char* ae_allocator_strndup(ae_Allocator* allocator, const char* s, usize size) {
	return allocator->strndup(s, size);
}

ae_inline void ae_allocator_memory_report(ae_Allocator* allocator) {
	allocator->report();
}

