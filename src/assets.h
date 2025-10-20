#pragma once

#include <raylib.h>

// directories for assets
#define ASSET_DIR "assets/"
#define FONT_DIR ASSET_DIR "font/"

/*************************************************/
// fonts

/// index into font array of max size FONT_MAX
typedef enum {
    FT_MAIN,

    FT_MAX
} FontID;
 
/// x macro for loading fonts
#define F(NAME_, FONT_PATH_) \
    [FT_##NAME_] = ( FONT_DIR FONT_PATH_ ),

static const char* FONT_PATHS[FT_MAX] = {
    F(MAIN, "bbt/BigBlue_TerminalPlus.TTF")
};

#undef F

/*************************************************/
extern Font fonts[FT_MAX];
