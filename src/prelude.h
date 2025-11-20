#pragma once

/// silence annoying warnings
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <raylib.h>

typedef unsigned int uint;

#define DEF_INT(BITS) typedef int##BITS##_t i##BITS; typedef uint##BITS##_t u##BITS

DEF_INT(8);
DEF_INT(16);
DEF_INT(32);
DEF_INT(64);

#undef DEF_INT

// raylib types
typedef struct Vector2 vec2;
typedef struct Vector3 vec3;
typedef struct Vector4 vec4;
typedef struct Rectangle rect;
#define quat Quaternion

#define vec2sub(A, B) Vector2Subtract((A), (B))

#define DEF_PRINT2(T, FMT, A, B) static inline int print_##T(T x) { \
        return printf(#T " {" FMT "}", x.A, x.B); \
    }
#define DEF_PRINT3(T, FMT, A, B, C) static inline int print_##T(T x) { \
        return printf(#T " {" FMT "}", x.A, x.B, x.C); \
    }
#define DEF_PRINT4(T, FMT, A, B, C, D) static inline int print_##T(T x) { \
        return printf(#T " {" FMT "}", x.A, x.B, x.C, x.D); \
    }
    
DEF_PRINT2(Vector2, "x = %f, y = %f", x, y)
DEF_PRINT3(Vector3, "x = %f, y = %f, z = %f", x, y, z)
DEF_PRINT4(Rectangle, "x = %f, y = %f, width = %f, height = %f", x, y, width, height)
DEF_PRINT4(Color, "r = %d, g = %d, b = %d, a = %d", r, g, b, a)
    
#define PRINT_ARG(T) T: print_##T

#define pprint(X) (_Generic((X), \
        PRINT_ARG(Color), \
        PRINT_ARG(Vector2), \
        PRINT_ARG(Vector3), \
        PRINT_ARG(Rectangle) \
    )(X))

#define pprintln(X) do { pprint(X); printf("\n"); } while (0)
