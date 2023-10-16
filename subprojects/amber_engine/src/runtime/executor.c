#include "executor.h"

void ae_executor_init(ae_ExecutorImpl* executor) {
  executor->systems = cvec_ae_ExecutionSystem_init();
  executor->lookup = cmap_ExecutionSystem_Lookup_init();
}

void ae_executor_free(ae_ExecutorImpl* executor) {
  cvec_ae_ExecutionSystem_drop(&executor->systems);
  cmap_ExecutionSystem_Lookup_drop(&executor->lookup);
}

void ae_executor_register_system(ae_ExecutorImpl* executor, ae_ExecutionSystem system) {
  cvec_ae_ExecutionSystem_push_back(&executor->systems, system);
  u32 location = cvec_ae_ExecutionSystem_size(&executor->systems) - 1;

  cmap_ExecutionSystem_Lookup_insert(&executor->lookup, cstr_clone(system.identifier), location);
}

