//! rawr.h - raylib.h wrapper

#include <raylib.h>
#include <raymath.h>
#include <stdint.h>

/* ****************** */
// internal
#define _STR(X) #X
#define STR(X) _STR(X)

/* ****************** */
// types

typedef Vector2 vec2;
typedef Vector3 vec3;
typedef Vector4 vec4;
typedef Rectangle rect;
typedef Quaternion quat;

// std types
#define DEF_INT(BITS) typedef int##BITS##_t i##BITS; typedef uint##BITS##_t u##BITS

DEF_INT(8);
DEF_INT(16);
DEF_INT(32);
DEF_INT(64);

typedef unsigned int uint;

#undef DEF_INT

/* ****************** */
// utility macros

#define VEC2ZERO vec2(0, 0)
#define VEC3ZERO vec3(0, 0, 0)
#define VEC4ZERO vec3(0, 0, 0, 0)
#define RECTZERO vec3(0, 0, 0, 0)

#define VEC2ONE vec2(1, 1)
#define VEC3ONE vec3(1, 1, 1)
#define VEC4ONE vec3(1, 1, 1, 1)
#define RECTONE vec3(1, 1, 1, 1)

#define VEC2(X, Y)       ( (Vector2){(X), (Y)} )
#define VEC3(X, Y, Z)    ( (Vector3){(X), (Y), (Z)} )
#define VEC4(X, Y, Z, W) ( (Vector4){(X), (Y), (Z), (W)} )
#define RECT(X, Y, W, H) ( (Rectangle){(X), (Y), (W), (H)} )

#define rectsize(R) vec2((R).width, (R).height)

/* ****************** */
// raymath

// return Vec2
#define vec2add Vector2Add
#define vec2addv Vector2AddValue
#define vec2sub Vector2Subtract
#define vec2subv Vector2SubtractValue
#define vec2mul Vector2Multiply
#define vec2div Vector2Divide
#define vec2neg Vector2Negate
#define vec2scale Vector2Scale
#define vec2trans Vector2Transform
#define vec2clamp Vector2Clamp
#define vec2clampv Vector2ClampValue
#define vec2lerp Vector2Lerp
#define vec2reflect Vector2Reflect
#define vec2rot Vector2Rotate
#define vec2moveto Vector2MoveTowards
#define vec2invert Vector2Invert

// return single data (float, bool)
#define vec2eq Vector2Equals
#define vec2angle Vector2Angle
#define vec2norm Vector2Normalize
#define vec2len Vector2Length
#define vec2len_sqr Vector2LengthSqr
#define vec2dist Vector2Distance
#define vec2dist_sqr Vector2DistanceSqr
#define vec2dot Vector2DotProduct

vec2 rectcenter(rect r) {
    return VEC2(
        r.x + r.width / 2,
        r.y + r.height / 2
    );
}

/* ****************** */
// main interface


