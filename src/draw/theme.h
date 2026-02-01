#pragma once

#include "assets.h"
#include "raygui.h"
#include "raylib.h"

#define rgba(HEX) (Color) { \
    .r = (unsigned char)((HEX >> 24) & 0xFF), \
    .g = (unsigned char)((HEX >> 16) & 0xFF), \
    .b = (unsigned char)((HEX >> 8) & 0xFF), \
    .a = (unsigned char)(HEX & 0xFF), \
}

#define rgb(HEX) (Color) { \
    .r = (unsigned char)((HEX >> 16) & 0xFF), \
    .g = (unsigned char)((HEX >> 8 ) & 0xFF), \
    .b = (unsigned char)((HEX      ) & 0xFF), \
    .a = 0xFF, \
}

typedef struct {
    Color
        // bg
        bg, bg0_h, bg0_s,
        bg0, bg1, bg2, bg3, bg4,

        gray, gray_s,
        
        // colors
        red, red_s,
        green, green_s,
        yellow, yellow_s,
        blue, blue_s,
        purple, purple_s,
        aqua, aqua_s,
        orange, orange_s,
        // fg
        fg,
        fg0, fg1, fg2, fg3, fg4;
} Theme;

static const Theme gruvbox = {
    // Backgrounds
    .bg      = rgb(0x282828), // hard background
    .bg0_h   = rgb(0x1d2021), // hard contrast
    .bg0_s   = rgb(0x32302f), // soft contrast
    .bg0     = rgb(0x282828),
    .bg1     = rgb(0x3c3836),
    .bg2     = rgb(0x504945),
    .bg3     = rgb(0x665c54),
    .bg4     = rgb(0x7c6f64),

    // Grays
    .gray    = rgb(0x928374),
    .gray_s  = rgb(0xa89984),

    // Reds
    .red     = rgb(0xcc241d),
    .red_s   = rgb(0xfb4934),

    // Greens
    .green   = rgb(0x98971a),
    .green_s = rgb(0xb8bb26),

    // Yellows
    .yellow   = rgb(0xd79921),
    .yellow_s = rgb(0xfabd2f),

    // Blues
    .blue    = rgb(0x458588),
    .blue_s  = rgb(0x83a598),

    // Purples
    .purple   = rgb(0xb16286),
    .purple_s = rgb(0xd3869b),

    // Aquas
    .aqua    = rgb(0x689d6a),
    .aqua_s  = rgb(0x8ec07c),

    // Oranges
    .orange   = rgb(0xd65d0e),
    .orange_s = rgb(0xfe8019),

    // Foregrounds
    .fg   = rgb(0xebdbb2),
    .fg0  = rgb(0xfbf1c7),
    .fg1  = rgb(0xebdbb2),
    .fg2  = rgb(0xd5c4a1),
    .fg3  = rgb(0xbdae93),
    .fg4  = rgb(0xa89984),
};

static Theme theme = gruvbox;
