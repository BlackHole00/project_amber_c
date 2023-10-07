#include "memory/library_definitions.h"

#include <stdio.h>
#include <assert.h>

#include <tomlc99/toml.h>
#include <mimalloc.h>

#include "config/config.h"
#include "memory/memory.h"
#include "bindings/proc_table.h"

#define i_key f32
#include <stc/cvec.h>
#include <stc/ccommon.h>

int main(void) {
  ae_defaultallocator_init();
  ae_proctable_init();

  cvec_f32 vec = {0};
  cvec_f32_push(&vec, 1.0f);
  cvec_f32_push(&vec, 2.0f);
  cvec_f32_push(&vec, 3.0f);
  cvec_f32_push(&vec, 4.0f);
  
  c_foreach(i, cvec_f32, vec) {
    printf("%f\n", *i.ref);
  }
  
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

