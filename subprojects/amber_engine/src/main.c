#include "common/library_definitions.h"

#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>
#include <mimalloc.h>

#include "config/config.h"
#include "memory/memory.h"
#include "bindings/proc_table.h"

void ae_init(void) {
  ae_Config config;
  cstr config_location;
  bool config_location_ok = ae_locate_config_file(&config_location);

  if (!config_location_ok) {
    ae_config_init_from_default(&config);
  } else {
    assert(ae_config_init_from_file(cstr_sv(&config_location), &config) == AE_PARSECONFIGERROR_SUCCESS);
    cstr_drop(&config_location);
  }

  printf("%s\n", config.game_target);
}

int main(void) {
  ae_defaultallocator_init();
  ae_init();
  // ae_proctable_init();
  // ae_config_free(&config);
  ae_defaultallocator_deinit();
  
  return 0;
}

