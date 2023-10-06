#include "proc_table.h"

#include "../engine.h"

aeb_ProcTable AE_PROC_TABLE = {};

void ae_proctable_init() {
  AE_PROC_TABLE.get_version = ae_get_version;
}
