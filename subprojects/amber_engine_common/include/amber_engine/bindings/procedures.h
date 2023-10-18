#pragma once

#include "amber_engine/runtime/system_manager.h"
#include <amber_engine/memory/allocator.h>
#include <amber_engine/runtime/system_manager.h>

typedef const char* (*aeb_get_version_proc)(void);
typedef ae_Allocator* (*aeb_get_defaultallocator)(void);

typedef ae_SystemManager* (*aeb_get_systemmanager)(void);
typedef void (*aeb_systemmanager_register_system)(ae_SystemManager* executor, ae_System system);
typedef const void* (*aeb_systemmanager_get_system_data)(ae_SystemManager* executor, const char* identifier);

