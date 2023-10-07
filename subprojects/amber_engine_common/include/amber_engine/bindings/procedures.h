#pragma once

#include <amber_engine/memory/allocator.h>

typedef const char* (*aeb_get_version_proc)(void);
typedef ae_Allocator* (*aeb_get_defaultallocator)(void);

