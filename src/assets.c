#include "assets.h"
#include "game.h"
#include "raylib.h"

#include "raygui_style.c"

Font gfont;

void load_fonts() {
    gfont = LoadFontEx(
        FONT_PATH,
        12,
        0,
        0
    );
    
    // apply pixel filter
    SetTextureFilter(
        gfont.texture,
        TEXTURE_FILTER_POINT
    );
}

void game_load_assets(Game* game) {
    load_fonts();

    raygui_load_style(gfont);
}

void game_unload_assets(Game* game) {
    UnloadFont(gfont);
}

