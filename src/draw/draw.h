#pragma once

#include "prelude.h"
#include "assets.h"
#include "raylib.h"

inline void draw_text(const char* text, vec2 pos, float size, Color color) {
    DrawTextEx(
        fonts[FT_MAIN],
        text,
        pos,
        size,
        1.0,
        color
    );
}

inline rect screen_rect() {
    return (rect) {
        .x = 0,
        .y = 0,
        .width = (float)GetRenderWidth(),
        .height = (float)GetRenderHeight(),
    };
}

inline vec2 get_screen_size() {
    return (vec2) {
        (float)GetRenderWidth(),
        (float)GetRenderHeight()
    };
}
