#include <stdlib.h>
#include <amber_engine/bindings/bindings.h>
#include <amber_engine/common/functions.h>

aeb_ProcTable* AEB_CURRENT_PROC_TABLE = NULL;

ae_export void aeb_set_proctable(aeb_ProcTable* table) {
  AEB_CURRENT_PROC_TABLE = table;
}
