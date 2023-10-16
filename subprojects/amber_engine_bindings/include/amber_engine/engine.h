#pragma once

#include <amber_engine/common/functions.h>
#include "amber_engine/runtime/executor.h"
#include "bindings/bindings.h"

ae_inline const char* ae_get_version() {
	return AEB_CURRENT_PROC_TABLE->get_version();
}

ae_inline ae_Executor* ae_get_executor() {
  return AEB_CURRENT_PROC_TABLE->get_executor();
}

ae_inline void ae_executor_register_system(ae_Executor* executor, ae_ExecutionSystem system) {
  AEB_CURRENT_PROC_TABLE->executor_register_system(executor, system);
}

ae_inline void* ae_executor_get_system_data(const ae_Executor* executor, csview identifier) {
  return AEB_CURRENT_PROC_TABLE->executor_get_system_data(executor, identifier);
}

