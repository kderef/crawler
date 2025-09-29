#include "raylib.h"
#include "config.h"
#include "settings.c"
#include <sys/types.h>

typedef struct {
    bool quit;
    bool show_fps;
    bool paused;
} Game;

// implementations
void game_update(Game*);
void game_draw(Game*);

#include "game_draw.c"
#include "game_update.c"


bool game_init(Game* game, const Config* conf) {
    uint flags = config_flags(conf);

    settings_copy_config(conf);
    
    SetConfigFlags(flags);

    // open window
    InitWindow(conf->init_width, conf->init_height, "crawler");

    // apply default settings
    settings_load_default();

    SetExitKey(0);
    SetTargetFPS(settings.target_fps);
        
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


