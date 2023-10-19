#include "system_manager.h"
#include "amber_engine/memory/allocator.h"
#include "amber_engine/memory/handling_strategy.h"
#include "amber_engine/runtime/system_manager.h"
#include "src/memory/memory.h"
#include "stc/ccommon.h"
#include <string.h>

#define i_key int
#include <stc/cqueue.h>
#undef i_key

#define i_key bool
#define i_type cvec_bool
#include <stc/cvec.h>
#undef i_key
#undef i_type

static void ae_executionsystem_free(ae_System *system) {
  switch (system->user_data_handling_strategy.type) {
  case AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE: {
    for (int i = 0; i < system->dependencies_count; i++) {
      ae_free((void *)(system->dependencies[i]));
    }
    ae_free((void*)(system->dependants));
    ae_free((void*)(system->dependencies));
    ae_free((void*)(system->identifier));
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
                      (void *)(system->dependants));
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

static void ae_systemmanager_create_execution_order_helper(
  ae_SystemManager* system_manager, 
  cqueue_int* stack,
  cvec_bool* visited,
  int current_idx
) {
  *cvec_bool_at_mut(visited, current_idx) = true;

  const ae_System* system = cvec_ae_System_at(&system_manager->systems, current_idx);
  for (int i = 0; i < system->dependencies_count; i++) {
    const char* dependency = system->dependencies[i];
    int dependency_idx = cmap_System_Lookup_get(&system_manager->lookup, dependency)->second;

    // visit dependencies
    if (!*cvec_bool_at(visited, dependency_idx)) {
      ae_systemmanager_create_execution_order_helper(system_manager, stack, visited, dependency_idx);
    }

    // visit dependants
    c_foreach(other_system, cvec_ae_System, system_manager->systems) {
      for (int j = 0; j < other_system.ref->dependants_count; j++) {
        const char* dependant = other_system.ref->identifier;

        if (strcmp(other_system.ref->dependants[j], system->identifier) == 0) {
          int dependant_idx = cmap_System_Lookup_get(&system_manager->lookup, dependant)->second;
          if (!*cvec_bool_at(visited, dependant_idx)) {
            ae_systemmanager_create_execution_order_helper(system_manager, stack, visited, dependant_idx);
          }
        }
      }
    }
  }

  cqueue_int_push(stack, current_idx);
}

static void ae_systemmanager_create_execution_order(ae_SystemManager *system_manager) {
  // TOPOLOGICAL Sort
  cvec_u32_clear(&system_manager->execution_order);

  int system_count = cvec_ae_System_size(&system_manager->systems);
  cqueue_int stack = cqueue_int_init();
  cvec_bool visited = cvec_bool_with_size(system_count, false);

  for (int i = 0; i < system_count; i++) {
    if (!*cvec_bool_at(&visited, i)) {
      ae_systemmanager_create_execution_order_helper(system_manager, &stack, &visited, i);
    }
  } 

  while (cqueue_int_size(&stack) > 0) {
    int idx = cqueue_int_pull(&stack);
    cvec_u32_push_back(&system_manager->execution_order, idx);
  }

  cqueue_int_drop(&stack);
  cvec_bool_drop(&visited);
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
