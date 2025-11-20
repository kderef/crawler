#include <raylib.h>
#include <raygui.h>

#include "assets.h"
#include "prelude.h"
#include "game.h"

#include "draw/draw.h"
#include "draw/theme.h"

#include "scene/scene.c"

#include "draw/ui.c"

void scene_mainmenu_draw(Game* game) {
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
    )) scene_transition(game, SCENE_TEST);
}
