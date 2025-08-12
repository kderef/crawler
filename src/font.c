#pragma once

#include <raylib.h>
#include <stdlib.h>

typedef enum {
    // big blue terminal
    FNT_BBT,

    FNT_MAX,
} FontID;

typedef struct {
    int filter;
    char* path;
    Font data;
} FontInfo;


static FontInfo fonts[FNT_MAX] = {
    [FNT_BBT] = {TEXTURE_FILTER_POINT, "font/bbt/BigBlue_TerminalPlus.TTF"},
};

bool fonts_load(const char *path) {
    const char *app_dir = GetApplicationDirectory();

    ChangeDirectory(path);

    for (FontID i = 0; i < FNT_MAX; i++) {
        fonts[i].data = LoadFontEx(
            fonts[i].path,
            100,
            NULL,
            0
        );
        SetTextureFilter(fonts[i].data.texture, fonts[i].filter);
    }

    ChangeDirectory(app_dir);

    return true;
}

Font get_font(FontID id) {
    return fonts[id].data;
}

void fonts_unload() {
    for (FontID i = 0; i < FNT_MAX; i++) {
        UnloadFont(get_font(i));
    }
}
