#include "assets.h"
#include "game.h"
#include "raylib.h"

#include "raygui_style.c"

Font fonts[FT_MAX];

inline Font load_font(const char* path) {
    Font f = LoadFontEx(
        path,
        100,
        0,
        0
    );

    return f;
}

void load_fonts() {
    for (int i = 0; i < FT_MAX; i++) {
        fonts[i] = load_font(
            FONT_PATHS[i]
        );
    }

    // apply pixel filter
    SetTextureFilter(
        fonts[FT_MAIN].texture,
        TEXTURE_FILTER_POINT
    );
}

void game_load_assets(Game* game) {
    load_fonts();

    raygui_load_style(fonts[FT_MAIN]);
}

void game_unload_assets(Game* game) {
    // 1. fonts
    for (int i = 0; i < FT_MAX; i++) {
        UnloadFont(fonts[i]);
    }
}

