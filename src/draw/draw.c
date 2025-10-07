#include "game.h"

#include "mainmenu.c"

void game_draw(Game* game) {
    BeginDrawing();
    ClearBackground(BLACK);

    switch (game->state) {
        case GAME_MAIN_MENU:
            game_draw_mainmenu(game);
            break;
    }

    if (game->show_fps)
        DrawFPS(0, 0);
    
    EndDrawing();
}
