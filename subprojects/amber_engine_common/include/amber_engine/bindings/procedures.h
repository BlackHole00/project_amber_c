#pragma once

#include <stc/cstr.h>
#include <amber_engine/memory/allocator.h>
#include <amber_engine/runtime/executor.h>

typedef const char* (*aeb_get_version_proc)(void);
typedef ae_Allocator* (*aeb_get_defaultallocator)(void);

typedef ae_Executor* (*aeb_get_executor)(void);
typedef void (*aeb_executor_register_system)(ae_Executor* executor, ae_ExecutionSystem system);
typedef const void* (*aeb_executor_get_system_data)(ae_Executor* executor, csview identifier);

