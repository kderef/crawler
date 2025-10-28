#pragma once

#include "prelude.h"

typedef struct {
    enum {
        ROOM_EMPTY = 0,
    } kind;
} Room;

#define ROOMS_MAX 64

typedef struct {
    size_t width, height;
    Room rooms[ROOMS_MAX];
} Level;

Level test_level(struct Game*);
