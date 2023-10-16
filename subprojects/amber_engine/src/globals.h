#pragma once
#include "memory/library_definitions.h"
#include <amber_engine/memory/allocator.h>

#include "src/runtime/executor.h"

typedef struct {
  ae_ExecutorImpl executor;
} ae_EngineGlobals;
extern ae_EngineGlobals AE_ENGINEGLOBALS;

void ae_init_globals(void);
void ae_deinit_globals(void);

