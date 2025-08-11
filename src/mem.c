#pragma once

#include <stdlib.h>
#include "raylib.h"
#include "log.c"

#ifdef MEM_DEBUG

void* mem_alloc(size_t size) {
    INFO("allocating memory of size %d", size);
    return malloc(size);
}

#define mem_free(PTR) do { \
        if (PTR) { \
            INFO("Freeing memory at %p"); free(PTR); \
        } else ERROR("Tried to free NULL memory"); \
    } while (0)

#else

#define mem_alloc malloc
#define mem_free free

#endif
