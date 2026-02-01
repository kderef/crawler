#include <raylib.h>
#include <raygui.h>

#include "assets.h"
#include "prelude.h"
#include "game.h"

#include "draw.h"
#include "theme.h"

#include "ui.c"

void game_draw_mainmenu(Game* game) {
    ClearBackground(theme.bg0_h);
    
    const rect screen = screen_rect();
    const vec2 screen_center = {screen.width / 2.0, screen.height / 2.0};

    float base_font_size = screen.width * 0.05;

    // draw the title
    float title_font_size = base_font_size * 1.2;

    vec2 title_size = MeasureTextEx(
        fonts[FT_MAIN],
        "CRAWLER",
        title_font_size,
        1.0
    );

    pprintln(title_size);

    vec2 title_pos = {
        screen_center.x - title_size.x / 2.0,
        title_font_size
    };
    
    draw_text(
        "CRAWLER",
        title_pos,
        title_font_size,
        WHITE
    );

    // draw the controls
    ui_button( (rect) { 10, 100, 200, 50 }, "play" );
}
