#pragma once

#define _STR(X) #X
#define STR(X) _STR(X)

#define STRLEN(S) (sizeof(S) * sizeof(*(S)))

#include <stdbool.h>
#include <stdint.h>

#define vec2(X, Y) ((Vector2){.x = X, .y = Y})
#define rect(X, Y, W, H) ((Rectangle){.x = (X), .y = (Y), .width = (W), .height = (H)})
#define texture_source_rec(TEX) rect(0, 0, (TEX).width, (TEX).height)

typedef unsigned int uint;
typedef unsigned char uchar;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;
