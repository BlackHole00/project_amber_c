#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>

#include "config/config.h"
#include "bindings/proc_table.h"

int main(void) {
  ae_Config config;
  const char* config_location = ae_locate_config_file();

  if (!config_location) {
    ae_config_init_from_default(&config);
  } else {
    assert(ae_config_init_from_file(config_location, &config) == AE_PARSECONFIGERROR_SUCCESS);
  }

  printf("%s\n", config.game_target);
  
  ae_proctable_init();

  free((void*)(config_location));
  ae_config_free(&config);
  
  return 0;
}

