#include "memory.h"
#include "src/globals.h"

#include <stdlib.h>
#include <tomlc99/toml.h>
#include <mimalloc.h>

static void ae_defaultallocator_report(void) {
  mi_collect(true);
  mi_stats_print(NULL);
}

ae_Allocator AE_DEFAULT_ALLOCATOR = { 0 };

ae_Allocator* ae_get_defaultallocator(void) {
	return &AE_DEFAULT_ALLOCATOR;
}

void ae_defaultallocator_init(void) {
	AE_DEFAULT_ALLOCATOR.alloc = mi_malloc;
	AE_DEFAULT_ALLOCATOR.calloc = mi_calloc;
	AE_DEFAULT_ALLOCATOR.realloc = mi_realloc;
	AE_DEFAULT_ALLOCATOR.free = mi_free;
	AE_DEFAULT_ALLOCATOR.report = ae_defaultallocator_report;
	AE_DEFAULT_ALLOCATOR.strdup = mi_strdup;
	AE_DEFAULT_ALLOCATOR.strndup = mi_strndup;

	toml_set_memutil(mi_malloc, mi_free);
}

void ae_defaultallocator_deinit(void) {
	AE_DEFAULT_ALLOCATOR.alloc = NULL;
	AE_DEFAULT_ALLOCATOR.calloc = NULL;
	AE_DEFAULT_ALLOCATOR.realloc = NULL;
	AE_DEFAULT_ALLOCATOR.free = NULL;
	AE_DEFAULT_ALLOCATOR.report = NULL;
	AE_DEFAULT_ALLOCATOR.strdup = NULL;
	AE_DEFAULT_ALLOCATOR.strndup = NULL;
	
	toml_set_memutil(malloc, free);
}

