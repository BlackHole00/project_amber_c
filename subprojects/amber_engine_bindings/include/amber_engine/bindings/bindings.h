#pragma once

#include <amber_engine/bindings/proc_table.h>

extern aeb_ProcTable* AEB_CURRENT_PROC_TABLE;

void aeb_set_proctable(aeb_ProcTable* table);
