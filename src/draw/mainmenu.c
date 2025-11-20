#include <raylib.h>
#include <raygui.h>

#include "assets.h"
#include "prelude.h"
#include "game.h"

#include "draw.h"
#include "theme.h"

#include "ui.c"

void game_draw_mainmenu(Game* game) {
    const rect screen = screen_rect();
    const vec2 screen_center = {screen.width / 2, screen.height / 2};

    float base_font_size = screen.width * 0.05;

    // draw the title
    float title_font_size = base_font_size * 1.2;
    vec2 title_size = MeasureTextEx(
        gfont,
        "CRAWLER",
        title_font_size,
        1.0
    );

    vec2 title_pos = {
        screen_center.x - title_size.x / 2,
        title_font_size
    };
    
    draw_text(
        "CRAWLER",
        title_pos,
        title_font_size,
        WHITE
    );

    // draw the controls
    if (ui_button(
        (rect) { 10, 100, 200, 50 },
        "play"
    )) game->scene = SCENE_TEST;
}
