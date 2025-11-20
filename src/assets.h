#pragma once

#include <raylib.h>

// directories for assets
#define ASSET_DIR "assets/"
#define TEX_DIR ASSET_DIR "sprite/"
#define FONT_DIR ASSET_DIR "fonts/"

/*************************************************/
// fonts
 
#define FONT_PATH FONT_DIR "bbt/BigBlue_TerminalPlus.TTF"


typedef enum {
    TX_NONE = 0,
    TX_GRASS,
    TX_BRICKWALL_DARK,

    TX_MAX
} TextureID;

static const char* TEXTURE_PATHS[TX_MAX] = {
    [TX_NONE] = 0,
    [TX_GRASS] = TEX_DIR "grass",
};

/// Global font
extern Font gfont;
/*************************************************/
