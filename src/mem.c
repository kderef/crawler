#pragma once

#include <stdlib.h>
#include "raylib.h"
#include "log.c"

#ifdef MEM_DEBUG

void* mem_alloc(size_t size) {
    INFO("allocating memory of size %d", size);
    return malloc(size);
}

void mem_free(void* mem) {
    if (mem) {
        INFO("Freeing memory at %p", mem);
        free(mem);
    }
    else ERROR("tried to free NULL memory");
}

#else

#define mem_alloc malloc
#define mem_free free

#endif
