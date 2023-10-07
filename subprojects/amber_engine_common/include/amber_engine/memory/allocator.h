#pragma once

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

