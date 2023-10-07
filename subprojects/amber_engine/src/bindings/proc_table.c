#include "proc_table.h"

#include "../engine.h"
#include "../memory/memory.h"

aeb_ProcTable AE_PROC_TABLE = { 0 };

void ae_proctable_init(void) {
  AE_PROC_TABLE.get_version = ae_get_version;
  AE_PROC_TABLE.get_defaultallocator = ae_get_defaultallocator;
}


