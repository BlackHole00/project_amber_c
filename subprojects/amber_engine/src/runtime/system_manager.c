#include "system_manager.h"
#include "amber_engine/memory/allocator.h"
#include "amber_engine/memory/handling_strategy.h"
#include "src/memory/memory.h"
#include "stc/ccommon.h"

#define i_key_str
#include <stc/cset.h>
#undef i_key_str

static void ae_executionsystem_free(ae_System *system) {
  switch (system->user_data_handling_strategy.type) {
  case AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE: {
    for (int i = 0; i < system->dependencies_count; i++) {
      ae_free((void *)(system->dependencies[i]));
    }
    ae_free((void *)(system->dependencies));
    ae_free((void *)(system->identifier));
    ae_free(system->system_data);

    break;
  }
  case AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE_ALLOCATOR: {
    assert(system->user_data_handling_strategy.value.move_allocator != NULL);

    for (int i = 0; i < system->dependencies_count; i++) {
      ae_allocator_free(
          system->user_data_handling_strategy.value.move_allocator,
          (void *)(system->dependencies[i]));
    }
    ae_allocator_free(system->user_data_handling_strategy.value.move_allocator,
                      (void *)(system->dependencies));
    ae_allocator_free(system->user_data_handling_strategy.value.move_allocator,
                      (void *)(system->identifier));
    ae_allocator_free(system->user_data_handling_strategy.value.move_allocator,
                      system->system_data);

    break;
  }
  case AE_MEMORYHANDLINGSTRATEGYTYPE_KEEP: {
    break;
  }
  }
}

static void
ae_systemmanager_create_execution_order(ae_SystemManager *system_manager) {
  // cset_str inserted_systems = cset_str_init();
  //
  //  cvec_u32_clear(&systemmanager->execution_order);

  // for(int i = 0; i < cvec_ae_ExecutionSystem_size(&systemmanager->systems);
  // i++) { ae_ExecutionSystem* system =
  // cvec_ae_ExecutionSystem_at_mut(&systemmanager->systems, i);
  //
  // if (
  // cvec_str_size(&system->dependencies) <= 0 ||
  // !cset_str_contains(&inserted_systems, cstr_str(&system->identifier))
  // ) {
  //     cvec_u32_push_back(&systemmanager->execution_order, i);
  //     continue;
  //   }
  //
  //   c_foreach(dependency, cvec_str, system->dependencies) {
  //     const u32* dependency_index =
  //     cmap_ExecutionSystem_Lookup_at(&systemmanager->lookup,
  //     cstr_str(dependency.ref));
  //
  //     cvec_u32_iter result = cvec_u32_find(&systemmanager->execution_order,
  //     *dependency_index); assert(result.ref != NULL);
  //
  //     cvec_u32_insert_at(&systemmanager->execution_order, result, i);
  //   }
  // }
  //
  // cset_str_drop(&inserted_systems);
}

void ae_systemmanager_init(ae_SystemManager *system_manager) {
  system_manager->systems = cvec_ae_System_init();
  system_manager->lookup = cmap_System_Lookup_init();
  system_manager->execution_order = cvec_u32_init();
}

void ae_systemmanager_free(ae_SystemManager *system_manager) {
  c_foreach(system, cvec_ae_System, system_manager->systems) {
    ae_executionsystem_free(system.ref);
  }

  cvec_ae_System_drop(&system_manager->systems);
  cmap_System_Lookup_drop(&system_manager->lookup);
  cvec_u32_drop(&system_manager->execution_order);
}

void ae_systemmanager_register_system(ae_SystemManager *system_manager,
                                      ae_System system) {
  cvec_ae_System_push_back(&system_manager->systems, system);
  u32 location = cvec_ae_System_size(&system_manager->systems) - 1;

  cmap_System_Lookup_insert(&system_manager->lookup,
                            cstr_from(system.identifier), location);
}

void ae_systemmanager_prepare_for_execution(ae_SystemManager *system_manager) {
  ae_systemmanager_create_execution_order(system_manager);
}
