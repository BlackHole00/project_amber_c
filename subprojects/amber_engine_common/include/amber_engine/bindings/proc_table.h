#pragma once

#include <amber_engine/bindings/procedures.h>

typedef struct {
	aeb_get_version_proc          get_version;

	aeb_get_defaultallocator      get_defaultallocator;

  aeb_get_executor              get_executor;
  aeb_executor_register_system  executor_register_system;
  aeb_executor_get_system_data  executor_get_system_data;
} aeb_ProcTable;
