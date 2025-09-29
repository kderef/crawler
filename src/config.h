#pragma once

#include "raylib.h"
#include <sys/types.h>

typedef struct {
    bool resizable;
    bool hidpi;
    bool msaa_4x;
    bool vsync;
    
    int init_width;
    int init_height;
    const char* window_title;
} Config;

unsigned config_flags(const Config* conf) {
    unsigned flags = 0;

    if (conf->resizable) flags |= FLAG_WINDOW_RESIZABLE;
    if (conf->hidpi) flags |= FLAG_WINDOW_HIGHDPI;
    if (conf->msaa_4x) flags |= FLAG_MSAA_4X_HINT;
    if (conf->vsync) flags |= FLAG_VSYNC_HINT;

    return flags;
}
