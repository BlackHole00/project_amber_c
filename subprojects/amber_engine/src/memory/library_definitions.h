#pragma once

#include "memory.h"

#define _TINYDIR_MALLOC ae_alloc
#define _TINYDIR_FREE ae_free

#define _AE_STC_malloc(sz) ae_alloc((usize)(sz))
#define _AE_STC_calloc(n, sz) ae_calloc(0, (usize)((n)*(sz)))
#define _AE_STC_realloc(p, sz) ae_realloc(p, (usize)(sz))
#define _AE_STC_free(p) ae_free(p)

#define i_allocator _AE_STC

