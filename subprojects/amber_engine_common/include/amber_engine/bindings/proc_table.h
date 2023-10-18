#pragma once

#include <amber_engine/bindings/procedures.h>

typedef struct {
	aeb_get_version_proc          get_version;

	aeb_get_defaultallocator      get_defaultallocator;

  aeb_get_systemmanager         get_systemmanager;
  aeb_systemmanager_register_system  systemmanager_register_system;
  aeb_systemmanager_get_system_data  systemmanager_get_system_data;
} aeb_ProcTable;
