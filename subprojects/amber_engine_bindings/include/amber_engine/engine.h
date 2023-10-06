#pragma once

#include <amber_engine/common/functions.h>
#include <amber_engine/bindings/proc_table.h>

ae_static const char* ae_get_version() {
	return AEB_CURRENT_PROC_TABLE->get_version();
}
