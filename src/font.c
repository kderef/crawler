#pragma once

#include <raylib.h>
#include <stdlib.h>

typedef enum {
    // big blue terminal
    FNT_BBT,

    FNT_MAX,
} FontID;

static const char *font_paths[FNT_MAX] = {
    [FNT_BBT] = "bbt/BigBlue_TerminalPlus.TTF",
};

static Font fonts[FNT_MAX] = {0};

bool fonts_load(const char *path) {
    const char *app_dir = GetApplicationDirectory();

    ChangeDirectory(path);

    for (FontID i = 0; i < FNT_MAX; i++) {
        fonts[i] = LoadFontEx(
            font_paths[i],
            100,
            NULL,
            0
        );
    }

    ChangeDirectory(app_dir);

    return true;
}

void fonts_unload() {
    for (FontID i = 0; i < FNT_MAX; i++) {
        UnloadFont(fonts[i]);
    }
}
