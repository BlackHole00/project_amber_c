#pragma once

#include "allocator.h"
#include "../common/types.h"

typedef enum {
  AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE,
  AE_MEMORYHANDLINGSTRATEGYTYPE_KEEP,
  AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE_ALLOCATOR,
} ae_MemoryHandlingStrategy_Type;

typedef ae_tagged_union(ae_MemoryHandlingStrategy_Type) {
  ae_tagged_union_case(AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE)
  ae_tagged_union_case(AE_MEMORYHANDLINGSTRATEGYTYPE_KEEP) ae_none none;

  ae_tagged_union_case(AE_MEMORYHANDLINGSTRATEGYTYPE_MOVE_ALLOCATOR) ae_Allocator* move_allocator;
} ae_MemoryHandlingStrategy_Value;

typedef struct {
  ae_MemoryHandlingStrategy_Type type;
  ae_MemoryHandlingStrategy_Value value;
} ae_MemoryHandlingStrategy;

