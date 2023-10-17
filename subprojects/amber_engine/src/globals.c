#include "globals.h"
#include "src/runtime/executor.h"

#include <mimalloc.h>
#include <tomlc99/toml.h>

ae_EngineGlobals AE_ENGINEGLOBALS;

void ae_init_globals(void) {
  ae_executor_init(&AE_ENGINEGLOBALS.executor);
}

void ae_deinit_globals(void) {
  ae_executor_free(&AE_ENGINEGLOBALS.executor);
}

