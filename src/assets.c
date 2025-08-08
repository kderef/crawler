#pragma once

#include "font.c"
#include <stdbool.h>

#define TRY(EXPR) if (!(EXPR)) return false

bool assets_load(const char* path) {
    TRY(fonts_load(path));

    return true;
}
void assets_unload() {
    fonts_unload();
}

#undef TRY
