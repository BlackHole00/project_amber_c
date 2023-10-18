#include "common/library_definitions.h"

#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>
#include <mimalloc.h>

#include "config/config.h"
#include "logger.h"
#include "memory/memory.h"
#include "bindings/proc_table.h"
#include "src/common/c-logger.h"
#include "src/runtime/system_manager.h"

void ae_init(void) {
  ae_Config config;
  cstr config_location;

  LOG_TRACE("Locating config file...");
  bool config_location_ok = ae_locate_config_file(&config_location);

  if (!config_location_ok) {
    LOG_TRACE("Could not find config file. Loading default config");
    ae_config_init_from_default(&config);
  } else {
    LOG_TRACE("Initializing config from file");
    assert(ae_config_init_from_file(cstr_sv(&config_location), &config) == AE_PARSECONFIGERROR_SUCCESS);
    cstr_drop(&config_location);
  }
  LOG_TRACE("Engine config loaded");
}

int main(void) {
  ae_defaultallocator_init();
  ae_logger_init();

  LOG_INFO("Successfully initialized entry systems. Initializing engine");

  ae_init();
  // ae_proctable_init();
  // ae_config_free(&config);
  //

  ae_SystemManager sm;
  ae_systemmanager_init(&sm);

  ae_systemmanager_free(&sm);

  LOG_INFO("Exiting. Freeing last entry systems");

  ae_logger_deinit();
  ae_defaultallocator_deinit();
  
  return 0;
}

