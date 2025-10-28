#pragma once

#include <stdio.h>

#include "assets.h"
#include "draw/theme.h"
#include "prelude.h"
#include "draw.h"
#include "raylib.h"

bool ui_button(rect bounds, const char* text) {
    const vec2 mouse_pos = GetMousePosition();
    const rect screen = screen_rect();
    const bool hovering = CheckCollisionPointRec(mouse_pos, bounds);

    const Color bg = hovering? theme.bg3 : theme.bg0;
    const Color fg = hovering? theme.fg0 : theme.fg;
    const Color border = hovering? theme.gray_s : theme.gray;

    // draw the background, outline
    DrawRectangleRec(bounds, bg);
    DrawRectangleLinesEx(bounds, 3.0, border);

    const float font_size = bounds.width * 0.1;

    const vec2 text_size = MeasureTextEx(
        gfont,
        text,
        font_size,
        1
    );

    const vec2 bounds_center = {
        bounds.x + bounds.width / 2,
        bounds.y + bounds.height / 2
    };

    const vec2 text_pos = {
        bounds_center.x - text_size.x / 2,
        bounds_center.y - text_size.y / 2
    };

    draw_text(
        text,
        text_pos,
        font_size,
        fg
    );

    // check if it was clicked
    if (!hovering) return false;

    // clicked
    const bool mouse_clicked = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);

    return mouse_clicked;
}
