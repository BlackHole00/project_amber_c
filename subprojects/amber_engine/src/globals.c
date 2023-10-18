#include "globals.h"
#include "src/runtime/system_manager.h"

#include <mimalloc.h>
#include <tomlc99/toml.h>

ae_EngineGlobals AE_ENGINEGLOBALS;

void ae_init_globals(void) {
  ae_systemmanager_init(&AE_ENGINEGLOBALS.system_manager);
}

void ae_deinit_globals(void) {
  ae_systemmanager_free(&AE_ENGINEGLOBALS.system_manager);
}

