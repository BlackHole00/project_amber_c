#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>
#include <mimalloc.h>

#include "config/config.h"
#include "memory/memory.h"
#include "bindings/proc_table.h"

int main(void) {
  ae_defaultallocator_init();
  ae_proctable_init();
  
  ae_Config config;
  const char* config_location = ae_locate_config_file();

  if (!config_location) {
    ae_config_init_from_default(&config);
  } else {
    assert(ae_config_init_from_file(config_location, &config) == AE_PARSECONFIGERROR_SUCCESS);
  }

  printf("%s\n", config.game_target);
  
  ae_free((void*)(config_location));
  ae_config_free(&config);

  ae_free(ae_alloc(6553600));

  ae_memory_report();
  ae_defaultallocator_deinit();
  
  return 0;
}

