#pragma once
#include "../common/library_definitions.h"
#include "amber_engine/bindings/procedures.h"

#include <amber_engine/common/types.h>
#include <amber_engine/runtime/system_manager.h>

#include <stc/cstr.h>

#define i_key ae_System
#include <stc/cvec.h>
#undef i_key

#define i_key u32
#define i_use_cmp
#include <stc/cvec.h>
#undef i_key

#define i_key_str
#define i_val u32
#define i_type cmap_System_Lookup
#include <stc/cmap.h>
#undef i_key
#undef i_val
#undef i_type

struct ae_SystemManager {
  cvec_ae_System systems;

  cmap_System_Lookup lookup;
  cvec_u32 execution_order;
};

void ae_systemmanager_init(ae_SystemManager* system_manager);
void ae_systemmanager_free(ae_SystemManager* system_manager);

void ae_systemmanager_register_system(ae_SystemManager* system_manager, ae_System system);

void ae_systemmanager_get_current_phase(ae_SystemManager* system_manager);
void ae_systemmanager_prepare_for_execution(ae_SystemManager* system_manager);
void ae_systemmanager_tick_current_phase(ae_SystemManager* system_manager);
void ae_systemmanager_run(ae_SystemManager* system_manager);

