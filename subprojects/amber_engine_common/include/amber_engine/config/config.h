#pragma once

#include <amber_engine/common/types.h>

static const char* AE_CONFIG_DEFAULT_NAME = "config.toml";
static const char* AE_CONFIG_DEFAULT_GAMETARGET = "game";

typedef enum {
	AE_CONFIGSOURCETYPE_AUTOGENERATED,
	AE_CONFIGSOURCETYPE_FROM_SOURCE,
	AE_CONFIGSOURCETYPE_FROM_FILE,
} ae_ConfigSource_Type;

typedef ae_tagged_union(ae_ConfigSourceType) {
  ae_tagged_union_case(AE_CONFIGSOURCETYPE_FROM_FILE) const char* file;

  ae_tagged_union_case(AE_CONFIGSOURCETYPE_FROM_SOURCE)
  ae_tagged_union_case(AE_CONFIGSOURCETYPE_AUTOGENERATED)
  ae_none none;
} ae_ConfigSource_Value;

typedef struct {
	ae_ConfigSource_Type type;
  ae_ConfigSource_Value value;
} ae_ConfigSource;

typedef struct {
	ae_ConfigSource source;

	const char* game_target;
} ae_Config;

