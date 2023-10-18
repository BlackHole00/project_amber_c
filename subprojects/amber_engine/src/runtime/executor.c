#include "executor.h"
#include "amber_engine/runtime/executor.h"
#include "stc/ccommon.h"

#define i_key_str
#include <stc/cset.h>
#undef i_key_str

static void ae_executor_create_execution_order(ae_ExecutorImpl* executor) {
  cset_str inserted_systems = cset_str_init();

  cvec_u32_clear(&executor->execution_order);

  for(int i = 0; i < cvec_ae_ExecutionSystem_size(&executor->systems); i++) {
    ae_ExecutionSystem* system = cvec_ae_ExecutionSystem_at_mut(&executor->systems, i);

    if (
      cvec_str_size(&system->dependencies) <= 0 ||
      !cset_str_contains(&inserted_systems, cstr_str(&system->identifier))
    ) {
      cvec_u32_push_back(&executor->execution_order, i);
      continue;
    }

    c_foreach(dependency, cvec_str, system->dependencies) {
      const u32* dependency_index = cmap_ExecutionSystem_Lookup_at(&executor->lookup, cstr_str(dependency.ref));

      cvec_u32_iter result = cvec_u32_find(&executor->execution_order, *dependency_index);
      assert(result.ref != NULL);

      cvec_u32_insert_at(&executor->execution_order, result, i);
    }
  }

  cset_str_drop(&inserted_systems);
}

void ae_executor_init(ae_ExecutorImpl* executor) {
  executor->systems = cvec_ae_ExecutionSystem_init();
  executor->lookup = cmap_ExecutionSystem_Lookup_init();
  executor->execution_order = cvec_u32_init();
}

void ae_executor_free(ae_ExecutorImpl* executor) {
  c_foreach(system, cvec_ae_ExecutionSystem, executor->systems) {
    cstr_drop(&system.ref->identifier);
    cvec_str_drop(&system.ref->dependencies);
  }

  cvec_ae_ExecutionSystem_drop(&executor->systems);
  cmap_ExecutionSystem_Lookup_drop(&executor->lookup);
  cvec_u32_drop(&executor->execution_order);
}

void ae_executor_register_system(ae_ExecutorImpl* executor, ae_ExecutionSystem system) {
  cvec_ae_ExecutionSystem_push_back(&executor->systems, system);
  u32 location = cvec_ae_ExecutionSystem_size(&executor->systems) - 1;

  cmap_ExecutionSystem_Lookup_insert(&executor->lookup, cstr_clone(system.identifier), location);
}

void ae_executor_prepare_for_execution(ae_ExecutorImpl* executor) {
  ae_executor_create_execution_order(executor);
}

