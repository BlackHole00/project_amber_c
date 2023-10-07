#pragma once

#include <amber_engine/bindings/procedures.h>

typedef struct {
	aeb_get_version_proc get_version;

	aeb_get_defaultallocator get_defaultallocator;
} aeb_ProcTable;
