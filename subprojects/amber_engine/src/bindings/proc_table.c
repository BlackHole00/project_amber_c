#include "proc_table.h"

#include "../engine.h"
#include "../memory/memory.h"

void aeb_proctable_init(aeb_ProcTable* proc_table) {
  proc_table->get_version = ae_get_version;
  proc_table->get_defaultallocator = ae_get_defaultallocator;
}


