#include "game.h"
#include <raygui.h>

#include "mainmenu.c"

void game_draw(Game* game) {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (game->scene) {
        case SCENE_MAIN:
            game_draw_mainmenu(game);
            break;
    }

    if (game->show_fps)
        DrawFPS(0, 0);
    
    EndDrawing();
}
