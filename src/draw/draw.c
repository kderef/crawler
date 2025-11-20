#include "draw/theme.h"
#include "game.h"
#include "prelude.h"

#include "scene/main_menu/draw.c"
#include "scene/test/draw.c"

#include "raylib.h"

void game_draw(Game* game) {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (game->scene) {
        case SCENE_MENU:
            scene_mainmenu_draw(game);
            break;
        case SCENE_TEST:
            scene_test_draw(game);
            break;
    }

    if (game->show_fps)
        DrawFPS(0, 0);
    
    EndDrawing();
}

