#pragma once

#include <stdbool.h>
#include <stdint.h>

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
