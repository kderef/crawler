#pragma once

#include "prelude.h"
#include <raylib.h>

#define Key KeyboardKey

/// controls
typedef struct {
    Key dbg_show_fps;

    Key fullscreen;
    
    /// movement keys
    Key move_forward, move_left, move_right, move_back;
} Keymap;

#undef Key

/// Configuration used on game startup
typedef struct {
    bool resizable;
    bool hidpi;
    bool msaa_4x;
    bool vsync;
    
    int init_width;
    int init_height;
    const char* window_title;
} Config;


/// Settings configurable by the user
typedef struct {
    u32 target_fps;
    bool vsync;
    bool msaa_4x;

    int screen_w;
    int screen_h;

    Keymap keymap;
} Settings;
