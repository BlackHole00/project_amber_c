#pragma once
#include "../memory/library_definitions.h"

#include <amber_engine/common/types.h>
#include <amber_engine/runtime/executor.h>

#define i_key ae_ExecutionSystem
#include <stc/cvec.h>
#undef i_key

#define i_key_str
#define i_val u32
#define i_type cmap_ExecutionSystem_Lookup
#include <stc/cmap.h>
#undef i_key
#undef i_val
#undef i_type

typedef struct {
  cvec_ae_ExecutionSystem systems;

  cmap_ExecutionSystem_Lookup lookup;
} ae_ExecutorImpl;

void ae_executor_init(ae_ExecutorImpl* executor);
void ae_executor_free(ae_ExecutorImpl* executor);

void ae_executor_register_system(ae_ExecutorImpl* executor, ae_ExecutionSystem system);

