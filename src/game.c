#include "raylib.h"
#include "settings.c"
#include <sys/types.h>

#include "game.h"

bool game_init(Game* game, const Config* conf) {
    uint flags = config_flags(conf);

    settings_copy_config(&game->settings, conf);
    
    SetConfigFlags(flags);

    // open window
    InitWindow(conf->init_width, conf->init_height, "crawler");

    // apply default settings
    settings_load_default(&game->settings);

    SetWindowSize(game->settings.screen_w, game->settings.screen_h);

    SetExitKey(0);
    SetTargetFPS(game->settings.target_fps);
        
    InitAudioDevice();

    return true;
}

void game_close(Game* game) {
    CloseAudioDevice();
    CloseWindow();
}

void game_update(Game* game) {
    
    // update state
    game->quit ^= WindowShouldClose();
}

void game_draw(Game* game) {
    
    BeginDrawing();
    ClearBackground(BLACK);

    if (game->show_fps)
        DrawFPS(0, 0);
    
    EndDrawing();
}


