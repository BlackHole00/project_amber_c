#pragma once
#include "common/library_definitions.h"
#include <amber_engine/memory/allocator.h>

#include "src/runtime/system_manager.h"

typedef struct {
  ae_SystemManager system_manager;
} ae_EngineGlobals;
extern ae_EngineGlobals AE_ENGINEGLOBALS;

void ae_init_globals(void);
void ae_deinit_globals(void);

