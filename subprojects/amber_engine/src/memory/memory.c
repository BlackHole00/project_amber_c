#include "memory.h"

#include <stdlib.h>
#include <tomlc99/toml.h>
#include <mimalloc.h>

ae_Allocator AE_CURRENT_ALLOCATOR = {0};

static void ae_defaultallocator_report(void) {
  mi_collect(true);
  mi_stats_print(NULL);
}

void ae_defaultallocator_init(void) {
	AE_CURRENT_ALLOCATOR.alloc = mi_malloc;
	AE_CURRENT_ALLOCATOR.calloc = mi_calloc;
	AE_CURRENT_ALLOCATOR.realloc = mi_realloc;
	AE_CURRENT_ALLOCATOR.free = mi_free;
	AE_CURRENT_ALLOCATOR.report = ae_defaultallocator_report;
	AE_CURRENT_ALLOCATOR.strdup = mi_strdup;
	AE_CURRENT_ALLOCATOR.strndup = mi_strndup;

	toml_set_memutil(mi_malloc, mi_free);
}

void ae_defaultallocator_deinit(void) {
	AE_CURRENT_ALLOCATOR.alloc = NULL;
	AE_CURRENT_ALLOCATOR.calloc = NULL;
	AE_CURRENT_ALLOCATOR.realloc = NULL;
	AE_CURRENT_ALLOCATOR.free = NULL;
	AE_CURRENT_ALLOCATOR.report = NULL;
	AE_CURRENT_ALLOCATOR.strdup = NULL;
	AE_CURRENT_ALLOCATOR.strndup = NULL;
	
	toml_set_memutil(malloc, free);
}

ae_Allocator* ae_get_defaultallocator(void) {
	return &AE_CURRENT_ALLOCATOR;
}

