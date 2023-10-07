#pragma once
#include "../memory/library_definitions.h"

#include <tomlc99/toml.h>
#include <stdio.h>
#include <tinydir/tinydir.h>
#include <amber_engine/config/config.h>

typedef enum {
  AE_PARSECONFIGERROR_SUCCESS = 0,
  AE_PARSECONFIGERROR_COULD_NOT_PARSE = -1,
  AE_PARSECONFIGERROR_INVALID_GAME_SECTION = -2,
} ae_ParseConfig_Error;

const char* ae_locate_config_file(void);
const char* ae_locate_config_file_in_dir(tinydir_dir* search_dir);

ae_ParseConfig_Error ae_config_init_from_file(const char* file_name, ae_Config* out_config);
ae_ParseConfig_Error ae_config_init_from_toml(toml_table_t* table, ae_Config* out_config);
void ae_config_init_from_default(ae_Config* out_config);

void ae_config_free(ae_Config* config);
