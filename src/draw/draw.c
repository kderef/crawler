#include "draw/theme.h"
#include "game.h"
#include "prelude.h"

#include "mainmenu.c"
#include "raylib.h"

void game_draw(Game* game) {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (game->scene) {
        case SCENE_MENU:
            game_draw_mainmenu(game);
            break;
    }

    if (game->show_fps)
        DrawFPS(0, 0);
    
    EndDrawing();
}

