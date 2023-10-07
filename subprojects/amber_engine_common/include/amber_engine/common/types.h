#pragma once

#include <stdint.h>

#define u8 uint8_t
#define u16 uint16_t
#define u32 uint32_t
#define u64 uint64_t

#define i8 int8_t
#define i16 int16_t
#define i32 int32_t
#define i64 int64_t

#define uint unsigned int

#define byte uint8_t
#define sbyte int8_t
#define ubyte uint8_t

#define f32 float
#define f64 double


#define ae_tagged_union struct

// Used in union. Since void cannot be used since it has no size, you can use none.
#define ae_none uint8_t