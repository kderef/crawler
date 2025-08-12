#pragma once

#include "raylib.h"
#include "tileset.c"
#include "font.c"
#include "util.c"
#include <stdbool.h>

#define TRY(EXPR) if (!(EXPR)) {ok = false; goto done;}

bool assets_load(const char* path) {
    const char* app_dir = GetApplicationDirectory();
    bool ok = true;

    ChangeDirectory(path);
    
    TRY(fonts_load());
    TRY(tileset_load());

done:
    ChangeDirectory(app_dir);
    return true;
}
void assets_unload() {
    fonts_unload();
    tileset_unload();
}

void assets_test() {
    int screen_w = GetScreenWidth();
    int screen_h = GetScreenHeight();
    
    // 1. test sprites
    // DrawTexture(tileset.texture, 0, 0, WHITE);
    DrawTexturePro(
        tileset.texture,
        texture_source_rec(tileset.texture),
        rect(0, 0, screen_w, screen_h),
        vec2(0, 0),
        0.0,
        WHITE
    );

    tile_draw_rec(TILE_DEBUG, rect(50, 50, 200, 50), WHITE);
    
    // LAST: test font
    DrawTextEx(
        get_font(FNT_BBT),
        "(size 15.0) Hello from the debug screen! ABCDEFGH1234567890 (BBT)",
        vec2(100, 100),
        15.0,
        1.0,
        PURPLE
    );
}

#undef TRY
