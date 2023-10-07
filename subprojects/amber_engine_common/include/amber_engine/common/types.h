#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t byte;
typedef int8_t sbyte;
typedef uint8_t ubyte;

typedef float f32;
typedef double f64;

typedef size_t usize;

#define ae_tagged_union struct 

// Used in union. Since void cannot be used since it has no size, you can use none.
typedef uint8_t ae_none;

