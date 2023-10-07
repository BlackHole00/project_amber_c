#pragma once

#include <mimalloc.h>
#define _TINYDIR_MALLOC mi_malloc
#define _TINYDIR_FREE mi_free
#include "../../tinydir/tinydir.h"
